import program, {BOOL} from 'caporal';
import updateNotifier from 'update-notifier';
import inquirer from 'inquirer';
import pTry from 'p-try';
import pkg from '../package.json';
import {off, offAll, list, vibrate, vibrateAll} from '.';

const notifier = updateNotifier({pkg});
const getControllerChoices = () => list()
  .then(controllers => controllers.map(id => ({
    name: (id + 1).toString(),
    value: id
  })));

program
  .version(pkg.version)
  .description(pkg.description)
  .command('off', 'Turn off controllers')
  .argument('[controllers...]', 'controllers ids')
  .option('-a, --ask', 'Ask for the controller to turn off', BOOL, false)
  .option('-m, --ask-many', 'Ask for multiple controllers to turn off', BOOL, false)
  .action(({controllers}, {ask, askMany}, logger) => pTry(() => {
    if (ask) {
      return getControllerChoices()
        .then(choices => {
          if (!choices.length) {
            logger.info('There are no connected controllers');

            return;
          }

          return inquirer.prompt([
            {
              name: 'controller',
              message: 'Choose the controller to turn off:',
              type: 'list',
              choices
            }
          ])
            .then(({controller}) => off(controller));
        });
    }

    if (askMany) {
      return getControllerChoices()
        .then(choices => {
          if (!choices.length) {
            logger.info('There are no connected controllers');

            return;
          }

          return inquirer.prompt([
            {
              name: 'controllers',
              message: 'Choose the controllers to turn off:',
              type: 'checkbox',
              choices
            }
          ])
            .then(({controllers}) => Promise.all(controllers.map(off)));
        });
    }

    if (!controllers.length) {
      return offAll();
    }

    return Promise.all(controllers.map(controller => off(parseInt(controller, 10) - 1)));
  })
    .then(() => notifier.notify())
    .catch(console.error))
  .command('vibrate', 'Vibrate controllers')
  .argument('[controllers...]', 'controllers ids')
  .option('-a, --ask', 'Ask for the controller to vibrate', BOOL, false)
  .action(({controllers}, {ask, askMany}, logger) => pTry(() => {
    if (ask) {
      return getControllerChoices()
        .then(choices => {
          if (!choices.length) {
            logger.info('There are no connected controllers');

            return;
          }

          return inquirer.prompt([
            {
              name: 'controller',
              message: 'Choose the controller to vibrate:',
              type: 'list',
              choices
            }
          ])
            .then(({controller}) => vibrate(controller));
        });
    }

    if (askMany) {
      return getControllerChoices()
        .then(choices => {
          if (!choices.length) {
            logger.info('There are no connected controllers');

            return;
          }

          return inquirer.prompt([
            {
              name: 'controllers',
              message: 'Choose the controllers to vibrate:',
              type: 'checkbox',
              choices
            }
          ])
            .then(({controllers}) => Promise.all(controllers.map(vibrate)));
        });
    }

    if (!controllers.length) {
      return vibrateAll();
    }

    return Promise.all(controllers.map(controller => vibrate(parseInt(controller, 10) - 1)));
  })
    .then(() => notifier.notify())
    .catch(console.error))
  .command('list', 'List connected controllers')
  .action((args, options, logger) => list()
    .then(controllers => {
      const message = !controllers.length ?
        'There are no connected controllers' :
        `Currently connected controllers are: ${controllers.map(index => index + 1).join(' ')}`;

      logger.info(message);
      notifier.notify();
    }));

/**
 * Handle cli arguments
 *
 * @param {string[]} argv - string array of the arguments
 */
export default argv => {
  program
    .parse(argv);
};