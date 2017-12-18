# xbox-ctrl
Node api for the xbox controller

## Installation
As cli tool
```bash
$ [sudo] npm install xbox-ctrl -g
```

Programmatically
```bash
$ [sudo] npm install xbox-ctrl
```

## Usage
### CLI
```bash
$  xbox-ctrl 0.0.0 - Node api for the xbox controller
     
   USAGE

     xbox-ctrl <command> [options]

   COMMANDS

     off [controllers...]          Turn off controllers               
     vibrate [controllers...]      Vibrate controllers                
     list                          List connected controllers         
     help <command>                Display help for a specific command

   GLOBAL OPTIONS

     -h, --help         Display help                                      
     -V, --version      Display version                                   
     --no-color         Disable colors                                    
     --quiet            Quiet mode - only displays warn and error messages
     -v, --verbose      Verbose mode - will also output debug messages    


```
#### Synonym
This module is exported as `xbox-ctrl` and as `xctrl`.

### Programmatically
All the methods return a promise
```js
import {list, build, off, offAll, vibrate, vibrateAll} from 'xbox-ctrl';

// list connected controllers
list(); // => [0, 1]

// build a controller instance for every connected controller
build(); // => [new Controller(0), new Controller(1)]

// turns off controller 1
off(1);

// turns off all controllers
offAll();

// vibrate controller 1
vibrate(1);

// vibrate all controllers
vibrateAll();
```
#### Controller class
This module exports a `Controller` class as well
```js
import {Controller} from 'xbox-ctrl';

const controller = new Controller(1);

controller.vibrate();
controller.off();
```

#### Sync methods
Every method has a sync implementation as well, just add `Sync` to the method name

## License

[MIT](LICENSE) © [Noam Okman](https://github.com/noamokman)