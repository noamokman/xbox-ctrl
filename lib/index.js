import pify from 'pify';
import native from './native';
import Controller from './Controller';

const xboxCtrl = pify(native);

export {
  Controller
};

export function off (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  return xboxCtrl.off(index);
}

export function offAll () {
  return xboxCtrl.offAll();
}

export function offSync (index) {
  if (!Number.isInteger(index)) {
    throw new TypeError('index must be a number');
  }

  xboxCtrl.offSync(index);
}

export function offAllSync () {
  return xboxCtrl.offAllSync();
}

export function list () {
  return xboxCtrl.list();
}

export function listSync () {
  return xboxCtrl.listSync();
}

export function build () {
  return xboxCtrl.list()
    .then(indices => indices.map(index => new Controller(index)));
}

export function buildSync () {
  return xboxCtrl.listSync()
    .map(index => new Controller(index));
}

export function vibrate (index, sleep = 1000) {
  if (!Number.isInteger(index) || index < 0) {
    throw new TypeError('index must be a positive number');
  }

  if (!Number.isInteger(sleep) || sleep < 0) {
    throw new TypeError('sleep must be a positive number');
  }

  return xboxCtrl.vibrate(index, sleep);
}

export function vibrateAll (sleep = 1000) {
  return xboxCtrl.vibrateAll(sleep);
}

export function vibrateSync (index, sleep = 1000) {
  if (!Number.isInteger(index) || index < 0) {
    throw new TypeError('index must be a positive number');
  }

  if (!Number.isInteger(sleep) || sleep < 0) {
    throw new TypeError('sleep must be a positive number');
  }

  xboxCtrl.vibrateSync(index, sleep);
}

export function vibrateAllSync (sleep = 1000) {
  xboxCtrl.vibrateAllSync(sleep);
}