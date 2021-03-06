#ifndef __REGS_H_
#define __REGS_H_

enum {
	_AX, _CX, _DX, _BX,
	_SP, _BP, _SI, _DI
};

enum {
    _CS, _DS, _SS, _ES, _FS, _GS
};


typedef union {
	int32_t  sdword[1];
	uint32_t dword[1];
	int16_t  sword[2];
	uint16_t word[2];
	int8_t   sbyte[4];
	uint8_t  byte[4];
} reg32_t;

typedef struct {
    uint32_t tag;
} fpu_p_reg_t;

typedef enum {
	ROUND_Nearest = 0,		
	ROUND_Down    = 1,
	ROUND_Up      = 2,	
	ROUND_Chop    = 3
} fpu_round_t;

typedef enum {
	d_none = 0,
	d_add8,
	d_add16,
	d_add32,
	d_and8,
	d_and16,
	d_and32,
	d_dec8,
	d_dec16,
	d_dec32,
	d_inc8,		//10
	d_inc16,
	d_inc32,
	d_imul8,
	d_imul16,
	d_imul32,
	d_or8,
	d_or16,
	d_or32,
	d_mul8,
	d_mul16,	//20
	d_mul32,
	d_neg8,
	d_neg16,
	d_neg32,
	d_shl8,
	d_shl16,
	d_shl32,
	d_shr8,
	d_shr16,
	d_shr32,	//30
	d_sar8,
	d_sar16,
	d_sar32,
	d_sub8,
	d_sub16, 
	d_sub32,
	d_xor8,
	d_xor16,
	d_xor32,
	d_unknown	//40
} defered_flags_t;

#pragma pack(push, 1)

typedef union {
	#ifdef USE_FLOAT
	float		f;
	uint32_t 	ll;	// same, to avoid more #ifdef...
	#else
    double d;
    struct {
        uint32_t lower;
        uint32_t upper;
    } l;
    struct {
        float lower;
        float upper;
    } f;
    int64_t ll;
	#endif
} fpu_reg_t;

typedef union {
	//long double ld;	// works only if 80bits!
	struct {
		uint64_t lower;
		uint16_t upper;
	} l;
} longdouble_t;

typedef struct {
	#ifdef HAVE_LD80BITS
	long double 	ld;
	#else
	longdouble_t 	ld;
	#endif
	uint64_t		ref;
} fpu_ld_t;

typedef struct {
	uint64_t		ll;
	uint64_t		ref;
} fpu_ll_t;

typedef union {
    struct __attribute__ ((__packed__)) {
        unsigned int F__CF:1;
		unsigned int F__res1:1;
        unsigned int F__PF:1;
		unsigned int F__res2:1;
        unsigned int F__AF:1;
		unsigned int F__res3:1;
        unsigned int F__ZF:1;
        unsigned int F__SF:1;
        unsigned int F__TF:1;
        unsigned int F__IF:1;
        unsigned int F__DF:1;
        unsigned int F__OF:1;
        unsigned int F__IOPL:2;
        unsigned int F__NT:1;
        unsigned int F__dummy:1;
        unsigned int F__RF:1;
        unsigned int F__VM:1;
        unsigned int F__AC:1;
        unsigned int F__VIF:1; 
        unsigned int F__VIP:1;
        unsigned int F__ID:1;
    } f;
    uint32_t    x32;
} x86flags_t;

typedef enum {
    F_CF = 0,
	F_res1,
    F_PF,
	F_res2,
    F_AF,
	F_res3,
    F_ZF,
    F_SF,
    F_TF,
    F_IF,
    F_DF,
    F_OF,
    F_IOPL, // double
    F_NT = 14,
    F_dummy,
    F_RF,
    F_VM,
    F_AC,
    F_VIF,
    F_VIP,
    F_ID,
	F_LAST
} flags_names_t;


typedef union {
    struct __attribute__ ((__packed__)) {
        unsigned int F87_IE:1;
        unsigned int F87_DE:1;
        unsigned int F87_ZE:1;
        unsigned int F87_OE:1;
        unsigned int F87_UE:1;
        unsigned int F87_PE:1;
        unsigned int F87_SF:1;
        unsigned int F87_ES:1;
        unsigned int F87_C0:1;
		unsigned int F87_C1:1;
		unsigned int F87_C2:1;
		unsigned int F87_TOP:3;
		unsigned int F87_C3:1;
		unsigned int F87_B:1;
    } f;
    uint16_t    x16;
} x87flags_t;

typedef union {
	uint64_t	q;
	int64_t		sq;
	uint32_t	ud[2];
	int32_t 	sd[2];
	uint16_t 	uw[4];
	int16_t 	sw[4];
	uint8_t 	ub[8];
	int8_t 		sb[8];
} mmx_regs_t;

typedef union {
	uint64_t q[2];
	int64_t sq[2];
	double d[2];
	float f[4];
	uint32_t ud[4];
	int32_t sd[4];
	uint16_t uw[8];
	int16_t sw[8];
	uint8_t ub[16];
	int8_t sb[16];
} sse_regs_t;
#pragma pack(pop)

#define R_EIP emu->ip.dword[0]
#define R_EAX emu->regs[_AX].dword[0]
#define R_EBX emu->regs[_BX].dword[0]
#define R_ECX emu->regs[_CX].dword[0]
#define R_EDX emu->regs[_DX].dword[0]
#define R_EDI emu->regs[_DI].dword[0]
#define R_ESI emu->regs[_SI].dword[0]
#define R_ESP emu->regs[_SP].dword[0]
#define R_EBP emu->regs[_BP].dword[0]
#define R_AX emu->regs[_AX].word[0]
#define R_BX emu->regs[_BX].word[0]
#define R_CX emu->regs[_CX].word[0]
#define R_DX emu->regs[_DX].word[0]
#define R_DI emu->regs[_DI].word[0]
#define R_SI emu->regs[_SI].word[0]
#define R_SP emu->regs[_SP].word[0]
#define R_BP emu->regs[_BP].word[0]
#define R_AL emu->regs[_AX].byte[0]
#define R_AH emu->regs[_AX].byte[1]
#define R_CX emu->regs[_CX].word[0]
#define R_CL emu->regs[_CX].byte[0]
#define R_CS emu->segs[_CS]
#define R_DS emu->segs[_DS]
#define R_SS emu->segs[_SS]
#define R_ES emu->segs[_ES]
#define R_FS emu->segs[_FS]
#define R_GS emu->segs[_GS]

#if 0
#define ACCESS_FLAG(F)  emu->eflags.f.F
#define SET_FLAG(F)     emu->eflags.f.F = 1
#define CLEAR_FLAG(F)   emu->eflags.f.F = 0
#define CONDITIONAL_SET_FLAG(COND, F)   emu->eflags.f.F = (COND)?1:0
#else
#define ACCESS_FLAG(F)  emu->flags[F]
#define SET_FLAG(F)     emu->flags[F] = 1
#define CLEAR_FLAG(F)   emu->flags[F] = 0
#define CONDITIONAL_SET_FLAG(COND, F)   emu->flags[F] = (COND)?1:0
#endif

#endif //__REGS_H_
