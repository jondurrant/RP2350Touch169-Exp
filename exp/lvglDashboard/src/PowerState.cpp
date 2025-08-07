/*
 * PowerState.cpp
 *
 *  Created on: 5 Aug 2025
 *      Author: jondurrant
 */

#include "PowerState.h"
#include <stdio.h>
#include <string.h>
#include "json-maker/json-maker.h"
#include "TwinProtocol.h"

#define BAT1CPUSLOT 1
#define BAT2CPUSLOT 2
#define BAT1DRVSLOT 3
#define BAT2DRVSLOT 4
#define BAT1CHGSLOT 5
#define BAT2CHGSLOT 6
#define BAT1VOLTSLOT 7
#define BAT2VOLTSLOT 8
#define BAT1PERSLOT 9
#define BAT2PERSLOT 10
#define CHGVOLTSLOT 11
#define CHGTIMESLOT 12
#define CHGREMAINSLOT 13
#define CHGAVLSLOT 14

PowerState::PowerState() {
	elements=15;
	jsonHelpers[BAT1CPUSLOT] = (StateFunc)&PowerState::jsonBat1CPU;
	jsonHelpers[BAT2CPUSLOT] = (StateFunc)&PowerState::jsonBat2CPU;
	jsonHelpers[BAT1DRVSLOT] = (StateFunc)&PowerState::jsonBat1Drive;
	jsonHelpers[BAT2DRVSLOT] = (StateFunc)&PowerState::jsonBat2Drive;
	jsonHelpers[BAT1CHGSLOT] = (StateFunc)&PowerState::jsonBat1Charge;
	jsonHelpers[BAT2CHGSLOT] = (StateFunc)&PowerState::jsonBat2Charge;
	jsonHelpers[BAT1VOLTSLOT] = (StateFunc)&PowerState::jsonBat1Volt;
	jsonHelpers[BAT2VOLTSLOT] = (StateFunc)&PowerState::jsonBat2Volt;
	jsonHelpers[BAT1PERSLOT] = (StateFunc)&PowerState::jsonBat1Per;
	jsonHelpers[BAT2PERSLOT] = (StateFunc)&PowerState::jsonBat2Per;
	jsonHelpers[CHGVOLTSLOT] = (StateFunc)&PowerState::jsonChargeVolt;
	jsonHelpers[CHGTIMESLOT] = (StateFunc)&PowerState::jsonChargeTime;
	jsonHelpers[CHGREMAINSLOT] = (StateFunc)&PowerState::jsonChargeRemain;
	jsonHelpers[CHGAVLSLOT] = (StateFunc)&PowerState::jsonChargeAvl;
}

PowerState::~PowerState() {
	// TODO Auto-generated destructor stub
}



bool PowerState::getBat1CPU(){
	return xBat1Cpu;
}

void PowerState::setBat1CPU(bool b){
	xBat1Cpu = b;
	setDirty(BAT1CPUSLOT);
}

bool PowerState::getBat2CPU(){
	return xBat2Cpu;
}

void PowerState::setBat2CPU(bool b){
	xBat2Cpu = b;
	setDirty(BAT2CPUSLOT);
}

bool PowerState::getBat1Drive(){
	return xBat1Drive;
}

void PowerState::setBat1Drive(bool b){
	xBat1Drive = b;
	setDirty(BAT1DRVSLOT);
}

bool PowerState::getBat2Drive(){
	return xBat2Drive;
}

void PowerState::setBat2Drive(bool b){
	xBat2Drive = b;
	setDirty(BAT2DRVSLOT);
}

bool PowerState::getBat1Charge(){
	return xBat1Charge ;
}

void PowerState::setBat1Charge(bool b){
	xBat1Charge = b;
	setDirty(BAT1CHGSLOT);
}

bool PowerState::getBat2Charge(){
	return xBat2Charge ;
}

void PowerState::setBat2Charge(bool b){
	xBat2Charge = b;
	setDirty(BAT2CHGSLOT);
}

float PowerState::getBat1Volt(){
	return xBat1Volt;
}
void PowerState::setBat1Volt(float v){
	xBat1Volt = v;
	setDirty(BAT1VOLTSLOT);
}

float PowerState::getBat2Volt(){
	return xBat2Volt;
}
void PowerState::setBat2Volt(float v){
	xBat2Volt = v;
	setDirty(BAT2VOLTSLOT);
}

float PowerState::getBat1Per(){
	return xBat1Per;
}
void PowerState::setBat1Per(float v){
	xBat1Per = v;
	setDirty(BAT1PERSLOT);
}

float PowerState::getBat2Per(){
	return xBat2Per;
}
void PowerState::setBat2Per(float v){
	xBat2Per = v;
	setDirty(BAT2PERSLOT);
}

float PowerState::getChgVolt(){
	return xChargeVolt;
}
void PowerState::setChgVolt(float v){
	xChargeVolt = v;
	setDirty(CHGVOLTSLOT);
}

uint PowerState::getChgTime(){
	return xChargeTime;
}
void PowerState::setChgTime(uint v){
	xChargeTime = v;
	setDirty(CHGTIMESLOT);
}

