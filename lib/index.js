import bindings from 'bindings';

const xboxCtrl = bindings('xboxCtrl');

/**
 * Turn off a controller by index
 * @param {Number} index - controller index from 1 to 4
 */
export function off (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  xboxCtrl.off(index);
}

/**
 * Turn off all controllers
 */
export function offAll () {
  xboxCtrl.offAll();
}

/**
 * Checks the connected controllers
 * @returns {[Number]} the connected controllers numbers
 */
export function list () {
  return xboxCtrl.list();
}

/**
 * Vibrate a controller by index
 * @param {Number} index - controller index from 1 to 4
 */
export function vibrate (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  xboxCtrl.vibrate(index);
}

/**
 * Vibrate all controllers
 */
export function vibrateAll () {
  xboxCtrl.vibrateAll();
}