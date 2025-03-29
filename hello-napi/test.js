const hello = require('./index.js');
const assert = require('assert');

assert.ok(hello, 'hello should be defined');
assert.ok(typeof hello.hello === 'function', 'hello should be a function');
assert.doesNotThrow(() => {
  hello.hello();
}, Error, 'hello should not throw an error');
