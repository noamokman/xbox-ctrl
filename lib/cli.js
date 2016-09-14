import program from 'commander';
import pkg from './../package.json';
import updateNotifier from 'update-notifier';
import inquirer from 'inquirer';
import {off, offAll, list, vibrate, vibrateAll} from './index';
const notifier = updateNotifier({pkg});

program
  .version(pkg.version)
  .description('Node api for the xbox controller')
  .usage('<command>');

program
  .command('off [controllers...]')
  .option('-a, --ask', 'Ask for the controller to turn off')
  .option('-m, --ask-many', 'Ask for multiple controllers to turn off')
  .description('Turn off controllers')
  .action((controllers, options) => {
    if (options.ask) {
      const availableControllers = list().map(x => ({name: x.toString(), value: x}));

      if (!availableControllers.length) {
        return console.log('There are no connected controllers');
      }

      return inquirer.prompt([
        {
          name: 'controller',
          message: 'Choose the controller to turn off:',
          type: 'list',
          choices: availableControllers
        }
      ])
        .then(({controller}) => off(controller));
    }

    if (options.askMany) {
      const availableControllers = list().map(x => ({name: x.toString(), value: x}));

      if (!availableControllers.length) {
        return console.log('There are no connected controllers');
      }

      return inquirer.prompt([
        {
          name: 'controllers',
          message: 'Choose the controllers to turn off:',
          type: 'checkbox',
          choices: availableControllers
        }
      ])
        .then(({controllers}) => controllers.forEach(off));
    }

    if (!controllers.length) {
      return offAll();
    }

    controllers.forEach(controller => {
      off(parseInt(controller, 10));
    });

    notifier.notify();
  });

program
  .command('vibrate [controllers...]')
  .option('-a, --ask', 'Ask for the controller to vibrate')
  .option('-m, --ask-many', 'Ask for multiple controllers to vibrate')
  .description('Vibrate controllers')
  .action((controllers, options) => {
    if (options.ask) {
      const availableControllers = list().map(x => ({name: x.toString(), value: x}));

      if (!availableControllers.length) {
        return console.log('There are no connected controllers');
      }

      return inquirer.prompt([
        {
          name: 'controller',
          message: 'Choose the controller to vibrate:',
          type: 'list',
          choices: availableControllers
        }
      ])
        .then(({controller}) => vibrate(controller));
    }

    if (options.askMany) {
      const availableControllers = list().map(x => ({name: x.toString(), value: x}));

      if (!availableControllers.length) {
        return console.log('There are no connected controllers');
      }

      return inquirer.prompt([
        {
          name: 'controllers',
          message: 'Choose the controllers to vibrate:',
          type: 'checkbox',
          choices: availableControllers
        }
      ])
        .then(({controllers}) => controllers.forEach(vibrate));
    }

    if (!controllers.length) {
      return vibrateAll();
    }

    controllers.forEach(controller => {
      vibrate(parseInt(controller, 10));
    });

    notifier.notify();
  });

program
  .command('list')
  .description('List connected controllers')
  .action(() => {
    const controllers = list();

    const message = !controllers.length ? 'There are no connected controllers' : `Currently connected controllers are: ${controllers.join(' ')}`;

    console.log(message);
    notifier.notify();
  });

/**
 * Handle cli arguments
 *
 * @param {string[]} argv - string array of the arguments
 */
export default function (argv) {
  program
    .parse(argv);

  if (argv.length <= 2) {
    program.help();
  }
}