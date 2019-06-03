/*
 * Room.cpp
 *
 *  Created on: 26 May 2019
 *      Author: nikolay
 */

#include "Room.h"
#include <typeinfo>
#include "Painting.h"
#include "Statue.h"
#include "Standing.h"
#include "WallArt.h"
#include "BadDataException.h"

Room::Room(float area, unsigned int maxExhibits): storage(0) {
	this->farea = area / 4;
	this->warea = area / 3;
	this->max = maxExhibits;
}

Room::~Room() {
	for (std::vector<Exhibit*>::iterator it = storage.begin() ; it != storage.end() ; ++it) {
		delete *it;
	}
}

bool Room::hasSpace(const Exhibit & e) {
	if ( storage.size() == this->max )
		return false;
	bool wcheck = false, fcheck = false;
	if ( typeid(e) == typeid(Painting) )
		wcheck = true;
	if ( typeid(e) == typeid(Statue) || typeid(e) == typeid(Standing) )
		fcheck = true;
	if ( wcheck && e.wallArea() > warea )
		return false;
	if ( fcheck && e.floorArea() > farea )
		return false;
	return true;
}

bool Room::addExhibit(Exhibit * e) {
	if ( nullptr == e )
		return false;
	if ( !hasSpace(*e) ) {
		delete e;
		return false;
	}
	if ( typeid(*e) == typeid(Painting) )
		warea -= e->wallArea();
	if ( typeid(*e) == typeid(Statue) || typeid(*e) == typeid(Standing) )
		farea -= e->floorArea();
	storage.push_back(e);
	return true;
}

bool Room::removeExhibit(r_flag rf, std::string str, int y) {
	switch(rf) {
	case n:
		removeByName(str);
		break;
	case c:
		removeByCreator(str);
		break;
	case by:
		removeBeforeYear(y);
		break;
	case ay:
		removeAfterYear(y);
		break;
	case last:
		removeLast();
		break;
	default:
		throw BadDataException("Wrong removal flag.");
	}
	return true;
}

/*
 * Removes the exhibit/s going by the given name.
 *
 * @param str 		The name of the exhibit/s to be removed.
 * @param return 	True if there was one to remove, false otherwise.
 */
bool Room::removeByName(std::string str) {
	int size = storage.size();
	for ( int i = 0 ; i < size ; ++i ) {
		Exhibit * e = storage[i];
		if ( e->name() == str ) {
			remove(i);
			--i;
			--size;
		}
	}
	return true;
}

/*
 * Removes the exhibit/s created by the named creator.
 *
 * @param str 		The name of the creator of the exhibit/s to be removed.
 * @param return 	True if there was at least one to remove, false otherwise.
 */
bool Room::removeByCreator(std::string str) {
	int size = storage.size();
	for ( int i = 0 ; i < size ; ++i ) {
		Exhibit * e = storage[i];
		if ( e->crtrName() == str ) {
			remove(i);
			--i;
			--size;
		}
	}
	return true;
}

/*
 * Removes all exhibits created before and during the given year.
 *
 * @param year 		The year in question.
 * @param return 	True if there was at least one to remove, false otherwise.
 */
bool Room::removeBeforeYear(int year) {
	int size = storage.size();
	for ( int i = 0 ; i < size ; ++i ) {
		Exhibit * e = storage[i];
		if ( e->yearMade() <= year ) {
			remove(i);
			--i;
			--size;
		}
	}
	return true;
}

/*
 * Removes all exhibits created after and during the given year.
 *
 * @param year 		The year in question.
 * @param return 	True if there was at least one to remove, false otherwise.
 */
bool Room::removeAfterYear(int year) {
	int size = storage.size();
	for ( int i = 0 ; i < size ; ++i ) {
		Exhibit * e = storage[i];
		if ( e->yearMade() >= year ) {
			remove(i);
			--i;
			--size;
		}
	}
	return true;
}

/*
 * Removes the last exhibit in the room.
 *
 * @return 			False if the room was empty.
 */
bool Room::removeLast() {
	if ( 0 == storage.size() )
		return false;
	remove(storage.size() - 1);
	return true;
}

void Room::remove(unsigned int index) {
	if ( index >= storage.size() )
		return;
	// Wamoo!
	Exhibit * e = storage[index];
	farea += e->floorArea();
	warea += e->wallArea();
	delete e;
	storage.erase(storage.begin() + index);
}

std::ostream & operator<<(std::ostream & os, const Room & rm) {
	int size = rm.storage.size();
	os << ":Exhibits in room:" << std::endl;
	for ( int i = 0 ; i < size ; ++i ) {
		Exhibit * e = rm.storage[i];
		os << e->Serialize() << std::endl;
	}
	return os;
}
