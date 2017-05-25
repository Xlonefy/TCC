/*
 * servo.h
 * 
 * Funções relacionadas ao uso de servos.
 *
 */

#ifndef SERVO_H
#define SERVO_H

typedef struct {
	unsigned short port;
	char position;
} servo;

void setup_servos(char ports)
{
	
}

void set_servopos(servo** servos, int size)
{
	
}

#endif
