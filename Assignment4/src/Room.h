/*
 * Room.h
 *
 *  Created on: 26 May 2019
 *      Author: nikolay
 */

#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "Exhibit.h"
#include <vector>
#include <iostream>

typedef enum { n, c, by, ay, last } r_flag;

class Room {
	std::vector<Exhibit*> storage;
	float farea, warea;
	unsigned int max;
	/*
	 * Removes the exhibit at the given index.
	 *
	 * @param index 		The index at which to remove.
	 */
	void remove(unsigned int);
	bool removeByName(std::string);
	bool removeByCreator(std::string);
	bool removeBeforeYear(int);
	bool removeAfterYear(int);
	bool removeLast();
public:
	/*
	 * A room in the museum.
	 *
	 * @param area 			The area of the room, in square meters.
	 * @param maxExhibits 	The maximum number of exhibits to be displayed.
	 */
	Room(float = 0,unsigned int = 0);
	virtual ~Room();
	/*
	 * Checks if the room has enough space for the exhibit.
	 *
	 * @param exh			The exhibit asking for asylum.
	 * @return 				true or false.
	 */
	bool hasSpace(const Exhibit &);
	/*
	 * Adds an exhibit to the room.
	 *
	 * @param exh 			A pointer to the exhibit to be added.
	 * @return 				True if the exhibit was added, false if there was
	 * 						no space for it.
	 */
	bool addExhibit(Exhibit *);
	/*
	 * Removes a exhibit/several exhibits from the room
	 * according to a user-defined clause.
	 *
	 * @param flag 			The flag to use for removal.
	 * 						n - name of exhibit
	 * 						c - name of creator (all exhibits)
	 * 						by - before a given year (all matching exhibits)
	 * 						ay - after a given year (all matching exhibits)
	 * @param str 			The string with the name of the exhibit or the
	 * 						creator. Defaults to nothing.
	 * @param year 			The year for the latter two flags.
	 * @return 				Success of removal - if no exhibits were removed,
	 * 						returns false.
	 */
	bool removeExhibit(r_flag,std::string = 0,int=0);
	/*
	 * Writes the exhibits in the room into an output stream.
	 *
	 * @param os 			The stream to save in.
	 * @return 				A reference to the file.
	 */
	friend std::ostream & operator<<(std::ostream &, const Room &);
};

#endif /* SRC_ROOM_H_ */
