/*
 * PowerState.h
 *
 *  Created on: 5 Aug 2025
 *      Author: jondurrant
 */

#ifndef EXP_LVGLDASHBOARD_SRC_POWERSTATE_H_
#define EXP_LVGLDASHBOARD_SRC_POWERSTATE_H_

#include "pico/stdlib.h"
#include "State.h"

#define STATEBAT1CPU 			"BAT1CPU"
#define STATEBAT2CPU 			"BAT2CPU"
#define STATEBAT1DRIVE 		"BAT1DRIVE"
#define STATEBAT2DRIVE 		"BAT2DRIVE"
#define STATEBAT1CHARGE 	"BAT1CHARGE"
#define STATEBAT2CHARGE 	"BAT2CHARGE"
#define STATEBAT1VOLT 			"BAT1VOLT"
#define STATEBAT2VOLT 			"BAT2VOLT"
#define STATEBAT1PER 				"BAT1PER"
#define STATEBAT2PER 				"BAT2PER"
#define STATECHARGEVOLT 	"CHARGEVOLT"
#define STATECHARGETIME 	"CHARGETIME"
#define STATECHARGEREMAIN "CHARGEREMAIN"
#define STATECHGAVL				"CHARGEAVL"
#define STATEHEADER				"state"

class PowerState : public State{
public:
	PowerState();
	virtual ~PowerState();


	bool getBat1CPU();
	void setBat1CPU(bool b);

	bool getBat2CPU();
	void setBat2CPU(bool b);

	bool getBat1Drive();
	void setBat1Drive(bool b);

	bool getBat2Drive();
	void setBat2Drive(bool b);

	bool getBat1Charge();
	void setBat1Charge(bool b);

	bool getBat2Charge();
	void setBat2Charge(bool b);

	float getBat1Volt();
	void setBat1Volt(float v);

	float getBat2Volt();
	void setBat2Volt(float v);

	float getBat1Per();
	void setBat1Per(float v);

	float getBat2Per();
	void setBat2Per(float v);

	float getChgVolt();
	void setChgVolt(float v);

	uint getChgTime();
	void setChgTime(uint v);

	uint getChgRemain();
	void setChgRemain(uint v);

	bool getChargeAvl();
	void setChargeAvl(bool b);

	/***
	 * Update state data from a json structure
	 * @param json
	 */
	virtual void updateFromJson(json_t const *json);



protected:

	char* jsonBat1CPU(char *buf, unsigned int len);
	char* jsonBat2CPU(char *buf, unsigned int len);
	char* jsonBat1Drive(char *buf, unsigned int len);
	char* jsonBat2Drive(char *buf, unsigned int len);
	char* jsonBat1Charge(char *buf, unsigned int len);
	char* jsonBat2Charge(char *buf, unsigned int len);
	char* jsonBat1Volt(char *buf, unsigned int len);
	char* jsonBat2Volt(char *buf, unsigned int len);
	char* jsonBat1Per(char *buf, unsigned int len);
	char* jsonBat2Per(char *buf, unsigned int len);
	char* jsonChargeVolt(char *buf, unsigned int len);
	char* jsonChargeTime(char *buf, unsigned int len);
	char* jsonChargeRemain(char *buf, unsigned int len);
	char* jsonChargeAvl(char *buf, unsigned int len);

private:
	bool xBat1Cpu = false;
	bool xBat2Cpu = false;
	bool xBat1Drive = false;
	bool xBat2Drive = false;
	bool xBat1Charge = false;
	bool xBat2Charge = false;
	bool xChargeAvl = false;

	float xBat1Volt=0.0;
	float xBat2Volt=0.0;
	float xBat1Per=0.0;
	float xBat2Per=0.0;
	float xChargeVolt=0.0;
	int xChargeTime=0;
	int xChargeRemain=0;
};

#endif /* EXP_LVGLDASHBOARD_SRC_POWERSTATE_H_ */
