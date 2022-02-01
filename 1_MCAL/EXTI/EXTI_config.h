/*
 * EXTI_config.h
 *
 *  Created on: Jan 24, 2022
 *      Author: 20111
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*********************** SENSE CONTROL **************************************/
/*
Choose option:
                                       LOW_LEVEL
                                       RISING_EDGE
                                       FALLING_EDGE
                                       ON_CHANGE
                                                          */
#define INT0_SENSE                     LOW_LEVEL

#define INT1_SENSE                     FALLING_EDGE

/*
Choose option: ONLY 2 Options for INT2
                                       RISING_EDGE
                                       FALLING_EDGE
                                                            */
#define INT2_SENSE                     FALLING_EDGE


/********************* INITIAL STATE******************************************/
/*
Choose option:
                                       ENABLED
                                       DISABLED
                                                          */
#define INT0_INITIAL_STATE             ENABLED

#define INT1_INITIAL_STATE             ENABLED

#define INT2_INITIAL_STATE             ENABLED




#endif /* EXTI_CONFIG_H_ */
