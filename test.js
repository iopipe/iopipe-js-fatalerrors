const addon = require('./build/Release/addon');
addon.register();

/* Allocate a bit of memory */
var y;
for (var i = 0; ; i++) {
  y += "."
}