uint PowerState::getChgRemain(){
	return xChargeRemain;
}
void PowerState::setChgRemain(uint v){
	xChargeRemain = v;
	setDirty(CHGREMAINSLOT);
}

bool PowerState::getChargeAvl(){
	return xChargeAvl;
}

void PowerState::setChargeAvl(bool b){
	xChargeAvl = b;
	setDirty(CHGAVLSLOT);
}










char* PowerState::jsonBat1CPU(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT1CPU, getBat1CPU(), &l);
	return p;
}

char*PowerState:: jsonBat2CPU(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT2CPU, getBat2CPU(), &l);
	return p;
}

char* PowerState::jsonBat1Drive(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT1DRIVE, getBat1Drive(), &l);
	return p;
}

char* PowerState::jsonBat2Drive(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT2DRIVE, getBat2Drive(), &l);
	return p;
}

char* PowerState::jsonBat1Charge(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT1CHARGE, getBat1Charge(), &l);
	return p;
}

char* PowerState::jsonBat2Charge(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATEBAT2CHARGE, getBat2Charge(), &l);
	return p;
}

char* PowerState::jsonBat1Volt(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_double( p, STATEBAT1VOLT, (double)getBat1Volt(), &l);
	return p;
}

char* PowerState::jsonBat2Volt(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_double( p, STATEBAT2VOLT, (double)getBat2Volt(), &l);
	return p;
}

char*PowerState:: jsonBat1Per(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_double( p, STATEBAT1PER, (double)getBat1Per(), &l);
	return p;
}

char* PowerState::jsonBat2Per(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_double( p, STATEBAT2PER, (double)getBat2Per(), &l);
	return p;
}

char*PowerState:: jsonChargeVolt(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_double( p, STATECHARGEVOLT, (double)getChgVolt(), &l);
	return p;
}

char* PowerState::jsonChargeTime(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_uint( p, STATECHARGETIME, getChgTime(), &l);
	return p;
}

char* PowerState::jsonChargeRemain(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_uint( p, STATECHARGEREMAIN, getChgRemain(), &l);
	return p;
}

char* PowerState::jsonChargeAvl(char *buf, unsigned int len){
	char *p = buf;
	size_t l = len;
	p = json_bool( p, STATECHGAVL, getChargeAvl(), &l);
	return p;
}



void PowerState::updateFromJson(json_t const *j){
	json_t const* item;

	//Look for header of "state" or "delta"
	json_t const* json = json_getProperty( j, TWINSTATE );
	if ( json != NULL){
		if (JSON_OBJ !=  json_getType( json )){
			printf("Header is not an object\n");
			return;
		}
	} else {
		json = json_getProperty( j, TWINDELTA );
		if ( json != NULL){
			if (JSON_OBJ !=  json_getType( json )){
				printf("Header is not an object\n");
				return;
			}
		} else {
			json = j;
		}
	}


	item = json_getProperty( json, STATEBAT1CPU );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat1CPU(json_getBoolean(item));
	}
	item = json_getProperty( json, STATEBAT2CPU );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat2CPU(json_getBoolean(item));
	}

	item = json_getProperty( json, STATEBAT1DRIVE );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat1Drive(json_getBoolean(item));
	}
	item = json_getProperty( json, STATEBAT2DRIVE );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat2Drive(json_getBoolean(item));
	}

	item = json_getProperty( json, STATEBAT1CHARGE );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat1Charge(json_getBoolean(item));
	}
	item = json_getProperty( json, STATEBAT2CHARGE );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setBat2Charge(json_getBoolean(item));
	}

	item = json_getProperty( json, STATECHGAVL );
	if ( item != NULL && JSON_BOOLEAN == json_getType( item ) ) {
		setChargeAvl(json_getBoolean(item));
	}

	item = json_getProperty( json, STATEBAT1VOLT );
	if ( item != NULL && JSON_REAL == json_getType( item ) ) {
		setBat1Volt(json_getReal(item));
	}
	item = json_getProperty( json, STATEBAT2VOLT );
	if ( item != NULL && JSON_REAL == json_getType( item ) ) {
		setBat2Volt(json_getReal(item));
	}

	item = json_getProperty( json, STATEBAT1PER );
	if ( item != NULL && JSON_REAL == json_getType( item ) ) {
		setBat1Per(json_getReal(item));
	}
	item = json_getProperty( json, STATEBAT2PER );
	if ( item != NULL && JSON_REAL == json_getType( item ) ) {
		setBat2Per(json_getReal(item));
	}

	item = json_getProperty( json, STATECHARGEVOLT );
	if ( item != NULL && JSON_REAL == json_getType( item ) ) {
		setChgVolt(json_getReal(item));
	}

	item = json_getProperty( json, STATECHARGETIME );
	if ( item != NULL && JSON_INTEGER == json_getType( item ) ) {
		setChgTime(json_getInteger(item));
	}
	item = json_getProperty( json, STATECHARGEREMAIN );
	if ( item != NULL && JSON_INTEGER == json_getType( item ) ) {
		setChgRemain(json_getInteger(item));
	}


	State::updateFromJson(json);
}



