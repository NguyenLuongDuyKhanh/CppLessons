	.arch armv6
	.fpu vfp
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"Ex0.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,4
	.section	.rodata
	.align	2
.LC0:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	.fnstart
.LFB1754:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #32
	sub	sp, sp, #32
	mov	r1, #7
	mov	r0, #3
	bl	_Z5myMaxIiiET_S0_T0_
	mov	r3, r0
	mov	r1, r3
	ldr	r0, .L3+8
	bl	_ZNSolsEi
	mov	r3, r0
	ldr	r1, .L3+12
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	mov	r0, #7
	vldr.64	d0, .L3
	bl	_Z5myMaxIdiET_S0_T0_
	vmov.f64	d7, d0
	vmov.f64	d0, d7
	ldr	r0, .L3+8
	bl	_ZNSolsEd
	mov	r3, r0
	ldr	r1, .L3+12
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	mov	r1, #101
	mov	r0, #103
	bl	_Z5myMaxIciET_S0_T0_
	mov	r3, r0
	mov	r1, r3
	ldr	r0, .L3+8
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	mov	r3, r0
	ldr	r1, .L3+12
	mov	r0, r3
	bl	_ZNSolsEPFRSoS_E
	ldr	r3, .L3+16
	sub	ip, fp, #24
	mov	lr, r3
	ldmia	lr!, {r0, r1, r2, r3}
	stmia	ip!, {r0, r1, r2, r3}
	ldr	r3, [lr]
	str	r3, [ip]
	sub	r1, fp, #24
	sub	r3, fp, #32
	mov	r2, #5
	mov	r0, r3
	bl	_ZN5ArrayIiEC1EPii
	sub	r3, fp, #32
	mov	r0, r3
	bl	_ZN5ArrayIiE5printEv
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L4:
	.align	3
.L3:
	.word	0
	.word	1074266112
	.word	_ZSt4cout
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.word	.LC0
	.fnend
	.size	main, .-main
	.section	.text._Z5myMaxIiiET_S0_T0_,"axG",%progbits,_Z5myMaxIiiET_S0_T0_,comdat
	.align	2
	.weak	_Z5myMaxIiiET_S0_T0_
	.syntax unified
	.arm
	.type	_Z5myMaxIiiET_S0_T0_, %function
_Z5myMaxIiiET_S0_T0_:
	.fnstart
