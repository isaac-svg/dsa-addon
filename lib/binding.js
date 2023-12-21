// const addon = require('../build/Release/dsa-native');
const addon = require("dsa")

function Dsa(name) {
    this.greet = function(str) {
        return _addonInstance.greet(str);
    }

    var _addonInstance = new addon.Dsa(name);
}

module.exports = Dsa;
