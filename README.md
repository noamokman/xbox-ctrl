# xbox-ctrl
Node api for the xbox controller

## Installation
As cli tool
``` bash
$ [sudo] npm install xbox-ctrl -g
```

Programmatically
``` bash
$ [sudo] npm install xbox-ctrl --save
```

## Usage
### CLI
#### Options
``` bash
$ xbox-ctrl --help
 
  Usage: xbox-ctrl <command>

  Commands:

    off [options] [controllers...]  Turn off controllers
    list                            List connected controllers

  Node api for the xbox controller

  Options:

    -h, --help     output usage information
    -V, --version  output the version number


```
#### Synonym
This module is exported as `xbox-ctrl` and as `xctrl`.

### Programmatically
#### Example
``` js
const xboxCtrl = require('xbox-ctrl');

// list connected controllers
xboxCtrl.list(); // => [1, 2]

// turns off controller 1
xboxCtrl.off(1);

// turns off all controllers
xboxCtrl.offAll();
```

## Run Tests
``` bash
$ npm test
```

## License

[MIT](LICENSE)
