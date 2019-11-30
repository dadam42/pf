NAME:=#
MODS:=# Modules' directories, _each_ of these modules _must_ containt a Makefile
DIRSRCS:=# Directory containing sources
SRCS:=# Sources list, needed modules' .c files needed must be here, if, on a module
      # basis, no .c file is mentionned then all .c files module's will be automaticly added.
LIBS:=#each lib here can have its own directory in the variable $(lib)DIR
		#if unset, this variable wille have the default value $(lib)
LDLIBS:=#	Linker's extra flags (e.g. -L)
DIRINCS:=#
CFLAGS:=-Wall -Wextra -Werror
CPPFLAGS= -MT $@ -MMD -MP -MF $(DIRDEPS)/$*.d#	Preprocessor's flags
DIRDEPS:=.dep#Directory where dependencies' makefiles will be hidden.

define set
$(1):=$2
endef

LFLAGS:=$(LIBS:lib%=-l%)
$(foreach lib, $(LIBS), $(if $(lib)DIR,,$(call set, $(lib)DIR, $(lib))))
PATTERNMODS:=$(MODS:%=%/%)

MYSRCS:=$(filter-out $(PATTERNMODS),$(SRCS))
MODSSRCS:=$(filter $(PATTERNMODS),$(SRCS))

#if DIRSRCS is empty lets give it a value anyway:
ifeq ($(DIRSRCS), )
DIRSRCS:=.
endif

$(foreach lib, $(LIBS), $(if $($(lib)INC), ,$(call set, $($(lib)INC), $lib)))

IFLAGS:= $(DIRSRCS:%=-I%) $(DIRINCS:%=-I%) $(MODS:%=-I%) $(foreach lib, $(LIBS), $($(lib)INC:%=-I%))

# if MYSRCS is empty, it will be populated with all the .c files found in $DIRSRCS
ifeq ($(MYSRCS),)
MYSRCS:=$(wildcard $(DIRSRCS)/*.c)
else
MYSRCS:=$(MYSRCS:%.c=$(DIRSRCS)/%.c)
endif

# If, on a per module basis, MODSSRCS contains no .c file from the module, _all_ the
# module's .c files are then added to the sources list.
MODSSRCS:=$(MODSSRCS) $(foreach mod,$(MODS),$(if $(filter $(mod)/%.c, $(MODSSRCS)),,$(wildcard $(mod)/*.c)))
MYOBJS:=$(MYSRCS:%.c=%.o)
MODSOBJS:=$(MYSRCS:%.c=%.o)

define MOD_RULE
$(1):
	$(MAKE) -C $(1) $(patsubst $(1)/%.o,%.o,$(filter $(1)/%,$(MODSSRCS:%.c=%.o)))
endef

define LIB_RULE
$(1):
	$(CMAKE) -C $($(1)DIR)
endef

.PHONY:all
all: $(MYOBJS) $(MODS)

$(NAME): $(MYOBJS) $(MODS)
	$(CC) $(CFLAGS) $(LDLIBS) $(LFLAGS) $(OBJS) -c $@

$(DIRSRCS)/%.o: $(DIRSRCS)/%.c $(DIRDEPS)/%.d | $(DIRDEPS)
	$(CC) $(DFLAG) $(CPPFLAGS) $(CFLAGS) $(IFLAGS) -c $<

.PHONY:$(MODS)
$(foreach mod, $(MODS), $(eval $(call MOD_RULE,$(mod))))

$(DIRDEPS): ; mkdir -p $@

.PHONY:$(LIBS)
$(foreach lib, $(LIBS), $(eval $(call LIB_RULE,$(lib))))

.PHONY: clean
clean:
	rm -f $(MYOBJS) $(MODSOBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

DEP_FILES := $(MYSRCS:$(DIRSRCS)/%.c=$(DIRDEPS)/%.d)
$(DEP_FILES):
include $(wildcard $(DEP_FILES))
