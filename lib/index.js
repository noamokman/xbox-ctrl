import bindings from 'bindings';

const xinput = bindings('xinput');

/**
 * Turn off a controller by index
 * @param {Number} index - controller index from 1 to 4
 */
export function off (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  xinput.off(index);
}

/**
 * Turn off all controllers
 */
export function offAll () {
  xinput.offAll();
}

/**
 * Checks the connected controllers
 * @returns {[Number]} the connected controllers numbers
 */
export function list () {
  return xinput.list();
}

/**
 * Vibrate a controller by index
 * @param {Number} index - controller index from 1 to 4
 */
export function vibrate (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  xinput.vibrate(index);
}

/**
 * Vibrate all controllers
 */
export function vibrateAll () {
  xinput.vibrateAll();
}