/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run make instead
 */

#include "config.h"
#include "vcl.h"
#include "vrt.h"
#include "vcc_if.h"
#include "vmod_abi.h"

/* Functions */
typedef VCL_STRING td_example_hello(VRT_CTX, VCL_STRING);
struct Vmod_example_Func {

	/* Functions */
	td_example_hello		*hello;

	/* Init/Fini */
	vmod_event_f	*_event;
};
/*lint -esym(754, Vmod_example_Func::*) */

static const struct Vmod_example_Func Vmod_Func = {

	/* Functions */
	vmod_hello,

	/* Init/Fini */
	init_function,
};

static const char Vmod_Proto[] =
	"/* Functions */\n"
	"typedef VCL_STRING td_example_hello(VRT_CTX, VCL_STRING);\n"
	"\n"

	"struct Vmod_example_Func {\n"
	"\n"
	"	/* Functions */\n"
	"	td_example_hello		*hello;\n"
	"\n"
	"	/* Init/Fini */\n"
	"	vmod_event_f	*_event;\n"
	"};\n"
	"static struct Vmod_example_Func Vmod_example_Func;";

/*lint -save -e786 -e840 */
static const char * const Vmod_Spec[] = {
	/* Functions */
	"example.hello\0"
	"Vmod_example_Func.hello\0"
	    "STRING\0"
		"STRING\0"
	"\0",

	/* Init/Fini */
	"$EVENT\0Vmod_example_Func._event",
	0
};
/*lint -restore */

/*lint -esym(759, Vmod_example_Data) */
const struct vmod_data Vmod_example_Data = {
	.vrt_major = VRT_MAJOR_VERSION,
	.vrt_minor = VRT_MINOR_VERSION,
	.name = "example",
	.func = &Vmod_Func,
	.func_len = sizeof(Vmod_Func),
	.proto = Vmod_Proto,
	.spec = Vmod_Spec,
	.abi = VMOD_ABI_Version,
	.file_id = "NKKLUXLLDPSMYDBWNDIXX@DZLEGUJQEQ",
};
