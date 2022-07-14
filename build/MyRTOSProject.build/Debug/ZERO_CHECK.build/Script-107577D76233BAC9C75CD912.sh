#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/thierry/Desktop/General-RTOS/build
  make -f /Users/thierry/Desktop/General-RTOS/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/thierry/Desktop/General-RTOS/build
  make -f /Users/thierry/Desktop/General-RTOS/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/thierry/Desktop/General-RTOS/build
  make -f /Users/thierry/Desktop/General-RTOS/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/thierry/Desktop/General-RTOS/build
  make -f /Users/thierry/Desktop/General-RTOS/build/CMakeScripts/ReRunCMake.make
fi

