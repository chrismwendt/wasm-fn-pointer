var Module = require('./a.out.js')

Module['onRuntimeInitialized'] = function() {
  const onResponse = Module.addFunction(function(response) {
    console.log('response (this should print \'hey\'):', response)
  }, ['string'])
  const lspLoop = Module.ccall('newLSPLoop', 'number', ['number'], [onResponse])
  Module.ccall('LSPLoop_send', null, ['number', 'string'], [lspLoop, 'hey'])
}
