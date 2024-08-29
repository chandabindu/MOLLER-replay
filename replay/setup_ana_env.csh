#!/bin/csh

## Setup your custom database directory
## Use: source setup_db.csh
#setenv MOLLER /w/halla-scshelf2102/moller12gev/chandan/sim/software/moller-tracking/install
#if(! ${?LD_LIBRARY_PATH}) then
#   setenv LD_LIBRARY_PATH /w/halla-scshelf2102/moller12gev/chandan/sim/software/SBS-offline/install/lib64
#else
#setenv LD_LIBRARY_PATH /w/halla-scshelf2102/moller12gev/chandan/sim/software/moller-tracking/install/lib64:${LD_LIBRARY_PATH}
#setenv LD_LIBRARY_PATH $MOLLER:${LD_LIBRARY_PATH}
#endif
#setenv MOLLER_REPLAY /w/halla-scshelf2102/moller12gev/chandan/sim/software/moller-tracking/replay
setenv DB_DIR $MOLLER_REPLAY/DB
setenv DATA_DIR /w/halla-scshelf2102/moller12gev/chandan/sim/data
setenv ANALYZER_CONFIGPATH $MOLLER_REPLAY/replay
setenv OUT_DIR $MOLLER_REPLAY/replay
setenv LOG_DIR $MOLLER_REPLAY/replay
