const hello = require('./index.js');
const assert = require('assert');

assert.ok(hello, 'hello should be defined');
assert.ok(typeof hello.hello === 'function', 'hello should be a function');
assert.doesNotThrow(() => {
  hello.hello();
}, Error, 'hello should not throw an error');

assert.ok(typeof hello.add === 'function', 'add should be a function');
assert.doesNotThrow(() => {
  hello.add(1, 2);
}, Error, 'add should not throw an error');
assert.equal(hello.add(1, 2), 3, 'add should return 3');

assert.ok(typeof hello.fastSum === 'function', 'fastSum should be a function');
assert.doesNotThrow(() => {
  hello.fastSum(1000000);
}, Error, 'fastSum should not throw an error');
assert.equal(hello.fastSum(1000000), 1000000, 'fastSum should return 1000000');
