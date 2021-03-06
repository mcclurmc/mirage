/******************************************************************************
 * debug_op.h
 *
 * Copyright (c) 2007 Tristan Gingold <tgingold@free.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __XEN_PUBLIC_IA64_DEBUG_OP_H__
#define __XEN_PUBLIC_IA64_DEBUG_OP_H__

/* Set/Get extra conditions to break.  */
#define XEN_IA64_DEBUG_OP_SET_FLAGS 1
#define XEN_IA64_DEBUG_OP_GET_FLAGS 2

/* Break on kernel single step.  */
#define XEN_IA64_DEBUG_ON_KERN_SSTEP   (1 << 0)

/* Break on kernel debug (breakpoint or watch point).  */
#define XEN_IA64_DEBUG_ON_KERN_DEBUG   (1 << 1)

/* Break on kernel taken branch.  */
#define XEN_IA64_DEBUG_ON_KERN_TBRANCH (1 << 2)

/* Break on interrupt injection.  */
#define XEN_IA64_DEBUG_ON_EXTINT       (1 << 3)

/* Break on interrupt injection.  */
#define XEN_IA64_DEBUG_ON_EXCEPT       (1 << 4)

/* Break on event injection.  */
#define XEN_IA64_DEBUG_ON_EVENT        (1 << 5)

/* Break on privop/virtualized instruction (slow path only).  */
#define XEN_IA64_DEBUG_ON_PRIVOP       (1 << 6)

/* Break on emulated PAL call (at entry).  */
#define XEN_IA64_DEBUG_ON_PAL          (1 << 7)

/* Break on emulated SAL call (at entry).  */
#define XEN_IA64_DEBUG_ON_SAL          (1 << 8)

/* Break on emulated EFI call (at entry).  */
#define XEN_IA64_DEBUG_ON_EFI          (1 << 9)

/* Break on rfi emulation (slow path only, before exec).  */
#define XEN_IA64_DEBUG_ON_RFI          (1 << 10)

/* Break on address translation switch.  */
#define XEN_IA64_DEBUG_ON_MMU          (1 << 11)

/* Break on bad guest physical address.  */
#define XEN_IA64_DEBUG_ON_BAD_MPA      (1 << 12)

/* Force psr.ss bit.  */
#define XEN_IA64_DEBUG_FORCE_SS        (1 << 13)

/* Force psr.db bit.  */
#define XEN_IA64_DEBUG_FORCE_DB        (1 << 14)

/* Break on ITR/PTR.  */
#define XEN_IA64_DEBUG_ON_TR           (1 << 15)

/* Break on ITC/PTC.L/PTC.G/PTC.GA.  */
#define XEN_IA64_DEBUG_ON_TC           (1 << 16)

/* Get translation cache.  */
#define XEN_IA64_DEBUG_OP_GET_TC   3

/* Translate virtual address to guest physical address.  */
#define XEN_IA64_DEBUG_OP_TRANSLATE 4

union xen_ia64_debug_op {
    uint64_t flags;
    struct xen_ia64_debug_vtlb {
        uint64_t nbr;                             /* IN/OUT */
        XEN_GUEST_HANDLE_64(ia64_tr_entry_t) tr;  /* IN/OUT */
    } vtlb;
};
typedef union xen_ia64_debug_op xen_ia64_debug_op_t;
DEFINE_XEN_GUEST_HANDLE(xen_ia64_debug_op_t);

#endif /* __XEN_PUBLIC_IA64_DEBUG_OP_H__ */
