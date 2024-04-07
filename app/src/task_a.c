/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : task_a.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"
#include "app.h"
#include "task_a_fsm.h"

/********************** macros and definitions *******************************/
#define G_TASK_A_CNT_INI	0u

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_task_a 		= "Task A (Barrera) (System Modeling)";

/********************** external data declaration *****************************/
uint32_t g_task_a_cnt;

s_task_a_t g_state_task_a;

e_task_a_t g_event_task_a;
bool g_b_event_task_a;


const char *const names_e_task_a[] = {
        "ev_A_P_ON",
        "ev_A_P_OFF",
        "ev_T_I_ON",
        "ev_T_I_OFF",
        "ev_T_R_ON",
        "ev_T_R_OFF",
        "ev_A_E_ON",
        "ev_A_E_OFF",
        "ev_B_V_ON",
        "ev_B_V_OFF",
        "ev_B_H_ON",
        "ev_B_H_OFF"
    };

const char *const names_s_task_a[] = {
        "ESPERA_AUTO_st",
        "ESPERA_BOTON_st",
        "ESPERA_RETIRAR_TICKET_st",
        "SUBIENDO_BARRERA_st",
        "ESPERA_ENTRE_AUTO_st",
        "AUTO_ATRAVESANDO_BARRERA_st",
        "BAJANDO_BARRERA_st"
    };


/********************** external functions definition ************************/
void task_a_init(void *parameters)
{
	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_a_init), p_task_a);

	g_task_a_cnt = G_TASK_A_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_a_cnt), (int)g_task_a_cnt);

	g_state_task_a = ESPERA_AUTO_st;
	g_event_task_a = ev_A_P_OFF;
	g_b_event_task_a = false;

	/***
	 *
	 * MI CAMBIO - START
	 * ***/
	/* Print out: Task execution FSM */
	LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_state_task_a), names_s_task_a[(int)g_state_task_a]);
	LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_event_task_a), names_e_task_a[(int)g_event_task_a]);
	/***
	 *
	 * MI CAMBIO - END
	 * ***/
}


/***
 *
 * MI CAMBIO - START
 * ***/
void task_a_update(void *parameters)
{
	/* Update Task A Counter */
	g_task_a_cnt++;

	if (true == g_b_event_task_a)
	{
		g_b_event_task_a = false;

		/* Print out: Application Update */
		LOGGER_LOG("  %s is is running - %s\r\n", GET_NAME(task_a_update), p_task_a);

		/* Print out: Task execution counter */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_a_cnt), (int)g_task_a_cnt);

		switch (g_state_task_a){
			case ESPERA_AUTO_st:
				if (ev_A_P_ON == g_event_task_a)
					g_state_task_a = ESPERA_BOTON_st;

				break;

			case ESPERA_BOTON_st:
				if (ev_A_P_OFF == g_event_task_a)
					g_state_task_a = ESPERA_AUTO_st;

				if (ev_T_I_ON == g_event_task_a)
					g_state_task_a = ESPERA_RETIRAR_TICKET_st;

				break;

			case ESPERA_RETIRAR_TICKET_st:
				if (ev_T_R_ON == g_event_task_a)
					g_state_task_a = SUBIENDO_BARRERA_st;

				if (ev_A_P_OFF == g_event_task_a)
					g_state_task_a = ESPERA_AUTO_st;

				break;

			case SUBIENDO_BARRERA_st:
				if (ev_B_V_ON == g_event_task_a)
					g_state_task_a = ESPERA_ENTRE_AUTO_st;
				break;

			case ESPERA_ENTRE_AUTO_st:
				if (ev_A_E_ON == g_event_task_a)
					g_state_task_a = AUTO_ATRAVESANDO_BARRERA_st;
				break;

			case AUTO_ATRAVESANDO_BARRERA_st:
				if (ev_A_E_OFF == g_event_task_a)
					g_state_task_a = BAJANDO_BARRERA_st;
				break;

			case BAJANDO_BARRERA_st:
				if (ev_B_H_ON == g_event_task_a)
					g_state_task_a = ESPERA_AUTO_st;
				break;

			default:
				LOGGER_LOG("ERROR - default case \r\n");
				break;
		}
		/* Print out: Task execution FSM */
		LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_state_task_a), names_s_task_a[(int)g_state_task_a]);
		LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_event_task_a), names_e_task_a[(int)g_event_task_a]);
	}
}

	/***
	 *
	 * MI CAMBIO - END
	 * ***/

/********************** end of file ******************************************/