.LFB2019:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	ble	.L6
	ldr	r3, [fp, #-8]
	b	.L8
.L6:
	ldr	r3, [fp, #-12]
.L8:
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z5myMaxIiiET_S0_T0_, .-_Z5myMaxIiiET_S0_T0_
	.section	.text._Z5myMaxIdiET_S0_T0_,"axG",%progbits,_Z5myMaxIdiET_S0_T0_,comdat
	.align	2
	.weak	_Z5myMaxIdiET_S0_T0_
	.syntax unified
	.arm
	.type	_Z5myMaxIdiET_S0_T0_, %function
_Z5myMaxIdiET_S0_T0_:
	.fnstart
.LFB2022:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	vstr.64	d0, [fp, #-12]
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	vmov	s15, r3	@ int
	vcvt.f64.s32	d7, s15
	vldr.64	d6, [fp, #-12]
	vcmpe.f64	d6, d7
	vmrs	APSR_nzcv, FPSCR
	ble	.L15
	vldr.64	d7, [fp, #-12]
	b	.L13
.L15:
	ldr	r3, [fp, #-16]
	vmov	s15, r3	@ int
	vcvt.f64.s32	d7, s15
.L13:
	vmov.f64	d0, d7
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z5myMaxIdiET_S0_T0_, .-_Z5myMaxIdiET_S0_T0_
	.section	.text._Z5myMaxIciET_S0_T0_,"axG",%progbits,_Z5myMaxIciET_S0_T0_,comdat
	.align	2
	.weak	_Z5myMaxIciET_S0_T0_
	.syntax unified
	.arm
	.type	_Z5myMaxIciET_S0_T0_, %function
_Z5myMaxIciET_S0_T0_:
	.fnstart
.LFB2024:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	mov	r3, r0
	str	r1, [fp, #-12]
	strb	r3, [fp, #-5]
	ldrb	r2, [fp, #-5]	@ zero_extendqisi2
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	movge	r3, r2
	movlt	r3, r3
	uxtb	r3, r3
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z5myMaxIciET_S0_T0_, .-_Z5myMaxIciET_S0_T0_
	.section	.text._ZN5ArrayIiEC2EPii,"axG",%progbits,_ZN5ArrayIiEC5EPii,comdat
	.align	2
	.weak	_ZN5ArrayIiEC2EPii
	.syntax unified
	.arm
	.type	_ZN5ArrayIiEC2EPii, %function
_ZN5ArrayIiEC2EPii:
	.fnstart
.LFB2027:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #24
	sub	sp, sp, #24
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	str	r2, [fp, #-24]
	ldr	r3, [fp, #-24]
	cmn	r3, #-536870910
	bhi	.L19
	lsl	r3, r3, #2
	mov	r0, r3
	bl	_Znaj
	mov	r3, r0
	mov	r2, r3
	ldr	r3, [fp, #-16]
	str	r2, [r3]
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-24]
	str	r2, [r3, #4]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L21
.L19:
	bl	__cxa_throw_bad_array_new_length
.L22:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-20]
	add	r2, r2, r3
	ldr	r3, [fp, #-16]
	ldr	r1, [r3]
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	add	r3, r1, r3
	ldr	r2, [r2]
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L21:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	ldr	r2, [fp, #-8]
	cmp	r2, r3
	blt	.L22
	ldr	r3, [fp, #-16]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.fnend
	.size	_ZN5ArrayIiEC2EPii, .-_ZN5ArrayIiEC2EPii
	.weak	_ZN5ArrayIiEC1EPii
	.set	_ZN5ArrayIiEC1EPii,_ZN5ArrayIiEC2EPii
	.section	.rodata
	.align	2
.LC1:
	.ascii	" \000"
	.section	.text._ZN5ArrayIiE5printEv,"axG",%progbits,_ZN5ArrayIiE5printEv,comdat
	.align	2
	.weak	_ZN5ArrayIiE5printEv
	.syntax unified
	.arm
	.type	_ZN5ArrayIiE5printEv, %function
_ZN5ArrayIiE5printEv:
	.fnstart
.LFB2029:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #16
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L25
.L26:
	ldr	r1, .L27
	ldr	r0, .L27+4
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	ldr	r3, [fp, #-16]
	ldr	r2, [r3]
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r1, r3
	bl	_ZNSolsEi
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L25:
	ldr	r3, [fp, #-16]
	ldr	r3, [r3, #4]
	ldr	r2, [fp, #-8]
	cmp	r2, r3
	blt	.L26
	ldr	r1, .L27+8
	ldr	r0, .L27+4
	bl	_ZNSolsEPFRSoS_E
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L28:
	.align	2
.L27:
	.word	.LC1
	.word	_ZSt4cout
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.fnend
	.size	_ZN5ArrayIiE5printEv, .-_ZN5ArrayIiE5printEv
	.text
	.align	2
	.syntax unified
	.arm
	.type	_Z41__static_initialization_and_destruction_0ii, %function
_Z41__static_initialization_and_destruction_0ii:
	.fnstart
.LFB2296:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-8]
	cmp	r3, #1
	bne	.L31
	ldr	r3, [fp, #-12]
	ldr	r2, .L32
	cmp	r3, r2
	bne	.L31
	ldr	r0, .L32+4
	bl	_ZNSt8ios_base4InitC1Ev
	ldr	r2, .L32+8
	ldr	r1, .L32+12
	ldr	r0, .L32+4
	bl	__aeabi_atexit
.L31:
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L33:
	.align	2
.L32:
	.word	65535
	.word	_ZStL8__ioinit
	.word	__dso_handle
	.word	_ZNSt8ios_base4InitD1Ev
	.cantunwind
	.fnend
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align	2
	.syntax unified
	.arm
	.type	_GLOBAL__sub_I_main, %function
_GLOBAL__sub_I_main:
	.fnstart
.LFB2297:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r1, .L35
	mov	r0, #1
	bl	_Z41__static_initialization_and_destruction_0ii
	pop	{fp, pc}
.L36:
	.align	2
.L35:
	.word	65535
	.cantunwind
	.fnend
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align	2
	.word	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Raspbian 12.2.0-14+rpi1) 12.2.0"
	.section	.note.GNU-stack,"",%progbits
