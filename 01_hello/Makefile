SOURCES = hello.c

all: frama_project run_analysis

# Create frama-c project
include ../build.mk

run_analysis: frama_project
	frama-c -load frama_project -val -save project_after_analysis

