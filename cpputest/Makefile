# we don’t want to use relative paths, so we set these variables
PROJECT_DIR=~/git/aerostitch/faa106d7534416c4dd9dc7e57dbfd209
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/cpputest
# specify where the source code and includes are located
INCLUDE_DIRS=$(SRC_DIR)
SRC_DIRS=$(SRC_DIR)

# specify where the test code is located
TEST_SRC_DIRS = $(TEST_DIR)

# what to call the test binary
TEST_TARGET=example

# where the cpputest library is located
CPPUTEST_HOME=/usr
TARGET_PLATFORM=x86_64-linux-gnu
CPPUTEST_SCRIPTS_HOME=/usr/share/cpputest
CPPUTEST_CPPFLAGS += -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
CPPUTEST_LDFLAGS += -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
CPPUTEST_USE_GCOV=Y

# run MakefileWorker.mk with the variables defined here
include MakefileWorker.mk
