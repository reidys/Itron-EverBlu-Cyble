 /*  the radian_trx SW shall not be distributed  nor used for commercial product*/
 /*  it is exposed just to demonstrate CC1101 capability to reader water meter indexes */

#define METER_YEAR              16
#define METER_SERIAL            291067

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

	printf("Liters: %i\n", meter_data.liters);

	printf("reads_counter: %i\n", meter_data.reads_counter);

	printf("battery_left: %i\n", meter_data.battery_left);

        printf("time_start: %i\n", meter_data.time_start);

        printf("time_end: %i\n", meter_data.time_end);

	return 0;
}
