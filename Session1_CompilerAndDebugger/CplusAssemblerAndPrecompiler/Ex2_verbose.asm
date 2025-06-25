	.arch armv8-a
	.file	"Ex2.cpp"
// GNU C++17 (Debian 12.2.0-14) version 12.2.0 (aarch64-linux-gnu)
//	compiled by GNU C version 12.2.0, GMP version 6.2.1, MPFR version 4.1.1-p1, MPC version 1.3.1, isl version isl-0.25-GMP

// warning: MPFR header version 4.1.1-p1 differs from library version 4.2.0.
// GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
// options passed: -mlittle-endian -mabi=lp64 -fasynchronous-unwind-tables
	.text
	.align	2
	.global	_Z6myfunci
	.type	_Z6myfunci, %function
_Z6myfunci:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #16	//,,
	.cfi_def_cfa_offset 16
	str	w0, [sp, 12]	// i, i
// Ex2.cpp:4:     return i + INC;
	ldr	w0, [sp, 12]	// tmp94, i
	add	w0, w0, 1	// _2, tmp94,
// Ex2.cpp:5: }
	add	sp, sp, 16	//,,
	.cfi_def_cfa_offset 0
	ret	
	.cfi_endproc
.LFE0:
	.size	_Z6myfunci, .-_Z6myfunci
	.align	2
	.global	main
	.type	main, %function
main:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp	//,
// Ex2.cpp:7:     int a=10;
	mov	w0, 10	// tmp94,
	str	w0, [sp, 28]	// tmp94, a
// Ex2.cpp:9:     return myfunc(2);
	mov	w0, 2	//,
	bl	_Z6myfunci		//
// Ex2.cpp:9:     return myfunc(2);
	nop	
// Ex2.cpp:10: }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret	
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
