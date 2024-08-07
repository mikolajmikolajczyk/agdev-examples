# ----------------------------
# Makefile Options
# ----------------------------

NAME = 05-prts
DESCRIPTION = "How to use programmable reload timers"
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

# This makes it possible to use files shared between examples in ../lib
EXTRA_HEADERS +=  $(sort $(call rwildcard,../lib,*.h))
EXTRA_ASM_SOURCES +=  $(sort $(call rwildcard,../lib,*.asm))
EXTRA_C_SOURCES +=   $(sort $(call rwildcard,../lib,*.$(C_EXTENSION)))
EXTRA_CXX_SOURCES += $(sort $(call rwildcard,../lib,*.$(CPP_EXTENSION)))

# ----------------------------

include $(shell cedev-config --makefile)

send:
	python3 $(SEND_AGON_SCRIPT) bin/$(NAME).bin