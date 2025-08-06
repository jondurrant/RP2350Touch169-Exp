/*
 * State.h
 *
 * State superclass to hold the state of a Twin Thing object.
 *
 *  Created on: 19 Sept 2021
 *      Author: jondurrant
 */

#ifndef STATE_H_
#define STATE_H_

#ifndef STATE_ELEMENTS
#define STATE_ELEMENTS 16
#endif

#include <stdbool.h>
#include <list>

#include "tiny-json.h"
#include "StateObserver.h"

//Declaration for State function that will be used as array of member functions in class
class State;
typedef  char* (State::*StateFunc)(char *buf, unsigned int len);

/***
 * Abstract state function to manage twin communication from PICO to a host device
 * Note class is limited to max of 8 state items!
 */
class State {
public:


	/***
	 * Set transaction number. Used by twin client on a host to confirm updates
	 * have been processed by pico
	 * @param newTRN
	 */
	virtual void setTransaction(unsigned int newTRN);

	/***
	 * get transaction code. Used by twin client on a host to confirm updates
	 * have been processed by pico
	 * @return trn
	 */
	virtual unsigned int getTransaction();

	/***
	 * Retrieve delta of changes to state in JSON format
	 * @param buf - buffer to write to
	 * @param len - length of buffer
	 * @return length of json or zero if we ran out of space
	 */
	virtual unsigned int delta(char *buf, unsigned int len) ;

	/***
	 * Retrieve delta of changes to state in JSON format
	 * @param buf - buffer to write to
	 * @param len - length of buffer
	 * @param dirtyCode - dirtyCode which shows which elements changed.
	 * @return
	 */
	virtual unsigned int delta(char *buf, unsigned int len, uint16_t dirtyCode) ;

	/***
	 * Retrieve state of object in JSON format
	 * @param buf - buffer to write to
	 * @param len - length of buffer
	 * @return length of json or zero if we ran out of space
	 */
	virtual unsigned int state(char *buf, unsigned int len) ;

	/***
	 * Update state data from a json structure
	 * @param json
	 */
	virtual void updateFromJson(json_t const *json);

	/***
	 * Start a transaction and supress notifications of change until transaction is complete
	 */
	virtual void startTransaction();

	/***
	 * End transaction and notify all observers
	 */
	virtual void commitTransaction();

	/***
	 * Set state to clean for delta
	 */
	virtual void setClean();

	/***
	 * Check if delta is currently available. Should be false except in transation
	 * @return bool
	 */
	virtual bool isDirty() const;

	/***
	 * Attach an observer
	 * @param observer
	 */
	void attach(StateObserver *observer);
	/***
	 * Detach observer
	 * @param observer
	 */
	void detach(StateObserver *observer);


protected:
	/***
	 * Protect constructor as virtual
	 */
	State();
	/***
	 * Destructor
	 */
	virtual ~State();
	/***
	 * Copy constructor
	 * @param other
	 */
	State(const State &other);

	// List of the 16 helpder functions that will serialise the 16 elements to JSON
	StateFunc jsonHelpers[STATE_ELEMENTS];
	// Actual number of elements, must be bellow 16
	uint16_t elements = STATE_ELEMENTS;

	/***
	 * Set specific element (0 to 15) to be dirty
	 * @param element
	 */
	void setDirty(uint16_t element);

	/***
	 * Notify all observers
	 */
	void notifyObservers();

	/***
	 * Retrieve transaction number in JSON format
	 * @param buf
	 * @param len
	 * @return
	 */
	char* jsonTRN(char *buf, unsigned int len);


private:
	//bit associated with the state element is set when changed
	uint16_t dirty = 0;

	//Observer list who will be notified of change
	std::list<StateObserver *> observers;

	//If we are in transaction don't notify until commit
	bool transaction = false;

	//Current transaction number
	unsigned int trn = 0;
	#define STATETRN "trn"

};



#endif /* STATE_H_ */
