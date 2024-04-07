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
 * @file   : task_a_fsm.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef TASK_INC_TASK_A_FSM_H_
#define TASK_INC_TASK_A_FSM_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/
/* Events to excite Task A */
typedef enum e_task_a {
    ev_A_P_ON,
    ev_A_P_OFF,
    ev_T_I_ON,
    ev_T_I_OFF,
    ev_T_R_ON,
    ev_T_R_OFF,
    ev_A_E_ON,
    ev_A_E_OFF,
    ev_B_V_ON,
    ev_B_V_OFF,
    ev_B_H_ON,
    ev_B_H_OFF,
    } e_task_a_t;
/*  Names of the events to excite Task A */
//const char * const names_e_task_a[] = {"ev_A_P_ON","ev_A_P_OFF","ev_T_I_ON","ev_T_I_OFF","ev_T_R_ON","ev_T_R_OFF","ev_A_E_ON","ev_A_E_OFF","ev_B_V_ON","ev_B_V_OFF","ev_B_H_ON","ev_B_H_OFF"};

/* State of Task A */
typedef enum s_task_a {
    ESPERA_AUTO_st,
    ESPERA_BOTON_st,
    ESPERA_RETIRAR_TICKET_st,
    SUBIENDO_BARRERA_st,
    ESPERA_ENTRE_AUTO_st,
    AUTO_ATRAVESANDO_BARRERA_st,
    BAJANDO_BARRERA_st
    } s_task_a_t;

/*  Names of the states of Task A */
//const char names_s_task_a[][] = {"ESPERA_AUTO_st","ESPERA_BOTON_st","ESPERA_RETIRAR_TICKET_st","SUBIENDO_BARRERA_st","ESPERA_ENTRE_AUTO_st","AUTO_ATRAVESANDO_BARRERA_st","BAJANDO_BARRERA_st"};

/********************** external data declaration ****************************/
extern s_task_a_t g_state_task_a;
extern e_task_a_t g_event_task_a;
extern bool g_b_event_task_a;

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_A_FSM_H_ */

/********************** end of file ******************************************/
