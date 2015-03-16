CFLAGS		= -std=c99 -Wall


# Internal definitions
FRAMA_C_SHARE	= $(shell frama-c -print-share-path)
ALL_INCLUDES	= ${INCLUDES} -I${FRAMA_C_SHARE}/libc
ALL_SOURCES		=  ${FRAMA_C_SHARE}/libc.c ${SOURCES}
# C Preprocessor
# option -C does not discard comments

CPP			= gcc -C -E -nostdinc ${ALL_INCLUDES} -o %2 %1


frama_project: ${ALL_SOURCES}
	frama-c -debug 0 -pp-annot -cpp-command '${CPP}' ${ALL_SOURCES} -rte -save frama_project

wp:
	rm -rf ./proofs
	frama-c -load frama_project -wp-rte -wp-fct ${TARGETS} -wp-out ./proofs
