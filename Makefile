#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := PowerESP

include $(IDF_PATH)/make/project.mk

# cleans project using idf.py
peclean:
	./scripts/clean_esp32

# build using idf.py
pebuild:
	./scripts/build_esp32

# Runs the peclean and pebuild
cleanbuild:
	./scripts/cleanbuild_esp32

# Flash PowerESP(pe) onto esp32
peflash:
	./scripts/flash_esp32

# Same as peflash but runs cleanbuild before.
pecleanflash:
	./scripts/clean_esp32
	./scripts/flash_esp32

# sets up libraries
pesetuplibs:
	./scripts/setup_libraries

# installs the project for a machine/developer
pefullsetup:
	./scripts/clean_esp32
	./scripts/cleanup_libraries
	./scripts/setup_libraries
	./scripts/build_esp32