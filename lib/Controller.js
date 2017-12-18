import xboxCtrl from './native';

export default class Controller {
  constructor (index) {
    if (!Number.isInteger(index)) {
      throw new TypeError('index must be a number');
    }

    this.index = index;
  }

  vibrate (sleep = 1000) {
    return xboxCtrl.vibrate(this.index, sleep);
  }

  off () {
    return xboxCtrl.off(this.index);
  }

  vibrateSync (sleep = 1000) {
    xboxCtrl.vibrateSync(this.index, sleep);
  }

  offSync () {
    xboxCtrl.offSync(this.index);
  }
}