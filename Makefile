build:
	emcc a.cc \
	  -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "addFunction"]' \
	  -s EXPORTED_FUNCTIONS='["_newLSPLoop","_LSPLoop_send"]' \
	  -s RESERVED_FUNCTION_POINTERS=1

run:
	  node main.js
