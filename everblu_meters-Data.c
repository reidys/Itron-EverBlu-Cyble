 /*  the radian_trx SW shall not be distributed  nor used for commercial product*/
 /*  it is exposed just to demonstrate CC1101 capability to reader water meter indexes */

#define METER_YEAR              <##>
#define METER_SERIAL            <######>

#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>

#include "everblu_meters.h"
#include "cc1101.c"


void IO_init(void)
{
	wiringPiSetup();
	pinMode (GDO2, INPUT);
	pinMode (GDO0, INPUT);           

	cc1101_init();
}


int main(int argc, char *argv[])
{
	struct tmeter_data meter_data;
	//struct mosquitto *mosq = NULL;
	//char buff[MQTT_MSG_MAX_SIZE];
	char meter_id[12];
	//char mqtt_topic[64];

	sprintf(meter_id, "%i_%i", METER_YEAR, METER_SERIAL);
	

	IO_init();
	meter_data = get_meter_data();
	//liters - Bill in metercube(didvie /1000 * per unit rate )
	printf("Liters: %i\n", meter_data.liters);
	//reads_counter - time the meter has been read
	printf("reads_counter: %i\n", meter_data.reads_counter);
	//battery_left - time in months
	printf("battery_left: %i\n", meter_data.battery_left);
	//time_start - wake time of meter
        printf("time_start: %i\n", meter_data.time_start);
	//time_end - Sleep time of meter
        printf("time_end: %i\n", meter_data.time_end);

	return 0;
}
