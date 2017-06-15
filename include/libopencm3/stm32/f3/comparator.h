/** @defgroup comp_defines COMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32F3xx
 * Comparator module</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 29 Jun 2013
 *
 *LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define COMP1	0
#define COMP2	1
#define COMP3   2
#define COMP4   3
#define COMP5   4
#define COMP6   5
#define COMP7   6

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define COMP_CSR(i)			MMIO32(COMP_BASE + 0x1C + (i)*4)
#define COMP_CSR1			COMP_CSR(COMP1)
#define COMP_CSR2			COMP_CSR(COMP2)
#define COMP_CSR3                       COMP_CSR(COMP3)
#define COMP_CSR4                       COMP_CSR(COMP4)
#define COMP_CSR5                       COMP_CSR(COMP5)
#define COMP_CSR6                       COMP_CSR(COMP6)
#define COMP_CSR7                       COMP_CSR(COMP7)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* COMP_CSR Values ----------------------------------------------------------*/

#define COMP_CSR_LOCK			(1 << 31)
#define COMP_CSR_OUT			(1 << 30)

#define COMP_CSR_HYST_SHIFT		16
#define COMP_CSR_HYST			(3 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_NO		(0 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_LOW		(1 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_MED		(2 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_HIGH		(3 << COMP_CSR_HYST_SHIFT)

#define COMP_CSR_POL			(1 << 15)

#define COMP_CSR_OUTSEL_SHIFT		10
#define COMP_CSR_OUTSEL			(0xF << COMP_CSR_OUTSEL_SHIFT)

#define COMP2_CSR_OUTSEL_TIM1_IC1       (7 << COMP_CSR_OUTSEL_SHIFT)

#define COMP_CSR_WINDWEN		(1 << 9)

#define COMP_CSR_INMSEL_SHIFT		4
#define COMP_CSR_INMSEL			(7 << COMP_CSR_INMSEL_SHIFT)

#define COMP2_CSR_INMSEL_DAC1_OUT1      (4 << COMP_CSR_INMSEL_SHIFT)

#define COMP2_CSR_COMPOUT_SHIFT          30
#define COMP2_CSR_COMPOUT               (1 << COMP2_CSR_COMPOUT_SHIFT)

#define COMP_CSR_INPSEL_SHIFT           7
#define COMP_CSR_INPSEL                 (1 << COMP_CSR_INMSEL_SHIFT)

#define COMP_CSR_EN			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void comp_enable(uint8_t id);
void comp_disable(uint8_t id);
void comp_select_input_m(uint8_t id, uint32_t input);
void comp_select_input_p(uint8_t id, uint32_t input);
void comp_select_output(uint8_t id, uint32_t output);
void comp_select_hyst(uint8_t id, uint32_t hyst);

END_DECLS
/**@}*/

#endif
