# About

This is just a proof-of-concept application that was created to try out the Reason + React Native combination. You can check how it turned out by [getting an iOS version from the app store](https://itunes.apple.com/us/app/brains-barcelona/id1431909667?ls=1&mt=8).

You can also clone the repository and play around with it on your computer, if you want to check how this technology works in practise. That's why we open sourced the code.

Just keep in mind that it's covered by a restrictive license and we don't give permission to copy our code directly, nor any images that we used. If you want a guide for your city, you'll need to put in some work ;)

Feel free to look around and ask us any questions you might have. You can [find the author on Twitter](https://twitter.com/sharnik), or spend 3 mins to get the email address ;)

# Development

To be able to play with the project in an iOS simulator, do the following:

```bash
yarn install # installs dependencies
yarn bs:watch # starts the Reason -> JS compiler in watch mode
yarn start # in a separate tab, runs React Native development server
react-native run-ios # builds the iOS app, starts a simulator and installs it
```

Enjoy!
