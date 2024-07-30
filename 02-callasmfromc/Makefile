# ----------------------------
# Makefile Options
# ----------------------------

NAME = 02-callasmfromc
DESCRIPTION = "Example hello world app for Agon"
COMPRESSED = NO
ARCHIVED = NO
INIT_LOC = 040000
BSSHEAP_LOW = 050000
BSSHEAP_HIGH = 0B7FFF
STACK_HIGH = 0B7FFF

CFLAGS = -Werror -Wall -Wextra -Oz -DCEDEV
CXXFLAGS = -Werror -Wall -Wextra -Oz - DCEDEV
LDHAS_EXIT_HANDLER:=0

SEND_AGON_SCRIPT = "../../agon-hexload/send.py"

# ----------------------------

include $(shell cedev-config --makefile)

send:
	python3 $(SEND_AGON_SCRIPT) bin/$(NAME).bin