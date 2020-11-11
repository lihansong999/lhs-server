/*!
 * @nutui/nutui v2.2.11 - nutui.js, d62ca4dee823f5d9dfc4, Sun Sep 27 2020 20:44:34 GMT+0800 (GMT+08:00)
 * (c) 2017-2020 JDC
 * Released under the MIT License.
 */
(function webpackUniversalModuleDefinition(root, factory) {
	if(typeof exports === 'object' && typeof module === 'object')
		module.exports = factory(require("vue"));
	else if(typeof define === 'function' && define.amd)
		define("nutui", ["vue"], factory);
	else if(typeof exports === 'object')
		exports["nutui"] = factory(require("vue"));
	else
		root["nutui"] = factory(root["Vue"]);
})((typeof self !== 'undefined' ? self : this), function(__WEBPACK_EXTERNAL_MODULE__3__) {
return /******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, { enumerable: true, get: getter });
/******/ 		}
/******/ 	};
/******/
/******/ 	// define __esModule on exports
/******/ 	__webpack_require__.r = function(exports) {
/******/ 		if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 			Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 		}
/******/ 		Object.defineProperty(exports, '__esModule', { value: true });
/******/ 	};
/******/
/******/ 	// create a fake namespace object
/******/ 	// mode & 1: value is a module id, require it
/******/ 	// mode & 2: merge all properties of value into the ns
/******/ 	// mode & 4: return value when already ns object
/******/ 	// mode & 8|1: behave like require
/******/ 	__webpack_require__.t = function(value, mode) {
/******/ 		if(mode & 1) value = __webpack_require__(value);
/******/ 		if(mode & 8) return value;
/******/ 		if((mode & 4) && typeof value === 'object' && value && value.__esModule) return value;
/******/ 		var ns = Object.create(null);
/******/ 		__webpack_require__.r(ns);
/******/ 		Object.defineProperty(ns, 'default', { enumerable: true, value: value });
/******/ 		if(mode & 2 && typeof value != 'string') for(var key in value) __webpack_require__.d(ns, key, function(key) { return value[key]; }.bind(null, key));
/******/ 		return ns;
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "./";
/******/
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 122);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports, __webpack_require__) {

var arrayWithoutHoles = __webpack_require__(113);

var iterableToArray = __webpack_require__(114);

var unsupportedIterableToArray = __webpack_require__(27);

var nonIterableSpread = __webpack_require__(115);

function _toConsumableArray(arr) {
  return arrayWithoutHoles(arr) || iterableToArray(arr) || unsupportedIterableToArray(arr) || nonIterableSpread();
}

module.exports = _toConsumableArray;

/***/ }),
/* 1 */
/***/ (function(module, exports) {

function _defineProperty(obj, key, value) {
  if (key in obj) {
    Object.defineProperty(obj, key, {
      value: value,
      enumerable: true,
      configurable: true,
      writable: true
    });
  } else {
    obj[key] = value;
  }

  return obj;
}

module.exports = _defineProperty;

/***/ }),
/* 2 */
/***/ (function(module, exports) {

function _extends() {
  module.exports = _extends = Object.assign || function (target) {
    for (var i = 1; i < arguments.length; i++) {
      var source = arguments[i];

      for (var key in source) {
        if (Object.prototype.hasOwnProperty.call(source, key)) {
          target[key] = source[key];
        }
      }
    }

    return target;
  };

  return _extends.apply(this, arguments);
}

module.exports = _extends;

/***/ }),
/* 3 */
/***/ (function(module, exports) {

module.exports = __WEBPACK_EXTERNAL_MODULE__3__;

/***/ }),
/* 4 */
/***/ (function(module, exports) {

function _typeof(obj) {
  "@babel/helpers - typeof";

  if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") {
    module.exports = _typeof = function _typeof(obj) {
      return typeof obj;
    };
  } else {
    module.exports = _typeof = function _typeof(obj) {
      return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
    };
  }

  return _typeof(obj);
}

module.exports = _typeof;

/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

var arrayWithHoles = __webpack_require__(116);

var iterableToArrayLimit = __webpack_require__(117);

var unsupportedIterableToArray = __webpack_require__(27);

var nonIterableRest = __webpack_require__(118);

function _slicedToArray(arr, i) {
  return arrayWithHoles(arr) || iterableToArrayLimit(arr, i) || unsupportedIterableToArray(arr, i) || nonIterableRest();
}

module.exports = _slicedToArray;

/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 8 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 9 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 10 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 11 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 12 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 13 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 14 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 15 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(119);


/***/ }),
/* 16 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"13px\" height=\"13px\" viewBox=\"0 0 13 13\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <!-- Generator: Sketch 52.2 (67145) - http://www.bohemiancoding.com/sketch -->\n    <title>icon_address_black</title>\n    <desc>Created with Sketch.</desc>\n    <g id=\"搜索流程\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"3_搜索流程-copy\" transform=\"translate(-137.000000, -90.000000)\" fill=\"#333333\">\n            <g id=\"icon_address\" transform=\"translate(137.000000, 90.000000)\">\n                <g id=\"分组\">\n                    <path d=\"M8.84815,8.7378 C8.06565,9.3058 7.28265,9.8733 6.50015,10.4408 C5.71715,9.8733 4.93465,9.3058 4.15165,8.7378 C2.74865,7.7203 2.16065,5.9148 2.69565,4.2658 C3.23065,2.6168 4.76665,1.5003 6.50015,1.5003 C8.23365,1.5003 9.76965,2.6168 10.30465,4.2658 C10.83915,5.9148 10.25165,7.7203 8.84815,8.7378 M11.25565,3.9568 C10.58715,1.8958 8.66665,0.4998 6.50015,0.4998 C4.33315,0.4998 2.41315,1.8958 1.74415,3.9568 C1.07565,6.0183 1.81065,8.2753 3.56465,9.5478 C4.39665,10.1508 5.22815,10.7538 6.05965,11.3568 C6.32215,11.5478 6.67765,11.5478 6.94065,11.3568 C7.77215,10.7538 8.60365,10.1508 9.43515,9.5478 C11.18915,8.2753 11.92415,6.0183 11.25565,3.9568\" id=\"Fill-2\"></path>\n                    <path d=\"M7.9143,4.08595 C7.7188,3.89045 7.4023,3.89045 7.2068,4.08595 C7.0118,4.28145 7.0118,4.59745 7.2068,4.79295 C7.8373,5.42295 7.3908,6.49995 6.4998,6.49995 C5.6093,6.49995 5.1628,5.42295 5.7928,4.79295 C5.9878,4.59745 5.9878,4.28145 5.7928,4.08595 C5.5978,3.89045 5.2808,3.89045 5.0858,4.08595 C3.8258,5.34595 4.7183,7.49995 6.4998,7.49995 C8.2818,7.49995 9.1743,5.34595 7.9143,4.08595\" id=\"Fill-4\"></path>\n                    <path d=\"M8,12 L5,12 C4.724,12 4.5,12.2235 4.5,12.5 C4.5,12.7765 4.724,13 5,13 L8,13 C8.276,13 8.5,12.7765 8.5,12.5 C8.5,12.2235 8.276,12 8,12\" id=\"Fill-6\"></path>\n                </g>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 17 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"20px\" height=\"20px\" viewBox=\"0 0 20 20\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <!-- Generator: Sketch 59 (86127) - https://sketch.com -->\n    <title>back_original 2</title>\n    <desc>Created with Sketch.</desc>\n    <g id=\"地址选择\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"地址选择1\" transform=\"translate(-18.000000, -284.000000)\" fill=\"#333333\">\n            <g id=\"back_original-2\" transform=\"translate(18.000000, 284.000000)\">\n                <path d=\"M4,10.0009322 C3.99859741,10.5049575 4.39578918,10.8616307 4.4994895,10.9579412 L12.2671305,18.7441237 C12.6723966,19.0981592 13.322967,19.083897 13.7141881,18.7069986 C14.1081366,18.3274726 14.0918341,17.7356488 13.6838673,17.379254 L6.23965094,10.0009322 L13.6838673,2.62261026 C14.0891334,2.26857481 14.1054091,1.67176406 13.7141881,1.2948657 C13.3202395,0.915339684 12.6750973,0.901345866 12.2671305,1.25774058 L4.4994895,9.03838594 C4.40147558,9.15875944 4.00141004,9.49690678 4,10.0009322 Z\" id=\"back_original\"></path>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 18 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 30 30\"><path d=\"M30 15c0 8.285-6.716 15-15 15-8.284 0-15-6.715-15-15C0 6.716 6.716 0 15 0c8.284 0 15 6.716 15 15zM10.56 8.44a1.501 1.501 0 0 0-2.12 2.121l4.439 4.44-4.44 4.438a1.5 1.5 0 0 0 2.121 2.122l4.44-4.44 4.44 4.44a1.501 1.501 0 0 0 2.12-2.122l-11-11zm11 2.12a1.5 1.5 0 0 0-2.12-2.121l-2 2a1.5 1.5 0 0 0 2.12 2.122l2-2z\" fill-rule=\"evenodd\" fill-opacity=\".6\"/></svg>";

/***/ }),
/* 19 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"13px\" height=\"13px\" viewBox=\"0 0 13 13\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <!-- Generator: Sketch 52.2 (67145) - http://www.bohemiancoding.com/sketch -->\n    <title>Fill 3</title>\n    <desc>Created with Sketch.</desc>\n    <g id=\"地址选择\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"地址选择-已有地址\" transform=\"translate(-18.000000, -384.000000)\" fill=\"#F2270C\">\n            <g id=\"Fill-3\" transform=\"translate(18.000000, 384.000000)\">\n                <path d=\"M3.8235773,10.236 C2.6030773,9.113 1.3830773,7.9905 0.162577302,6.868 C-0.172922698,6.5595 0.0455773022,6 0.501077302,6 L1.0030773,6 C1.7555773,6 2.4800773,6.2825 3.0335773,6.792 C3.5180773,7.2375 4.0025773,7.6835 4.4870773,8.129 C5.9855773,6.6965 7.4835773,5.264 8.9820773,3.8315 C9.5400773,3.298 10.2825773,3 11.0545773,3 L11.4990773,3 C11.9500773,3 12.1705773,3.5495 11.8445773,3.861 C9.6265773,5.982 7.4090773,8.102 5.1910773,10.223 C4.7860773,10.6105 4.1415773,10.589 3.7625773,10.175 C3.7620773,10.1765 3.7615773,10.1775 3.7610773,10.1785\" id=\"Fill-2\"></path>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 20 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 16 4\"><rect x=\"14\" y=\"20\" width=\"16\" height=\"4\" rx=\"2\" transform=\"translate(-14 -20)\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 21 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 16 16\"><g fill-rule=\"evenodd\"><rect y=\"6\" width=\"16\" height=\"4\" rx=\"2\"/><rect transform=\"rotate(90 8 8)\" y=\"6\" width=\"16\" height=\"4\" rx=\"2\"/></g></svg>";

/***/ }),
/* 22 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"13px\" height=\"13px\" viewBox=\"0 0 13 13\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <!-- Generator: Sketch 52.2 (67145) - http://www.bohemiancoding.com/sketch -->\n    <title>Fill 3</title>\n    <desc>Created with Sketch.</desc>\n    <g id=\"分类\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"4-排序状态\" transform=\"translate(-18.000000, -296.000000)\" fill=\"#F2270C\">\n            <g id=\"分组-2-copy\" transform=\"translate(0.000000, 222.000000)\">\n                <g id=\"Fill-3\" transform=\"translate(18.000000, 74.000000)\">\n                    <path d=\"M3.8235773,10.236 C2.6030773,9.113 1.3830773,7.9905 0.162577302,6.868 C-0.172922698,6.5595 0.0455773022,6 0.501077302,6 L1.0030773,6 C1.7555773,6 2.4800773,6.2825 3.0335773,6.792 C3.5180773,7.2375 4.0025773,7.6835 4.4870773,8.129 C5.9855773,6.6965 7.4835773,5.264 8.9820773,3.8315 C9.5400773,3.298 10.2825773,3 11.0545773,3 L11.4990773,3 C11.9500773,3 12.1705773,3.5495 11.8445773,3.861 C9.6265773,5.982 7.4090773,8.102 5.1910773,10.223 C4.7860773,10.6105 4.1415773,10.589 3.7625773,10.175 C3.7620773,10.1765 3.7615773,10.1775 3.7610773,10.1785\" id=\"Fill-2\"></path>\n                </g>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 23 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 24 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 25 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 26 */
/***/ (function(module, exports) {

function _arrayLikeToArray(arr, len) {
  if (len == null || len > arr.length) len = arr.length;

  for (var i = 0, arr2 = new Array(len); i < len; i++) {
    arr2[i] = arr[i];
  }

  return arr2;
}

module.exports = _arrayLikeToArray;

/***/ }),
/* 27 */
/***/ (function(module, exports, __webpack_require__) {

var arrayLikeToArray = __webpack_require__(26);

function _unsupportedIterableToArray(o, minLen) {
  if (!o) return;
  if (typeof o === "string") return arrayLikeToArray(o, minLen);
  var n = Object.prototype.toString.call(o).slice(8, -1);
  if (n === "Object" && o.constructor) n = o.constructor.name;
  if (n === "Map" || n === "Set") return Array.from(o);
  if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return arrayLikeToArray(o, minLen);
}

module.exports = _unsupportedIterableToArray;

/***/ }),
/* 28 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 29 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 30 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 31 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 32 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 33 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 34 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 35 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 36 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 37 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 38 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 39 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 40 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 41 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 42 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 43 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 44 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 45 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 46 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 47 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 48 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 49 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 50 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 51 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 52 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 53 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 54 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 55 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 56 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 57 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 58 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 59 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 60 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 61 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 62 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 63 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 64 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 65 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 66 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 67 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 68 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 69 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 70 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 71 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 72 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 73 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 74 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 75 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 76 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 77 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 78 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 79 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 80 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 81 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 82 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 83 */
/***/ (function(module) {

module.exports = JSON.parse("{\"a\":\"2.2.11\"}");

/***/ }),
/* 84 */
/***/ (function(module) {

module.exports = JSON.parse("{\"a\":[{\"name\":\"Cell\",\"version\":\"1.0.0\",\"sort\":\"4\",\"chnName\":\"列表项\",\"type\":\"component\",\"showDemo\":true,\"desc\":\"列表项，可组合成列表\",\"author\":\"Frans、玉磊\"},{\"name\":\"Dialog\",\"version\":\"1.0.0\",\"sort\":\"2\",\"chnName\":\"对话框\",\"type\":\"method\",\"showDemo\":true,\"desc\":\"模态弹窗，支持按钮交互，支持图片弹窗。\",\"star\":5,\"author\":\"Frans、肖晓\"},{\"name\":\"Icon\",\"version\":\"1.0.0\",\"sort\":\"5\",\"chnName\":\"图标\",\"type\":\"component\",\"showDemo\":true,\"desc\":\"网页小图标。\",\"author\":\"Frans\"},{\"version\":\"1.0.0\",\"name\":\"Toast\",\"sort\":\"2\",\"chnName\":\"吐司\",\"desc\":\"轻提示。\",\"type\":\"method\",\"showDemo\":true,\"star\":4,\"author\":\"Frans、张宇\"},{\"version\":\"1.0.0\",\"name\":\"ActionSheet\",\"sort\":\"2\",\"chnName\":\"动作面板\",\"desc\":\"从底部弹出的动作菜单面板。\",\"type\":\"component\",\"showDemo\":true,\"star\":5,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"Tab\",\"sort\":\"3\",\"chnName\":\"选项卡\",\"desc\":\"常用于平级区域大块内容的的收纳和展现。\",\"type\":\"component\",\"showDemo\":true,\"star\":3,\"author\":\"甄玉磊\"},{\"version\":\"1.0.0\",\"name\":\"TabPanel\",\"sort\":\"3\",\"chnName\":\"选项卡\",\"desc\":\"标签栏 选项卡组件\",\"type\":\"component\",\"showDemo\":false,\"author\":\"甄玉磊\"},{\"version\":\"1.0.0\",\"name\":\"TabBar\",\"sort\":\"3\",\"chnName\":\"标签栏\",\"desc\":\"用于不同模块以之间的切换\",\"type\":\"component\",\"showDemo\":true,\"star\":3,\"author\":\"甄玉磊\"},{\"version\":\"1.0.0\",\"name\":\"Calendar\",\"sort\":\"1\",\"chnName\":\"日历\",\"desc\":\"日历\",\"type\":\"component\",\"showDemo\":true,\"star\":5,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"DatePicker\",\"sort\":\"1\",\"chnName\":\"日期选择\",\"desc\":\"日期选择\",\"type\":\"component\",\"showDemo\":true,\"star\":5,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"NavBar\",\"sort\":\"3\",\"chnName\":\"导航栏\",\"desc\":\"移动端头部导航栏\",\"type\":\"component\",\"showDemo\":true,\"author\":\"lishaoqi\"},{\"version\":\"1.0.0\",\"name\":\"NoticeBar\",\"sort\":\"3\",\"chnName\":\"公告栏\",\"desc\":\"移动端公告栏\",\"type\":\"component\",\"showDemo\":true,\"author\":\"wangyue\"},{\"name\":\"Switch\",\"version\":\"1.0.0\",\"sort\":\"1\",\"chnName\":\"开关\",\"type\":\"component\",\"showDemo\":true,\"desc\":\"滑动开关，通过点击使按钮左右滑动，同时触发对应的开关状态\",\"author\":\"Frans\"},{\"version\":\"1.0.0\",\"name\":\"Slider\",\"sort\":\"1\",\"chnName\":\"滑块\",\"desc\":\"滑动输入器，用于在数值区间/自定义区间内进行选择。\",\"type\":\"component\",\"showDemo\":true,\"star\":4,\"author\":\"Frans\"},{\"version\":\"1.0.0\",\"name\":\"Range\",\"sort\":\"1\",\"chnName\":\"区间选择器\",\"desc\":\"区间选择器组件\",\"type\":\"component\",\"showDemo\":true,\"star\":4,\"author\":\"famanoder\"},{\"version\":\"1.0.0\",\"name\":\"Picker\",\"sort\":\"1\",\"chnName\":\"拾取器\",\"desc\":\"提供多个选项集合供用户选择其中一项。\",\"type\":\"component\",\"showDemo\":true,\"star\":5,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"Progress\",\"sort\":\"2\",\"chnName\":\"进度条\",\"desc\":\"展示操作或任务的当前进度，比如上传文件。\",\"type\":\"component\",\"showDemo\":true,\"author\":\"张毓飞\"},{\"version\":\"1.0.0\",\"name\":\"Price\",\"sort\":\"0\",\"chnName\":\"商品价格\",\"desc\":\"商品价格组件，支持小数点前后应用不同样式、千位分隔、人民币符号等功能\",\"type\":\"component\",\"showDemo\":true,\"author\":\"liaoyanli5\"},{\"version\":\"1.0.0\",\"name\":\"Flex\",\"sort\":\"4\",\"chnName\":\"Flex布局\",\"desc\":\"Flex布局速简便地创建布局\",\"type\":\"component\",\"showDemo\":true,\"author\":\"秦伟伟,苏子刚\"},{\"version\":\"1.0.0\",\"name\":\"Col\",\"sort\":\"4\",\"chnName\":\"Flex布局\",\"desc\":\"Flex布局速简便地创建布局\",\"type\":\"component\",\"showDemo\":false,\"author\":\"秦伟伟,苏子刚\"},{\"version\":\"1.0.0\",\"name\":\"Row\",\"sort\":\"4\",\"chnName\":\"Flex布局\",\"desc\":\"Flex布局速简便地创建布局\",\"type\":\"component\",\"showDemo\":false,\"author\":\"秦伟伟,苏子刚\"},{\"version\":\"1.0.0\",\"name\":\"Steps\",\"sort\":\"0\",\"chnName\":\"步骤条\",\"desc\":\"拆分展示某项流程的步骤，引导用户按流程完成任务或向用户展示当前状态。\",\"type\":\"component\",\"showDemo\":true,\"author\":\"宋其斌\"},{\"version\":\"1.0.0\",\"name\":\"Button\",\"sort\":\"5\",\"chnName\":\"按钮\",\"desc\":\"各式各样的按钮\",\"type\":\"component\",\"showDemo\":true,\"author\":\"杨磊\"},{\"version\":\"1.0.0\",\"name\":\"Badge\",\"sort\":\"0\",\"chnName\":\"徽标\",\"desc\":\"出现在图标或文字右上角的红色圆点、数字或者文字，表示有新内容或者待处理的信息\",\"type\":\"component\",\"showDemo\":true,\"author\":\"杨磊\"},{\"version\":\"1.0.0\",\"name\":\"Rate\",\"sort\":\"1\",\"chnName\":\"评分\",\"desc\":\"用于快速的评级操作，或对评价进行展示。\",\"type\":\"component\",\"showDemo\":true,\"star\":4,\"author\":\"永无止晋\"},{\"version\":\"1.0.1\",\"name\":\"Swiper\",\"chnName\":\"滑动切换\",\"sort\":\"0\",\"desc\":\"常用于一组图片或卡片轮播，当内容空间不足时，可以用走马灯的形式进行收纳，进行轮播展现。\",\"type\":\"component\",\"showDemo\":true,\"star\":5,\"author\":\"wangnan31\"},{\"version\":\"1.0.0\",\"name\":\"Menu\",\"sort\":\"3\",\"chnName\":\"菜单\",\"desc\":\"菜单\",\"type\":\"component\",\"showDemo\":true,\"author\":\"苏子刚\"},{\"version\":\"1.0.0\",\"name\":\"Stepper\",\"chnName\":\"步进器\",\"desc\":\"通过点击按钮控制数字加减\",\"type\":\"component\",\"sort\":\"1\",\"showDemo\":true,\"star\":3,\"author\":\"famanoder\"},{\"version\":\"1.0.0\",\"name\":\"ButtonGroup\",\"chnName\":\"按钮组\",\"desc\":\"用于页面底部的按钮组\",\"type\":\"component\",\"sort\":\"5\",\"showDemo\":true,\"author\":\"杨磊\"},{\"version\":\"1.0.0\",\"name\":\"SearchBar\",\"chnName\":\"搜索栏\",\"desc\":\"搜索栏\",\"type\":\"component\",\"sort\":\"1\",\"showDemo\":true,\"author\":\"lemon\"},{\"version\":\"1.0.0\",\"name\":\"ImagePicker\",\"sort\":\"1\",\"chnName\":\"图片选择器\",\"desc\":\"图片选择器\",\"type\":\"component\",\"showDemo\":true,\"author\":\"苏子刚\"},{\"name\":\"Radio\",\"version\":\"1.0.0\",\"sort\":\"1\",\"chnName\":\"单选按钮\",\"type\":\"component\",\"showDemo\":true,\"desc\":\"单选按钮，可组合成单选按钮组\",\"author\":\"Frans\"},{\"name\":\"RadioGroup\",\"version\":\"1.0.0\",\"sort\":\"1\",\"chnName\":\"单选按钮组\",\"type\":\"component\",\"showDemo\":false,\"desc\":\"单选按钮组\",\"author\":\"Frans\"},{\"version\":\"1.0.0\",\"name\":\"CheckBox\",\"sort\":\"1\",\"chnName\":\"复选按钮\",\"desc\":\"复选多个选项\",\"type\":\"component\",\"showDemo\":true,\"author\":\"Vicky.Ye\"},{\"version\":\"1.0.0\",\"name\":\"CheckBoxGroup\",\"sort\":\"1\",\"chnName\":\"复选按钮组\",\"desc\":\"成组出现的复选按钮组件\",\"type\":\"component\",\"showDemo\":true,\"author\":\"Vicky.Ye\"},{\"version\":\"1.0.0\",\"name\":\"ShortPassword\",\"chnName\":\"短密码\",\"des\":\"短密码\",\"type\":\"component\",\"sort\":\"1\",\"showDemo\":true,\"author\":\"wangnan31\"},{\"version\":\"1.0.0\",\"name\":\"Skeleton\",\"chnName\":\"骨架屏\",\"des\":\"在页面上待加载区域填充灰色的占位图，本质上是界面加载过程中的过渡效果\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"wangnan31\"},{\"version\":\"1.0.0\",\"name\":\"Scroller\",\"chnName\":\"滚动\",\"desc\":\"滚动组件\",\"type\":\"component\",\"sort\":\"0\",\"star\":5,\"showDemo\":true,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"BackTop\",\"chnName\":\"回到顶部\",\"desc\":\"用于页面内容高度过长，快捷回到顶部使用。\",\"type\":\"component\",\"sort\":\"2\",\"showDemo\":true,\"author\":\"永无止晋、richard1015\"},{\"version\":\"1.0.0\",\"name\":\"CountDown\",\"chnName\":\"倒计时\",\"desc\":\"倒计时组件\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"famanoder\"},{\"version\":\"1.0.0\",\"name\":\"InfiniteLoading\",\"chnName\":\"无限加载\",\"desc\":\"无限加载\",\"type\":\"component\",\"sort\":\"0\",\"star\":4,\"showDemo\":true,\"author\":\"iris\"},{\"version\":\"1.0.0\",\"name\":\"Uploader\",\"chnName\":\"上传\",\"desc\":\"文件上传组件\",\"type\":\"component\",\"sort\":\"5\",\"showDemo\":true,\"author\":\"林如风\"},{\"version\":\"1.0.0\",\"name\":\"TextInput\",\"chnName\":\"文本框\",\"desc\":\"单行文本框\",\"type\":\"component\",\"sort\":\"1\",\"showDemo\":true,\"author\":\"Frans\"},{\"version\":\"1.0.0\",\"name\":\"Avatar\",\"chnName\":\"头像\",\"desc\":\"用来表示用户或事物，支持图片或字符展示。\",\"type\":\"component\",\"sort\":\"5\",\"showDemo\":true,\"author\":\"zhenyulei\"},{\"version\":\"1.0.0\",\"name\":\"Lazyload\",\"chnName\":\"图片懒加载\",\"desc\":\"图片懒加载\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"richard1015\"},{\"version\":\"1.0.0\",\"name\":\"TextBox\",\"chnName\":\"文本域\",\"desc\":\"文本域\",\"type\":\"component\",\"sort\":\"1\",\"showDemo\":true,\"author\":\"guoxiaoxiao\"},{\"version\":\"1.0.0\",\"name\":\"Elevator\",\"chnName\":\"电梯楼层\",\"desc\":\"类似于电梯楼层，组件可以跟着右侧索引而滑动\",\"type\":\"component\",\"sort\":\"3\",\"showDemo\":true,\"author\":\"zhenyulei\"},{\"version\":\"1.0.0\",\"name\":\"Popup\",\"chnName\":\"弹出层\",\"desc\":\"弹出层\",\"type\":\"component\",\"sort\":\"5\",\"showDemo\":true,\"author\":\"杨凯旋\"},{\"version\":\"1.0.0\",\"name\":\"LeftSlip\",\"chnName\":\"左滑删除\",\"desc\":\"手势左滑删除元素\",\"type\":\"component\",\"sort\":\"2\",\"showDemo\":true,\"author\":\"vickyYE\"},{\"version\":\"1.0.0\",\"name\":\"TabSelect\",\"chnName\":\"配送时间\",\"desc\":\"两级配送时间\",\"type\":\"component\",\"sort\":\"6\",\"showDemo\":true,\"author\":\"dsj\"},{\"version\":\"1.0.0\",\"name\":\"LuckDraw\",\"chnName\":\"转盘抽奖\",\"desc\":\"可设置中奖奖品，转动时间，中奖标识等\",\"type\":\"component\",\"sort\":\"6\",\"showDemo\":true,\"author\":\"Ymm0008\"},{\"version\":\"1.0.0\",\"name\":\"Video\",\"chnName\":\"视频\",\"desc\":\"视频播放器\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"VickyYe\"},{\"version\":\"1.0.0\",\"name\":\"Signature\",\"chnName\":\"签名\",\"desc\":\"签名\",\"type\":\"component\",\"sort\":\"6\",\"showDemo\":true,\"author\":\"irisSong\"},{\"version\":\"1.0.0\",\"name\":\"CircleProgress\",\"chnName\":\"圆形进度条\",\"desc\":\"显示当前任务的操作进度\",\"type\":\"component\",\"sort\":\"2\",\"showDemo\":true,\"author\":\"zyf\"},{\"version\":\"1.0.0\",\"name\":\"TimeLineItem\",\"chnName\":\"时间轴节点\",\"desc\":\"定义时间轴节点\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":false,\"author\":\"yangxiaolu\"},{\"version\":\"1.0.0\",\"name\":\"TimeLine\",\"chnName\":\"时间轴节点\",\"desc\":\"定义时间轴节点\",\"type\":\"component\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"yangxiaolu\"},{\"version\":\"1.0.0\",\"name\":\"SideNavBar\",\"chnName\":\"侧边栏导航\",\"desc\":\"侧边栏导航\",\"type\":\"component\",\"sort\":\"3\",\"showDemo\":true,\"author\":\"szg2008\"},{\"version\":\"1.0.0\",\"name\":\"SubSideNavBar\",\"chnName\":\"侧边栏导航\",\"desc\":\"侧边栏导航\",\"type\":\"component\",\"sort\":\"3\",\"showDemo\":false,\"author\":\"szg2008\"},{\"version\":\"1.0.0\",\"name\":\"SideNavBarItem\",\"chnName\":\"侧边栏导航\",\"desc\":\"侧边栏导航\",\"type\":\"component\",\"sort\":\"3\",\"showDemo\":false,\"author\":\"szg2008\"},{\"name\":\"Drag\",\"chnName\":\"拖拽\",\"desc\":\"实现可拖拽的任意元素\",\"type\":\"component\",\"sort\":\"5\",\"showDemo\":true,\"author\":\"张宇\"},{\"version\":\"1.0.0\",\"name\":\"Address\",\"chnName\":\"地址选择\",\"desc\":\"业务功能-地址选择\",\"type\":\"component\",\"sort\":\"6\",\"showDemo\":true,\"author\":\"yangxiaolu\"},{\"version\":\"1.0.0\",\"name\":\"Notify\",\"type\":\"method\",\"chnName\":\"展示消息提示\",\"desc\":\"在页面顶部展示消息提示，支持函数调用和组件调用两种方式\",\"sort\":\"2\",\"showDemo\":true,\"author\":\"wangyue217\"},{\"name\":\"CountUp\",\"type\":\"component\",\"chnName\":\"数字滚动\",\"desc\":\"用于数据展示\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"Ymm0008\"},{\"name\":\"FixedNav\",\"type\":\"component\",\"chnName\":\"悬浮导航\",\"desc\":\"拖拽导航\",\"sort\":\"3\",\"showDemo\":true,\"author\":\"richard1015\"},{\"version\":\"1.0.0\",\"name\":\"Collapse\",\"type\":\"component\",\"chnName\":\"折叠面板\",\"desc\":\"可以折叠/展开的内容区域\",\"sort\":\"0\",\"showDemo\":true,\"author\":\"Ymm0008\",\"showTest\":true},{\"version\":\"1.0.0\",\"name\":\"Luckycard\",\"type\":\"component\",\"chnName\":\"刮刮卡\",\"desc\":\"挂挂卡抽奖\",\"sort\":\"6\",\"showDemo\":true,\"author\":\"guoxiao\"},{\"version\":\"1.0.0\",\"name\":\"NumberKeyboard\",\"type\":\"component\",\"chnName\":\"数字键盘\",\"desc\":\"数字虚拟键盘，自定义键盘\",\"sort\":\"1\",\"showDemo\":true,\"author\":\"Ymm0008\",\"showTest\":true}]}");

/***/ }),
/* 85 */
/***/ (function(module, exports) {

function asyncGeneratorStep(gen, resolve, reject, _next, _throw, key, arg) {
  try {
    var info = gen[key](arg);
    var value = info.value;
  } catch (error) {
    reject(error);
    return;
  }

  if (info.done) {
    resolve(value);
  } else {
    Promise.resolve(value).then(_next, _throw);
  }
}

function _asyncToGenerator(fn) {
  return function () {
    var self = this,
        args = arguments;
    return new Promise(function (resolve, reject) {
      var gen = fn.apply(self, args);

      function _next(value) {
        asyncGeneratorStep(gen, resolve, reject, _next, _throw, "next", value);
      }

      function _throw(err) {
        asyncGeneratorStep(gen, resolve, reject, _next, _throw, "throw", err);
      }

      _next(undefined);
    });
  };
}

module.exports = _asyncToGenerator;

/***/ }),
/* 86 */
/***/ (function(module, exports) {

function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

module.exports = _classCallCheck;

/***/ }),
/* 87 */
/***/ (function(module, exports) {

function _defineProperties(target, props) {
  for (var i = 0; i < props.length; i++) {
    var descriptor = props[i];
    descriptor.enumerable = descriptor.enumerable || false;
    descriptor.configurable = true;
    if ("value" in descriptor) descriptor.writable = true;
    Object.defineProperty(target, descriptor.key, descriptor);
  }
}

function _createClass(Constructor, protoProps, staticProps) {
  if (protoProps) _defineProperties(Constructor.prototype, protoProps);
  if (staticProps) _defineProperties(Constructor, staticProps);
  return Constructor;
}

module.exports = _createClass;

/***/ }),
/* 88 */
/***/ (function(module, exports, __webpack_require__) {

var map = {
	"./action.svg": 89,
	"./address-location.svg": 16,
	"./arrow-to-left.svg": 90,
	"./arrow-to-top.svg": 91,
	"./arrows-back.svg": 17,
	"./back.svg": 92,
	"./checked.svg": 93,
	"./checked2.svg": 94,
	"./circle-cross.svg": 18,
	"./close.svg": 95,
	"./cross.svg": 96,
	"./down.svg": 97,
	"./github.svg": 98,
	"./hook-red.svg": 19,
	"./message.svg": 99,
	"./minus.svg": 20,
	"./more.svg": 100,
	"./more2.svg": 101,
	"./more3.svg": 102,
	"./notice.svg": 103,
	"./plus.svg": 21,
	"./qrcode.svg": 104,
	"./right.svg": 105,
	"./search.svg": 106,
	"./search2.svg": 107,
	"./share.svg": 108,
	"./tick-red.svg": 22,
	"./tick.svg": 109,
	"./top.svg": 110,
	"./trolley.svg": 111,
	"./unchecked.svg": 112
};


function webpackContext(req) {
	var id = webpackContextResolve(req);
	return __webpack_require__(id);
}
function webpackContextResolve(req) {
	if(!__webpack_require__.o(map, req)) {
		var e = new Error("Cannot find module '" + req + "'");
		e.code = 'MODULE_NOT_FOUND';
		throw e;
	}
	return map[req];
}
webpackContext.keys = function webpackContextKeys() {
	return Object.keys(map);
};
webpackContext.resolve = webpackContextResolve;
module.exports = webpackContext;
webpackContext.id = 88;

/***/ }),
/* 89 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 24 24\"><g fill-rule=\"evenodd\"><path d=\"M.5 12c0 6.351 5.149 11.5 11.5 11.5S23.5 18.351 23.5 12 18.351.5 12 .5.5 5.649.5 12z\" stroke-opacity=\".6\" stroke=\"currentColor\" fill=\"#FFF\"/><path d=\"M10.909 4.364h2.182v2.182h-2.182zM10.909 8.727h2.182v10.909h-2.182z\"/></g></svg>";

/***/ }),
/* 90 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"19\" height=\"36\" xmlns=\"http://www.w3.org/2000/svg\"><path d=\"M18.552 35.569a1.5 1.5 0 0 1-2.121-.017c-5.952-6.05-9.905-10.1-15.857-16.15a2 2 0 0 1 0-2.804c5.952-6.05 9.905-10.1 15.857-16.15a1.5 1.5 0 1 1 2.138 2.104C12.847 8.368 9.125 12.184 3.403 18c5.722 5.816 9.444 9.632 15.166 15.448a1.5 1.5 0 0 1-.017 2.121z\" fill=\"#2E2D2D\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 91 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 31 39\"><g fill-rule=\"evenodd\"><path d=\"M1.41 0C.63 0 0 .672 0 1.5S.63 3 1.41 3h28.18C30.37 3 31 2.328 31 1.5S30.369 0 29.59 0H1.41zM17 7.5a1.5 1.5 0 0 0-3 0v30a1.5 1.5 0 1 0 3 0v-30zM8.44 12.44l-8 8a1.5 1.5 0 1 0 2.12 2.12l8-8a1.5 1.5 0 1 0-2.12-2.12z\"/><path d=\"M16.56 6.44l14 14a1.5 1.5 0 1 1-2.12 2.12l-14-14a1.5 1.5 0 1 1 2.12-2.12z\"/></g></svg>";

/***/ }),
/* 92 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"20px\" height=\"20px\" viewBox=\"0 0 20 20\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <!-- Generator: Sketch 59 (86127) - https://sketch.com -->\n    <title>back_original 2</title>\n    <desc>Created with Sketch.</desc>\n    <g id=\"地址选择\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"地址选择1\" transform=\"translate(-18.000000, -284.000000)\" fill=\"#333333\">\n            <g id=\"back_original-2\" transform=\"translate(18.000000, 284.000000)\">\n                <path d=\"M4,10.0009322 C3.99859741,10.5049575 4.39578918,10.8616307 4.4994895,10.9579412 L12.2671305,18.7441237 C12.6723966,19.0981592 13.322967,19.083897 13.7141881,18.7069986 C14.1081366,18.3274726 14.0918341,17.7356488 13.6838673,17.379254 L6.23965094,10.0009322 L13.6838673,2.62261026 C14.0891334,2.26857481 14.1054091,1.67176406 13.7141881,1.2948657 C13.3202395,0.915339684 12.6750973,0.901345866 12.2671305,1.25774058 L4.4994895,9.03838594 C4.40147558,9.15875944 4.00141004,9.49690678 4,10.0009322 Z\" id=\"back_original\"></path>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 93 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" viewBox=\"0 0 50 50\"><defs><path d=\"M38 19C38 8.507 29.493 0 19 0S0 8.507 0 19s8.507 19 19 19 19-8.507 19-19\" id=\"b\"/><filter x=\"-28.9%\" y=\"-18.4%\" width=\"157.9%\" height=\"157.9%\" filterUnits=\"objectBoundingBox\" id=\"a\"><feOffset dy=\"4\" in=\"SourceAlpha\" result=\"shadowOffsetOuter1\"/><feGaussianBlur stdDeviation=\"3\" in=\"shadowOffsetOuter1\" result=\"shadowBlurOuter1\"/><feColorMatrix values=\"0 0 0 0 0.941176471 0 0 0 0 0.145098039 0 0 0 0 0.0588235294 0 0 0 0.15 0\" in=\"shadowBlurOuter1\"/></filter></defs><g fill=\"none\" fill-rule=\"evenodd\"><g transform=\"translate(6 2)\"><use fill=\"#000\" filter=\"url(#a)\" xlink:href=\"#b\"/><use fill=\"#F0250F\" xlink:href=\"#b\"/></g><path d=\"M16 31h20V11H16z\"/><path fill=\"#FFF\" d=\"M16 21l2.5-2.5 5 4.5 10-9.5L36 16 24 28h-1z\"/></g></svg>";

/***/ }),
/* 94 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" viewBox=\"0 0 50 50\"><defs><path d=\"M19 0C8.506 0 0 8.506 0 19s8.506 19 19 19 19-8.506 19-19S29.494 0 19 0z\" id=\"b\"/><filter x=\"-28.9%\" y=\"-18.4%\" width=\"157.9%\" height=\"157.9%\" filterUnits=\"objectBoundingBox\" id=\"a\"><feOffset dy=\"4\" in=\"SourceAlpha\" result=\"shadowOffsetOuter1\"/><feGaussianBlur stdDeviation=\"3\" in=\"shadowOffsetOuter1\" result=\"shadowBlurOuter1\"/><feComposite in=\"shadowBlurOuter1\" in2=\"SourceAlpha\" operator=\"out\" result=\"shadowBlurOuter1\"/><feColorMatrix values=\"0 0 0 0 0.941176471 0 0 0 0 0.145098039 0 0 0 0 0.0588235294 0 0 0 0.15 0\" in=\"shadowBlurOuter1\"/></filter></defs><g fill-rule=\"evenodd\"><g transform=\"translate(6 2)\"><use fill=\"#000\" filter=\"url(#a)\" xlink:href=\"#b\"/><path stroke=\"#F0250F\" stroke-width=\"3\" d=\"M19 1.5C9.335 1.5 1.5 9.335 1.5 19S9.335 36.5 19 36.5 36.5 28.665 36.5 19 28.665 1.5 19 1.5z\" stroke-linejoin=\"square\" fill=\"#FFF\"/></g><path d=\"M37 21c0-6.627-5.373-12-12-12s-12 5.373-12 12 5.373 12 12 12 12-5.373 12-12\" fill=\"#F0250F\"/></g></svg>";

/***/ }),
/* 95 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"20px\" height=\"20px\" viewBox=\"0 0 20 20\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n    <title>btn_close</title>\n    <g id=\"页面-1\" stroke=\"none\" stroke-width=\"1\" fill=\"none\" fill-rule=\"evenodd\">\n        <g id=\"4_商品详情页-赠品\" transform=\"translate(-337.000000, -305.000000)\">\n            <g id=\"弹层\" transform=\"translate(0.000000, 287.000000)\">\n                <g id=\"关闭\" transform=\"translate(337.000000, 18.000000)\">\n                    <circle id=\"椭圆形\" fill=\"#F2F2F2\" cx=\"10\" cy=\"10\" r=\"10\"></circle>\n                    <path d=\"M12.2803,8.7803 C11.9873,9.0733 11.5128,9.0733 11.2198,8.7803 C10.9268,8.4878 10.9268,8.0128 11.2198,7.7198 L12.7198,6.2198 C13.0128,5.9268 13.4873,5.9268 13.7803,6.2198 C14.0733,6.5123 14.0733,6.9878 13.7803,7.2803 L12.2803,8.7803 Z\" id=\"Fill-5\" fill=\"#8C8C8C\"></path>\n                    <path d=\"M13.7803,12.71975 C14.0733,13.01225 14.0733,13.48775 13.7803,13.78025 C13.4873,14.07325 13.0128,14.07325 12.7198,13.78025 C11.8128,12.87375 10.9068,11.96725 9.9998,11.06075 C9.0933,11.96725 8.1868,12.87375 7.2803,13.78025 C6.9873,14.07325 6.5128,14.07325 6.2198,13.78025 C5.9268,13.48775 5.9268,13.01225 6.2198,12.71975 C7.1263,11.81325 8.0328,10.90675 8.9393,10.00025 C8.0328,9.09375 7.1263,8.18725 6.2198,7.28025 C5.9268,6.98775 5.9268,6.51225 6.2198,6.21975 C6.5128,5.92675 6.9873,5.92675 7.2803,6.21975 C9.4468,8.38625 11.6138,10.55325 13.7803,12.71975\" id=\"Fill-8\" fill=\"#8C8C8C\"></path>\n                </g>\n            </g>\n        </g>\n    </g>\n</svg>";

/***/ }),
/* 96 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 30 30\"><g fill-rule=\"evenodd\"><path d=\"M.44 2.56A1.5 1.5 0 1 1 2.56.44l27 27a1.5 1.5 0 1 1-2.12 2.12L15 17.123 2.56 29.56A1.5 1.5 0 1 1 .44 27.44L12.878 15 .44 2.56zM27.44.44a1.5 1.5 0 1 1 2.12 2.12l-9 9a1.5 1.5 0 1 1-2.12-2.12l9-9z\"/></g></svg>";

/***/ }),
/* 97 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 30 11\"><path d=\"M15 7.757L27.737.21a1.5 1.5 0 0 1 1.53 2.58c-4.5 2.668-9 5.334-13.5 8a1.503 1.503 0 0 1-1.53 0c-4.5-2.666-9-5.332-13.5-8A1.5 1.5 0 1 1 2.266.21C6.51 2.726 10.756 5.24 15 7.757\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 98 */
/***/ (function(module, exports) {

module.exports = "<svg height=\"24\" class=\"octicon octicon-mark-github\" viewBox=\"0 0 16 16\" version=\"1.1\" width=\"24\" aria-hidden=\"true\"><path fill-rule=\"evenodd\" d=\"M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z\"></path></svg>";

/***/ }),
/* 99 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"40\" height=\"40\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#2E2D2D\" fill-rule=\"evenodd\"><path d=\"M10 35.899c1.369-.79 2.743-1.58 4.111-2.371a1.377 1.377 0 0 1 1.136-.15l.021.006a18.57 18.57 0 0 0 7.865.348 18.198 18.198 0 0 0 4.757-1.507 17.286 17.286 0 0 0 2.912-1.763 16.288 16.288 0 0 0 2.467-2.282 15.604 15.604 0 0 0 1.874-2.649c.254-.455.485-.924.69-1.403A14.457 14.457 0 0 0 37 18.5a14.416 14.416 0 0 0-1.167-5.63 15.083 15.083 0 0 0-2.564-4.052 16.092 16.092 0 0 0-2.467-2.282 16.79 16.79 0 0 0-1.412-.954 17.746 17.746 0 0 0-4.655-1.968 18.577 18.577 0 0 0-9.467 0 18.085 18.085 0 0 0-3.155 1.159c-.512.246-1.013.515-1.5.809A16.774 16.774 0 0 0 7.901 7.62a15.883 15.883 0 0 0-2.184 2.487A15.346 15.346 0 0 0 4.17 12.87a14.413 14.413 0 0 0-.886 2.852A14.162 14.162 0 0 0 3 18.5c0 .932.101 1.862.284 2.776a14.455 14.455 0 0 0 1.212 3.56 1.5 1.5 0 1 1-2.691 1.324C-2.282 17.851.85 8.412 8.399 3.434c7.336-4.837 17.307-4.554 24.314.787 7.227 5.508 9.538 15.166 4.84 23.136-4.552 7.722-13.987 11.064-22.468 9.073l-5.829 3.367a1.5 1.5 0 0 1-2.249-1.299v-7C7.007 30.67 7.672 30 8.5 30c.828 0 1.5.67 1.5 1.498v4.401\"/><path d=\"M18.5 17h3a1.5 1.5 0 1 1 0 3h-3a1.5 1.5 0 1 1 0-3M31.5 17a1.5 1.5 0 1 1 0 3h-3a1.5 1.5 0 1 1 0-3h3M11.5 17a1.5 1.5 0 1 1 0 3h-3a1.5 1.5 0 1 1 0-3h3\"/></g></svg>";

/***/ }),
/* 100 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 35 9\"><g transform=\"translate(0 -13)\" fill-rule=\"evenodd\"><rect opacity=\".3\" y=\"15\" width=\"5\" height=\"5\" rx=\"2.5\"/><circle opacity=\".8\" cx=\"17.5\" cy=\"17.5\" r=\"4.5\"/><rect opacity=\".3\" x=\"30\" y=\"15\" width=\"5\" height=\"5\" rx=\"2.5\"/></g></svg>";

/***/ }),
/* 101 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"37\" height=\"37\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#2E2D2D\" fill-rule=\"evenodd\"><path d=\"M34.414 29.914a2 2 0 0 0 0-2.828l-4.5-4.5a2 2 0 0 0-2.828 0l-4.5 4.5a2 2 0 0 0 0 2.828l4.5 4.5a2 2 0 0 0 2.828 0l4.5-4.5\" opacity=\".35\"/><path d=\"M34 13a1 1 0 0 1-1 1h-9a1 1 0 0 1-1-1V4a1 1 0 0 1 1-1h9a1 1 0 0 1 1 1v9zM33 0h-9a4 4 0 0 0-4 4v9a4 4 0 0 0 4 4h9a4 4 0 0 0 4-4V4a4 4 0 0 0-4-4zM14 13a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V4a1 1 0 0 1 1-1h9a1 1 0 0 1 1 1v9zM13 0H4a4 4 0 0 0-4 4v9a4 4 0 0 0 4 4h9a4 4 0 0 0 4-4V4a4 4 0 0 0-4-4zM14 33a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1v-9a1 1 0 0 1 1-1h9a1 1 0 0 1 1 1v9zm-1-13H4a4 4 0 0 0-4 4v9a4 4 0 0 0 4 4h9a4 4 0 0 0 4-4v-9a4 4 0 0 0-4-4zM33.707 29.207l-4.5 4.5a.999.999 0 0 1-1.414 0l-4.5-4.5a.999.999 0 0 1 0-1.414l4.5-4.5a.999.999 0 0 1 1.414 0l4.5 4.5a.999.999 0 0 1 0 1.414zm2.122-3.536l-4.5-4.5a4.002 4.002 0 0 0-5.658 0l-4.5 4.5a4.002 4.002 0 0 0 0 5.658l4.5 4.5a4.002 4.002 0 0 0 5.658 0l4.5-4.5a4.002 4.002 0 0 0 0-5.658z\"/></g></svg>";

/***/ }),
/* 102 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"39\" height=\"7\" xmlns=\"http://www.w3.org/2000/svg\"><g transform=\"translate(-1 -17)\" fill=\"#2E2D2D\" fill-rule=\"evenodd\"><circle cx=\"36.5\" cy=\"20.5\" r=\"3.5\"/><circle cx=\"20.5\" cy=\"20.5\" r=\"3.5\"/><circle cx=\"4.5\" cy=\"20.5\" r=\"3.5\"/></g></svg>";

/***/ }),
/* 103 */
/***/ (function(module, exports) {

module.exports = "<?xml version=\"1.0\" standalone=\"no\"?><!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"><svg t=\"1591940507377\" class=\"icon\" viewBox=\"0 0 1024 1024\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" p-id=\"1389\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" width=\"200\" height=\"200\"><defs><style type=\"text/css\"></style></defs><path d=\"M512 256c117.632 0 213.333333 95.701333 213.333333 213.333333v149.333334c0 13.845333 4.501333 27.328 12.8 38.4L789.333333 725.333333H234.666667l51.2-68.266666c8.298667-11.072 12.8-24.554667 12.8-38.4v-149.333334c0-117.632 95.701333-213.333333 213.333333-213.333333m0-64c-153.173333 0-277.333333 124.16-277.333333 277.333333v149.333334l-64 85.333333v42.666667c0 23.466667 19.2 42.666667 42.666666 42.666666h597.333334c23.466667 0 42.666667-19.2 42.666666-42.666666v-42.666667l-64-85.333333v-149.333334c0-153.173333-124.16-277.333333-277.333333-277.333333zM512 853.333333a64 64 0 0 1-64-64h-64c0 70.570667 57.429333 128 128 128s128-57.429333 128-128h-64a64 64 0 0 1-64 64z\"  p-id=\"1390\"></path><path d=\"M512 256a42.666667 42.666667 0 1 1-0.021333-85.312A42.666667 42.666667 0 0 1 512 256h97.621333A105.962667 105.962667 0 0 0 618.666667 213.333333c0-58.816-47.850667-106.666667-106.666667-106.666666s-106.666667 47.850667-106.666667 106.666666c0 15.189333 3.306667 29.568 9.045334 42.666667H512z\" p-id=\"1391\"></path></svg>";

/***/ }),
/* 104 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"40\" height=\"39\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#2E2D2D\" fill-rule=\"evenodd\"><path d=\"M34 39a6 6 0 0 0 6-6v-3.5a1.5 1.5 0 1 0-3 0V33a3 3 0 0 1-3 3H6a3 3 0 0 1-3-3v-3.5a1.5 1.5 0 1 0-3 0V33a6 6 0 0 0 6 6h28M38.5 18a1.5 1.5 0 1 1 0 3h-5a1.5 1.5 0 1 1 0-3h5M26.5 18a1.5 1.5 0 1 1 0 3h-25a1.5 1.5 0 1 1 0-3h25M40 6a6 6 0 0 0-6-6H6a6 6 0 0 0-6 6v3.5a1.5 1.5 0 1 0 3 0V6a3 3 0 0 1 3-3h28a3 3 0 0 1 3 3v3.5a1.5 1.5 0 1 0 3 0V6\"/></g></svg>";

/***/ }),
/* 105 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 11 30\"><g fill=\"none\" fill-rule=\"evenodd\"><path d=\"M-11 0h30v30h-30z\"/><path d=\"M7.757 15C5.241 10.755 2.727 6.51.21 2.266A1.5 1.5 0 0 1 2.79.736l8 13.499c.28.472.28 1.058 0 1.53l-8 13.5a1.499 1.499 0 1 1-2.58-1.53L7.757 15z\" fill=\"currentColor\"/></g></svg>";

/***/ }),
/* 106 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 27 27\"><path d=\"M13.658 22.979c-5.511.363-10.273-3.81-10.637-9.321-.363-5.511 3.81-10.273 9.321-10.637 5.511-.363 10.273 3.81 10.637 9.321.363 5.511-3.81 10.273-9.321 10.637zM26.56 24.44l-3.369-3.37c4.277-5.4 3.599-13.197-1.545-17.778-5.144-4.581-12.968-4.355-17.838.516-4.871 4.87-5.097 12.694-.516 17.838 4.581 5.143 12.378 5.822 17.778 1.545l3.37 3.37a1.5 1.5 0 0 0 2.12-2.121z\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 107 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"40\" height=\"40\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#2E2D2D\" fill-rule=\"evenodd\"><path d=\"M24.495 34.027a1.5 1.5 0 0 1 1.03 2.818c-8.971 3.28-18.983-.611-23.385-9.088C-2.262 19.28.313 8.852 8.156 3.4 16-2.053 26.671-.834 33.083 6.246c6.412 7.08 6.571 17.82.371 25.087l6.107 6.107a1.501 1.501 0 0 1-2.122 2.121l-7.125-7.126a1.501 1.501 0 0 1 0-2.121c5.773-5.773 6.273-14.967 1.161-21.333-5.113-6.365-14.198-7.86-21.08-3.469-6.883 4.392-9.354 13.262-5.736 20.58 3.619 7.319 12.168 10.739 19.836 7.935\"/><path d=\"M27.272 15.453a1.5 1.5 0 0 0 2.757-1.182 12 12 0 0 0-6.299-6.299 1.5 1.5 0 0 0-1.182 2.757 9 9 0 0 1 4.821 4.959\"/></g></svg>";

/***/ }),
/* 108 */
/***/ (function(module, exports) {

module.exports = "<svg width=\"40\" height=\"40\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#2E2D2D\" fill-rule=\"evenodd\"><path d=\"M31 40H6a6 6 0 0 1-6-6V11a6 6 0 0 1 6-6h9.5a1.5 1.5 0 0 1 0 3H6a3 3 0 0 0-3 3v23a3 3 0 0 0 3 3h25a3 3 0 0 0 3-3v-9.5a1.5 1.5 0 0 1 3 0V34a6 6 0 0 1-6 6\"/><path d=\"M39.435 5.313l-.024-.004a1.5 1.5 0 0 1 .15 2.252l-5 5a1.502 1.502 0 0 1-2.122 0 1.502 1.502 0 0 1 0-2.122l2.397-2.397C26.474 8.652 20 15.615 20 24v2.5a1.5 1.5 0 0 1-3 0V24c0-10.07 7.856-18.391 17.91-18.97-.824-.822-1.647-1.646-2.471-2.47a1.502 1.502 0 0 1 0-2.121 1.502 1.502 0 0 1 2.122 0l5 5\"/></g></svg>";

/***/ }),
/* 109 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 28 21\"><path d=\"M10 13.5l-7-6-3 3L10.5 21 28 3.5l-3-3z\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 110 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 31 33\"><g fill-rule=\"evenodd\"><path d=\"M17 1.5a1.5 1.5 0 0 0-3 0v30a1.5 1.5 0 1 0 3 0v-30zM8.44 6.44l-8 8a1.5 1.5 0 1 0 2.12 2.12l8-8a1.5 1.5 0 1 0-2.12-2.12z\"/><path d=\"M16.56.44l14 14a1.5 1.5 0 1 1-2.12 2.12l-14-14A1.5 1.5 0 1 1 16.56.44z\"/></g></svg>";

/***/ }),
/* 111 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 35 39\"><path d=\"M3.63 5h22.363c5.789 0 9.278 4.972 8.312 10.342L32.6 24.037c-.56 3.69-4.112 5.893-7.9 5.893H5.27C4.513 29.93 4 29.274 4 28.52c0-.756.615-1.52 1.37-1.52H24.7c2.58 0 4.874-1.242 5.203-3.408l1.713-8.732C32.293 11.094 29.999 8 25.993 8H2.553C1.748 8 1.108 7.772.99 7.026L.017 1.581a1.367 1.367 0 1 1 2.699-.428L3.63 5zM3.5 16h12a1.5 1.5 0 0 1 1.5 1.5v.047a1.5 1.5 0 0 1-1.5 1.5h-12a1.5 1.5 0 0 1-1.5-1.5V17.5A1.5 1.5 0 0 1 3.5 16zM7 39a3 3 0 1 1 0-6 3 3 0 0 1 0 6zm20 0a3 3 0 1 1 0-6 3 3 0 0 1 0 6z\" fill-rule=\"evenodd\"/></svg>";

/***/ }),
/* 112 */
/***/ (function(module, exports) {

module.exports = "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" viewBox=\"0 0 50 50\"><defs><path d=\"M0 19c0 10.494 8.506 19 19 19s19-8.506 19-19S29.494 0 19 0 0 8.506 0 19z\" id=\"b\"/><filter x=\"-28.9%\" y=\"-18.4%\" width=\"157.9%\" height=\"157.9%\" filterUnits=\"objectBoundingBox\" id=\"a\"><feOffset dy=\"4\" in=\"SourceAlpha\" result=\"shadowOffsetOuter1\"/><feGaussianBlur stdDeviation=\"3\" in=\"shadowOffsetOuter1\" result=\"shadowBlurOuter1\"/><feComposite in=\"shadowBlurOuter1\" in2=\"SourceAlpha\" operator=\"out\" result=\"shadowBlurOuter1\"/><feColorMatrix values=\"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.05 0\" in=\"shadowBlurOuter1\"/></filter></defs><g transform=\"translate(6 2)\" fill=\"none\" fill-rule=\"evenodd\"><use fill=\"#000\" filter=\"url(#a)\" xlink:href=\"#b\"/><path stroke-opacity=\".6\" stroke=\"#848484\" stroke-width=\"3\" d=\"M1.5 19c0 9.665 7.835 17.5 17.5 17.5S36.5 28.665 36.5 19 28.665 1.5 19 1.5 1.5 9.335 1.5 19z\" stroke-linejoin=\"square\" fill=\"#FFF\"/></g></svg>";

/***/ }),
/* 113 */
/***/ (function(module, exports, __webpack_require__) {

var arrayLikeToArray = __webpack_require__(26);

function _arrayWithoutHoles(arr) {
  if (Array.isArray(arr)) return arrayLikeToArray(arr);
}

module.exports = _arrayWithoutHoles;

/***/ }),
/* 114 */
/***/ (function(module, exports) {

function _iterableToArray(iter) {
  if (typeof Symbol !== "undefined" && Symbol.iterator in Object(iter)) return Array.from(iter);
}

module.exports = _iterableToArray;

/***/ }),
/* 115 */
/***/ (function(module, exports) {

function _nonIterableSpread() {
  throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
}

module.exports = _nonIterableSpread;

/***/ }),
/* 116 */
/***/ (function(module, exports) {

function _arrayWithHoles(arr) {
  if (Array.isArray(arr)) return arr;
}

module.exports = _arrayWithHoles;

/***/ }),
/* 117 */
/***/ (function(module, exports) {

function _iterableToArrayLimit(arr, i) {
  if (typeof Symbol === "undefined" || !(Symbol.iterator in Object(arr))) return;
  var _arr = [];
  var _n = true;
  var _d = false;
  var _e = undefined;

  try {
    for (var _i = arr[Symbol.iterator](), _s; !(_n = (_s = _i.next()).done); _n = true) {
      _arr.push(_s.value);

      if (i && _arr.length === i) break;
    }
  } catch (err) {
    _d = true;
    _e = err;
  } finally {
    try {
      if (!_n && _i["return"] != null) _i["return"]();
    } finally {
      if (_d) throw _e;
    }
  }

  return _arr;
}

module.exports = _iterableToArrayLimit;

/***/ }),
/* 118 */
/***/ (function(module, exports) {

function _nonIterableRest() {
  throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
}

module.exports = _nonIterableRest;

/***/ }),
/* 119 */
/***/ (function(module, exports, __webpack_require__) {

/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

var runtime = (function (exports) {
  "use strict";

  var Op = Object.prototype;
  var hasOwn = Op.hasOwnProperty;
  var undefined; // More compressible than void 0.
  var $Symbol = typeof Symbol === "function" ? Symbol : {};
  var iteratorSymbol = $Symbol.iterator || "@@iterator";
  var asyncIteratorSymbol = $Symbol.asyncIterator || "@@asyncIterator";
  var toStringTagSymbol = $Symbol.toStringTag || "@@toStringTag";

  function define(obj, key, value) {
    Object.defineProperty(obj, key, {
      value: value,
      enumerable: true,
      configurable: true,
      writable: true
    });
    return obj[key];
  }
  try {
    // IE 8 has a broken Object.defineProperty that only works on DOM objects.
    define({}, "");
  } catch (err) {
    define = function(obj, key, value) {
      return obj[key] = value;
    };
  }

  function wrap(innerFn, outerFn, self, tryLocsList) {
    // If outerFn provided and outerFn.prototype is a Generator, then outerFn.prototype instanceof Generator.
    var protoGenerator = outerFn && outerFn.prototype instanceof Generator ? outerFn : Generator;
    var generator = Object.create(protoGenerator.prototype);
    var context = new Context(tryLocsList || []);

    // The ._invoke method unifies the implementations of the .next,
    // .throw, and .return methods.
    generator._invoke = makeInvokeMethod(innerFn, self, context);

    return generator;
  }
  exports.wrap = wrap;

  // Try/catch helper to minimize deoptimizations. Returns a completion
  // record like context.tryEntries[i].completion. This interface could
  // have been (and was previously) designed to take a closure to be
  // invoked without arguments, but in all the cases we care about we
  // already have an existing method we want to call, so there's no need
  // to create a new function object. We can even get away with assuming
  // the method takes exactly one argument, since that happens to be true
  // in every case, so we don't have to touch the arguments object. The
  // only additional allocation required is the completion record, which
  // has a stable shape and so hopefully should be cheap to allocate.
  function tryCatch(fn, obj, arg) {
    try {
      return { type: "normal", arg: fn.call(obj, arg) };
    } catch (err) {
      return { type: "throw", arg: err };
    }
  }

  var GenStateSuspendedStart = "suspendedStart";
  var GenStateSuspendedYield = "suspendedYield";
  var GenStateExecuting = "executing";
  var GenStateCompleted = "completed";

  // Returning this object from the innerFn has the same effect as
  // breaking out of the dispatch switch statement.
  var ContinueSentinel = {};

  // Dummy constructor functions that we use as the .constructor and
  // .constructor.prototype properties for functions that return Generator
  // objects. For full spec compliance, you may wish to configure your
  // minifier not to mangle the names of these two functions.
  function Generator() {}
  function GeneratorFunction() {}
  function GeneratorFunctionPrototype() {}

  // This is a polyfill for %IteratorPrototype% for environments that
  // don't natively support it.
  var IteratorPrototype = {};
  IteratorPrototype[iteratorSymbol] = function () {
    return this;
  };

  var getProto = Object.getPrototypeOf;
  var NativeIteratorPrototype = getProto && getProto(getProto(values([])));
  if (NativeIteratorPrototype &&
      NativeIteratorPrototype !== Op &&
      hasOwn.call(NativeIteratorPrototype, iteratorSymbol)) {
    // This environment has a native %IteratorPrototype%; use it instead
    // of the polyfill.
    IteratorPrototype = NativeIteratorPrototype;
  }

  var Gp = GeneratorFunctionPrototype.prototype =
    Generator.prototype = Object.create(IteratorPrototype);
  GeneratorFunction.prototype = Gp.constructor = GeneratorFunctionPrototype;
  GeneratorFunctionPrototype.constructor = GeneratorFunction;
  GeneratorFunction.displayName = define(
    GeneratorFunctionPrototype,
    toStringTagSymbol,
    "GeneratorFunction"
  );

  // Helper for defining the .next, .throw, and .return methods of the
  // Iterator interface in terms of a single ._invoke method.
  function defineIteratorMethods(prototype) {
    ["next", "throw", "return"].forEach(function(method) {
      define(prototype, method, function(arg) {
        return this._invoke(method, arg);
      });
    });
  }

  exports.isGeneratorFunction = function(genFun) {
    var ctor = typeof genFun === "function" && genFun.constructor;
    return ctor
      ? ctor === GeneratorFunction ||
        // For the native GeneratorFunction constructor, the best we can
        // do is to check its .name property.
        (ctor.displayName || ctor.name) === "GeneratorFunction"
      : false;
  };

  exports.mark = function(genFun) {
    if (Object.setPrototypeOf) {
      Object.setPrototypeOf(genFun, GeneratorFunctionPrototype);
    } else {
      genFun.__proto__ = GeneratorFunctionPrototype;
      define(genFun, toStringTagSymbol, "GeneratorFunction");
    }
    genFun.prototype = Object.create(Gp);
    return genFun;
  };

  // Within the body of any async function, `await x` is transformed to
  // `yield regeneratorRuntime.awrap(x)`, so that the runtime can test
  // `hasOwn.call(value, "__await")` to determine if the yielded value is
  // meant to be awaited.
  exports.awrap = function(arg) {
    return { __await: arg };
  };

  function AsyncIterator(generator, PromiseImpl) {
    function invoke(method, arg, resolve, reject) {
      var record = tryCatch(generator[method], generator, arg);
      if (record.type === "throw") {
        reject(record.arg);
      } else {
        var result = record.arg;
        var value = result.value;
        if (value &&
            typeof value === "object" &&
            hasOwn.call(value, "__await")) {
          return PromiseImpl.resolve(value.__await).then(function(value) {
            invoke("next", value, resolve, reject);
          }, function(err) {
            invoke("throw", err, resolve, reject);
          });
        }

        return PromiseImpl.resolve(value).then(function(unwrapped) {
          // When a yielded Promise is resolved, its final value becomes
          // the .value of the Promise<{value,done}> result for the
          // current iteration.
          result.value = unwrapped;
          resolve(result);
        }, function(error) {
          // If a rejected Promise was yielded, throw the rejection back
          // into the async generator function so it can be handled there.
          return invoke("throw", error, resolve, reject);
        });
      }
    }

    var previousPromise;

    function enqueue(method, arg) {
      function callInvokeWithMethodAndArg() {
        return new PromiseImpl(function(resolve, reject) {
          invoke(method, arg, resolve, reject);
        });
      }

      return previousPromise =
        // If enqueue has been called before, then we want to wait until
        // all previous Promises have been resolved before calling invoke,
        // so that results are always delivered in the correct order. If
        // enqueue has not been called before, then it is important to
        // call invoke immediately, without waiting on a callback to fire,
        // so that the async generator function has the opportunity to do
        // any necessary setup in a predictable way. This predictability
        // is why the Promise constructor synchronously invokes its
        // executor callback, and why async functions synchronously
        // execute code before the first await. Since we implement simple
        // async functions in terms of async generators, it is especially
        // important to get this right, even though it requires care.
        previousPromise ? previousPromise.then(
          callInvokeWithMethodAndArg,
          // Avoid propagating failures to Promises returned by later
          // invocations of the iterator.
          callInvokeWithMethodAndArg
        ) : callInvokeWithMethodAndArg();
    }

    // Define the unified helper method that is used to implement .next,
    // .throw, and .return (see defineIteratorMethods).
    this._invoke = enqueue;
  }

  defineIteratorMethods(AsyncIterator.prototype);
  AsyncIterator.prototype[asyncIteratorSymbol] = function () {
    return this;
  };
  exports.AsyncIterator = AsyncIterator;

  // Note that simple async functions are implemented on top of
  // AsyncIterator objects; they just return a Promise for the value of
  // the final result produced by the iterator.
  exports.async = function(innerFn, outerFn, self, tryLocsList, PromiseImpl) {
    if (PromiseImpl === void 0) PromiseImpl = Promise;

    var iter = new AsyncIterator(
      wrap(innerFn, outerFn, self, tryLocsList),
      PromiseImpl
    );

    return exports.isGeneratorFunction(outerFn)
      ? iter // If outerFn is a generator, return the full iterator.
      : iter.next().then(function(result) {
          return result.done ? result.value : iter.next();
        });
  };

  function makeInvokeMethod(innerFn, self, context) {
    var state = GenStateSuspendedStart;

    return function invoke(method, arg) {
      if (state === GenStateExecuting) {
        throw new Error("Generator is already running");
      }

      if (state === GenStateCompleted) {
        if (method === "throw") {
          throw arg;
        }

        // Be forgiving, per 25.3.3.3.3 of the spec:
        // https://people.mozilla.org/~jorendorff/es6-draft.html#sec-generatorresume
        return doneResult();
      }

      context.method = method;
      context.arg = arg;

      while (true) {
        var delegate = context.delegate;
        if (delegate) {
          var delegateResult = maybeInvokeDelegate(delegate, context);
          if (delegateResult) {
            if (delegateResult === ContinueSentinel) continue;
            return delegateResult;
          }
        }

        if (context.method === "next") {
          // Setting context._sent for legacy support of Babel's
          // function.sent implementation.
          context.sent = context._sent = context.arg;

        } else if (context.method === "throw") {
          if (state === GenStateSuspendedStart) {
            state = GenStateCompleted;
            throw context.arg;
          }

          context.dispatchException(context.arg);

        } else if (context.method === "return") {
          context.abrupt("return", context.arg);
        }

        state = GenStateExecuting;

        var record = tryCatch(innerFn, self, context);
        if (record.type === "normal") {
          // If an exception is thrown from innerFn, we leave state ===
          // GenStateExecuting and loop back for another invocation.
          state = context.done
            ? GenStateCompleted
            : GenStateSuspendedYield;

          if (record.arg === ContinueSentinel) {
            continue;
          }

          return {
            value: record.arg,
            done: context.done
          };

        } else if (record.type === "throw") {
          state = GenStateCompleted;
          // Dispatch the exception by looping back around to the
          // context.dispatchException(context.arg) call above.
          context.method = "throw";
          context.arg = record.arg;
        }
      }
    };
  }

  // Call delegate.iterator[context.method](context.arg) and handle the
  // result, either by returning a { value, done } result from the
  // delegate iterator, or by modifying context.method and context.arg,
  // setting context.delegate to null, and returning the ContinueSentinel.
  function maybeInvokeDelegate(delegate, context) {
    var method = delegate.iterator[context.method];
    if (method === undefined) {
      // A .throw or .return when the delegate iterator has no .throw
      // method always terminates the yield* loop.
      context.delegate = null;

      if (context.method === "throw") {
        // Note: ["return"] must be used for ES3 parsing compatibility.
        if (delegate.iterator["return"]) {
          // If the delegate iterator has a return method, give it a
          // chance to clean up.
          context.method = "return";
          context.arg = undefined;
          maybeInvokeDelegate(delegate, context);

          if (context.method === "throw") {
            // If maybeInvokeDelegate(context) changed context.method from
            // "return" to "throw", let that override the TypeError below.
            return ContinueSentinel;
          }
        }

        context.method = "throw";
        context.arg = new TypeError(
          "The iterator does not provide a 'throw' method");
      }

      return ContinueSentinel;
    }

    var record = tryCatch(method, delegate.iterator, context.arg);

    if (record.type === "throw") {
      context.method = "throw";
      context.arg = record.arg;
      context.delegate = null;
      return ContinueSentinel;
    }

    var info = record.arg;

    if (! info) {
      context.method = "throw";
      context.arg = new TypeError("iterator result is not an object");
      context.delegate = null;
      return ContinueSentinel;
    }

    if (info.done) {
      // Assign the result of the finished delegate to the temporary
      // variable specified by delegate.resultName (see delegateYield).
      context[delegate.resultName] = info.value;

      // Resume execution at the desired location (see delegateYield).
      context.next = delegate.nextLoc;

      // If context.method was "throw" but the delegate handled the
      // exception, let the outer generator proceed normally. If
      // context.method was "next", forget context.arg since it has been
      // "consumed" by the delegate iterator. If context.method was
      // "return", allow the original .return call to continue in the
      // outer generator.
      if (context.method !== "return") {
        context.method = "next";
        context.arg = undefined;
      }

    } else {
      // Re-yield the result returned by the delegate method.
      return info;
    }

    // The delegate iterator is finished, so forget it and continue with
    // the outer generator.
    context.delegate = null;
    return ContinueSentinel;
  }

  // Define Generator.prototype.{next,throw,return} in terms of the
  // unified ._invoke helper method.
  defineIteratorMethods(Gp);

  define(Gp, toStringTagSymbol, "Generator");

  // A Generator should always return itself as the iterator object when the
  // @@iterator function is called on it. Some browsers' implementations of the
  // iterator prototype chain incorrectly implement this, causing the Generator
  // object to not be returned from this call. This ensures that doesn't happen.
  // See https://github.com/facebook/regenerator/issues/274 for more details.
  Gp[iteratorSymbol] = function() {
    return this;
  };

  Gp.toString = function() {
    return "[object Generator]";
  };

  function pushTryEntry(locs) {
    var entry = { tryLoc: locs[0] };

    if (1 in locs) {
      entry.catchLoc = locs[1];
    }

    if (2 in locs) {
      entry.finallyLoc = locs[2];
      entry.afterLoc = locs[3];
    }

    this.tryEntries.push(entry);
  }

  function resetTryEntry(entry) {
    var record = entry.completion || {};
    record.type = "normal";
    delete record.arg;
    entry.completion = record;
  }

  function Context(tryLocsList) {
    // The root entry object (effectively a try statement without a catch
    // or a finally block) gives us a place to store values thrown from
    // locations where there is no enclosing try statement.
    this.tryEntries = [{ tryLoc: "root" }];
    tryLocsList.forEach(pushTryEntry, this);
    this.reset(true);
  }

  exports.keys = function(object) {
    var keys = [];
    for (var key in object) {
      keys.push(key);
    }
    keys.reverse();

    // Rather than returning an object with a next method, we keep
    // things simple and return the next function itself.
    return function next() {
      while (keys.length) {
        var key = keys.pop();
        if (key in object) {
          next.value = key;
          next.done = false;
          return next;
        }
      }

      // To avoid creating an additional object, we just hang the .value
      // and .done properties off the next function object itself. This
      // also ensures that the minifier will not anonymize the function.
      next.done = true;
      return next;
    };
  };

  function values(iterable) {
    if (iterable) {
      var iteratorMethod = iterable[iteratorSymbol];
      if (iteratorMethod) {
        return iteratorMethod.call(iterable);
      }

      if (typeof iterable.next === "function") {
        return iterable;
      }

      if (!isNaN(iterable.length)) {
        var i = -1, next = function next() {
          while (++i < iterable.length) {
            if (hasOwn.call(iterable, i)) {
              next.value = iterable[i];
              next.done = false;
              return next;
            }
          }

          next.value = undefined;
          next.done = true;

          return next;
        };

        return next.next = next;
      }
    }

    // Return an iterator with no values.
    return { next: doneResult };
  }
  exports.values = values;

  function doneResult() {
    return { value: undefined, done: true };
  }

  Context.prototype = {
    constructor: Context,

    reset: function(skipTempReset) {
      this.prev = 0;
      this.next = 0;
      // Resetting context._sent for legacy support of Babel's
      // function.sent implementation.
      this.sent = this._sent = undefined;
      this.done = false;
      this.delegate = null;

      this.method = "next";
      this.arg = undefined;

      this.tryEntries.forEach(resetTryEntry);

      if (!skipTempReset) {
        for (var name in this) {
          // Not sure about the optimal order of these conditions:
          if (name.charAt(0) === "t" &&
              hasOwn.call(this, name) &&
              !isNaN(+name.slice(1))) {
            this[name] = undefined;
          }
        }
      }
    },

    stop: function() {
      this.done = true;

      var rootEntry = this.tryEntries[0];
      var rootRecord = rootEntry.completion;
      if (rootRecord.type === "throw") {
        throw rootRecord.arg;
      }

      return this.rval;
    },

    dispatchException: function(exception) {
      if (this.done) {
        throw exception;
      }

      var context = this;
      function handle(loc, caught) {
        record.type = "throw";
        record.arg = exception;
        context.next = loc;

        if (caught) {
          // If the dispatched exception was caught by a catch block,
          // then let that catch block handle the exception normally.
          context.method = "next";
          context.arg = undefined;
        }

        return !! caught;
      }

      for (var i = this.tryEntries.length - 1; i >= 0; --i) {
        var entry = this.tryEntries[i];
        var record = entry.completion;

        if (entry.tryLoc === "root") {
          // Exception thrown outside of any try block that could handle
          // it, so set the completion value of the entire function to
          // throw the exception.
          return handle("end");
        }

        if (entry.tryLoc <= this.prev) {
          var hasCatch = hasOwn.call(entry, "catchLoc");
          var hasFinally = hasOwn.call(entry, "finallyLoc");

          if (hasCatch && hasFinally) {
            if (this.prev < entry.catchLoc) {
              return handle(entry.catchLoc, true);
            } else if (this.prev < entry.finallyLoc) {
              return handle(entry.finallyLoc);
            }

          } else if (hasCatch) {
            if (this.prev < entry.catchLoc) {
              return handle(entry.catchLoc, true);
            }

          } else if (hasFinally) {
            if (this.prev < entry.finallyLoc) {
              return handle(entry.finallyLoc);
            }

          } else {
            throw new Error("try statement without catch or finally");
          }
        }
      }
    },

    abrupt: function(type, arg) {
      for (var i = this.tryEntries.length - 1; i >= 0; --i) {
        var entry = this.tryEntries[i];
        if (entry.tryLoc <= this.prev &&
            hasOwn.call(entry, "finallyLoc") &&
            this.prev < entry.finallyLoc) {
          var finallyEntry = entry;
          break;
        }
      }

      if (finallyEntry &&
          (type === "break" ||
           type === "continue") &&
          finallyEntry.tryLoc <= arg &&
          arg <= finallyEntry.finallyLoc) {
        // Ignore the finally entry if control is not jumping to a
        // location outside the try/catch block.
        finallyEntry = null;
      }

      var record = finallyEntry ? finallyEntry.completion : {};
      record.type = type;
      record.arg = arg;

      if (finallyEntry) {
        this.method = "next";
        this.next = finallyEntry.finallyLoc;
        return ContinueSentinel;
      }

      return this.complete(record);
    },

    complete: function(record, afterLoc) {
      if (record.type === "throw") {
        throw record.arg;
      }

      if (record.type === "break" ||
          record.type === "continue") {
        this.next = record.arg;
      } else if (record.type === "return") {
        this.rval = this.arg = record.arg;
        this.method = "return";
        this.next = "end";
      } else if (record.type === "normal" && afterLoc) {
        this.next = afterLoc;
      }

      return ContinueSentinel;
    },

    finish: function(finallyLoc) {
      for (var i = this.tryEntries.length - 1; i >= 0; --i) {
        var entry = this.tryEntries[i];
        if (entry.finallyLoc === finallyLoc) {
          this.complete(entry.completion, entry.afterLoc);
          resetTryEntry(entry);
          return ContinueSentinel;
        }
      }
    },

    "catch": function(tryLoc) {
      for (var i = this.tryEntries.length - 1; i >= 0; --i) {
        var entry = this.tryEntries[i];
        if (entry.tryLoc === tryLoc) {
          var record = entry.completion;
          if (record.type === "throw") {
            var thrown = record.arg;
            resetTryEntry(entry);
          }
          return thrown;
        }
      }

      // The context.catch method must only be called with a location
      // argument that corresponds to a known catch block.
      throw new Error("illegal catch attempt");
    },

    delegateYield: function(iterable, resultName, nextLoc) {
      this.delegate = {
        iterator: values(iterable),
        resultName: resultName,
        nextLoc: nextLoc
      };

      if (this.method === "next") {
        // Deliberately forget the last sent value so that we don't
        // accidentally pass it on to the delegate.
        this.arg = undefined;
      }

      return ContinueSentinel;
    }
  };

  // Regardless of whether this script is executing as a CommonJS module
  // or not, return the runtime object so that we can declare the variable
  // regeneratorRuntime in the outer scope, which allows this module to be
  // injected easily by `bin/regenerator --include-runtime script.js`.
  return exports;

}(
  // If this script is executing as a CommonJS module, use module.exports
  // as the regeneratorRuntime namespace. Otherwise create a new empty
  // object. Either way, the resulting object will be used to initialize
  // the regeneratorRuntime variable at the top of this file.
   true ? module.exports : undefined
));

try {
  regeneratorRuntime = runtime;
} catch (accidentalStrictMode) {
  // This module should not be running in strict mode, so the above
  // assignment should always work unless something is misconfigured. Just
  // in case runtime.js accidentally runs in strict mode, we can escape
  // strict mode using a global Function call. This could conceivably fail
  // if a Content Security Policy forbids using Function, but in that case
  // the proper solution is to fix the accidental strict mode problem. If
  // you've misconfigured your bundler to force strict mode and applied a
  // CSP to forbid Function, and you're not willing to fix either of those
  // problems, please detail your unique predicament in a GitHub issue.
  Function("r", "regeneratorRuntime = r")(runtime);
}


/***/ }),
/* 120 */
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),
/* 121 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var _node_modules_mini_css_extract_plugin_dist_loader_js_ref_0_0_node_modules_css_loader_dist_cjs_js_node_modules_vue_loader_lib_loaders_stylePostLoader_js_node_modules_postcss_loader_src_index_js_node_modules_sass_loader_dist_cjs_js_ref_0_3_node_modules_cache_loader_dist_cjs_js_node_modules_vue_loader_lib_index_js_vue_loader_options_luckycard_vue_vue_type_style_index_0_lang_scss___WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(6);
/* harmony import */ var _node_modules_mini_css_extract_plugin_dist_loader_js_ref_0_0_node_modules_css_loader_dist_cjs_js_node_modules_vue_loader_lib_loaders_stylePostLoader_js_node_modules_postcss_loader_src_index_js_node_modules_sass_loader_dist_cjs_js_ref_0_3_node_modules_cache_loader_dist_cjs_js_node_modules_vue_loader_lib_index_js_vue_loader_options_luckycard_vue_vue_type_style_index_0_lang_scss___WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_node_modules_mini_css_extract_plugin_dist_loader_js_ref_0_0_node_modules_css_loader_dist_cjs_js_node_modules_vue_loader_lib_loaders_stylePostLoader_js_node_modules_postcss_loader_src_index_js_node_modules_sass_loader_dist_cjs_js_ref_0_3_node_modules_cache_loader_dist_cjs_js_node_modules_vue_loader_lib_index_js_vue_loader_options_luckycard_vue_vue_type_style_index_0_lang_scss___WEBPACK_IMPORTED_MODULE_0__);
/* unused harmony reexport * */
 /* unused harmony default export */ var _unused_webpack_default_export = (_node_modules_mini_css_extract_plugin_dist_loader_js_ref_0_0_node_modules_css_loader_dist_cjs_js_node_modules_vue_loader_lib_loaders_stylePostLoader_js_node_modules_postcss_loader_src_index_js_node_modules_sass_loader_dist_cjs_js_ref_0_3_node_modules_cache_loader_dist_cjs_js_node_modules_vue_loader_lib_index_js_vue_loader_options_luckycard_vue_vue_type_style_index_0_lang_scss___WEBPACK_IMPORTED_MODULE_0___default.a); 

/***/ }),
/* 122 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
// ESM COMPAT FLAG
__webpack_require__.r(__webpack_exports__);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/defineProperty.js
var defineProperty = __webpack_require__(1);
var defineProperty_default = /*#__PURE__*/__webpack_require__.n(defineProperty);

// EXTERNAL MODULE: ./package.json
var package_0 = __webpack_require__(83);

// EXTERNAL MODULE: ./src/config.json
var src_config = __webpack_require__(84);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/typeof.js
var helpers_typeof = __webpack_require__(4);
var typeof_default = /*#__PURE__*/__webpack_require__.n(helpers_typeof);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/extends.js
var helpers_extends = __webpack_require__(2);
var extends_default = /*#__PURE__*/__webpack_require__.n(helpers_extends);

// EXTERNAL MODULE: external {"root":"Vue","commonjs":"vue","commonjs2":"vue","amd":"vue"}
var external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_ = __webpack_require__(3);
var external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default = /*#__PURE__*/__webpack_require__.n(external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_);

// CONCATENATED MODULE: ./src/locales/lang/zn-CH.js

var zn_CH_lang = {
  lang: {
    okBtnTxt: '确 定',
    cancelBtnTxt: '取 消',
    calendar: {
      loadPrevMonth: '加载上一个月',
      noMoreMonth: '没有更早月份~',
      start: '开始',
      end: '结束',
      title: '选择日期',
      week: '日,一,二,三,四,五,六',
      monthTitle: '{year}年{month}月'
    },
    menu: {
      resetBtnTxt: '重置'
    },
    searchbar: {
      placeText: '请输入内容...',
      textInfo: '搜索'
    },
    shortpassword: {
      tip1: '输入数字密码',
      tip2: '忘记密码'
    },
    steps: {
      step: '步骤',
      stepDesc: '步骤描述'
    },
    uploader: {
      xmlError: '对不起，您的浏览器不支持本组件！',
      typeError: '不支持上传该类型文件',
      limitError: '文件大小超过限制'
    }
  }
};
external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang = 'zn-CH';
/* harmony default export */ var zn_CH = (zn_CH_lang);
// CONCATENATED MODULE: ./src/locales/index.js




var defaultMessages = {};
var merged = false;

var locales_vueI18nHandler = function vueI18nHandler() {
  var vuei18n = Object.getPrototypeOf(this || external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a).$t;

  if (typeof vuei18n === 'function' && !!external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.locale) {
    if (!merged) {
      merged = true;
      external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.locale(external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang, extends_default()(external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang === 'zn-CH' ? zn_CH : {}, external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.locale(external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang) || {}, defaultMessages));
    }

    return vuei18n.apply(this, arguments);
  }
};

function i18n(keysStr, params) {
  var value = locales_vueI18nHandler.apply(this, arguments);
  if (value !== null && value !== undefined) return value;

  var message = extends_default()({}, external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang === 'zn-CH' ? zn_CH : {}, defaultMessages);

  var keys = keysStr && keysStr.split('.') || [];
  var result = null;

  if (keys.length) {
    for (var i = 0; i < keys.length; i++) {
      var key = keys[i];

      if (key && message[key]) {
        message = message[key];
        result = message;
      } else {
        result = null;
        break;
      }
    }
  }

  return simpleTemplate(result, params);
}

function locale(lang, messages) {
  if (typeof_default()(lang) === 'object') {
    messages = lang;
    lang = external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang;
  }

  external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.config.lang = lang;

  extends_default()(defaultMessages, messages);
}

function getArgType(arg) {
  return Object.prototype.toString.call(arg).toLowerCase().match(/\s(\w+)/)[1];
}

function simpleTemplate(templ, conf) {
  var pars = templ && templ.match(/{.+?}/g);

  if (pars && conf) {
    pars = pars.map(function (p) {
      return p.replace(/\{\s*(\w+|\d+).*?\}/, '$1');
    });
    pars.forEach(function (c, i) {
      var reg = new RegExp('{\\s*' + c + '\\s*(?:=\\s*(\\S*?))?\\s*?}', 'g');
      templ = templ.replace(reg, function (a, b) {
        return getArgType(conf[c]) == 'function' ? conf[c]() : conf[c] !== undefined ? conf[c] : b ? b : a;
      });
    });
  }

  return templ;
}


// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/cell/cell.vue?vue&type=template&id=f50b618e&
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('a',{class:['nut-cell', { 'nut-cell-link': _vm.isLink }],style:({ 'background-color': _vm.bgColor }),attrs:{"href":_vm.linkUrl,"target":_vm.target},on:{"click":_vm.jumpPage}},[_c('div',{staticClass:"nut-cell-box",on:{"click":_vm.clickCell}},[_vm._t("avatar"),_vm._v(" "),_c('div',{staticClass:"nut-cell-left"},[_c('span',{staticClass:"nut-cell-title"},[_vm._t("title",[_vm._v(_vm._s(_vm.title))])],2),_vm._v(" "),_c('span',{staticClass:"nut-cell-sub-title"},[_vm._t("sub-title",[_vm._v(_vm._s(_vm.subTitle))])],2)]),_vm._v(" "),_c('div',{staticClass:"nut-cell-right"},[_c('span',{staticClass:"nut-cell-desc"},[_vm._t("desc",[_vm._v(_vm._s(_vm.desc))])],2),_vm._v(" "),_c('span',{staticClass:"nut-cell-icon"},[(_vm.showIcon)?_vm._t("icon",[_c('nut-icon',{attrs:{"type":"right","size":"15px","color":"#848484"}})]):_vm._e()],2)])],2)])}
var staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/cell/cell.vue?vue&type=template&id=f50b618e&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/icon/icon.vue?vue&type=template&id=508b7854&
var iconvue_type_template_id_508b7854_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('i',{class:['nut-icon', 'nut-icon-' + _vm.type],style:({ height: _vm.size, width: _vm.size, color: _vm.color }),domProps:{"innerHTML":_vm._s(_vm.icon)}})}
var iconvue_type_template_id_508b7854_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/icon/icon.vue?vue&type=template&id=508b7854&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/icon/icon.vue?vue&type=script&lang=js&
//
//
//
var types = ['top', 'action', 'cross', 'down', 'right', 'more', 'notice', 'plus', 'search', 'trolley', 'tick', 'minus', 'circle-cross'];
/* harmony default export */ var iconvue_type_script_lang_js_ = ({
  name: 'nut-icon',
  props: {
    type: {
      type: String,
      default: ''
    },
    size: {
      type: String,
      default: ''
    },
    color: {
      type: String,
      default: '#2e2d2d'
    },
    url: {
      type: String,
      default: ''
    }
  },
  data: function data() {
    return {
      icon: null
    };
  },
  watch: {
    url: function url(val) {
      this.icon = val;
    }
  },
  created: function created() {
    if (this.url) {
      this.icon = this.url;
      this.type = 'self';
    } else {
      if (types.indexOf(this.type) === -1) {
        console.error('nut-icon组件type值(' + this.type + ')有误，无此icon!');
      } else {
        this.icon = __webpack_require__(88)("./" + this.type + ".svg");
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/icon/icon.vue?vue&type=script&lang=js&
 /* harmony default export */ var icon_iconvue_type_script_lang_js_ = (iconvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/runtime/componentNormalizer.js
/* globals __VUE_SSR_CONTEXT__ */

// IMPORTANT: Do NOT use ES2015 features in this file (except for modules).
// This module is a runtime utility for cleaner component module output and will
// be included in the final webpack user bundle.

function normalizeComponent (
  scriptExports,
  render,
  staticRenderFns,
  functionalTemplate,
  injectStyles,
  scopeId,
  moduleIdentifier, /* server only */
  shadowMode /* vue-cli only */
) {
  // Vue.extend constructor export interop
  var options = typeof scriptExports === 'function'
    ? scriptExports.options
    : scriptExports

  // render functions
  if (render) {
    options.render = render
    options.staticRenderFns = staticRenderFns
    options._compiled = true
  }

  // functional template
  if (functionalTemplate) {
    options.functional = true
  }

  // scopedId
  if (scopeId) {
    options._scopeId = 'data-v-' + scopeId
  }

  var hook
  if (moduleIdentifier) { // server build
    hook = function (context) {
      // 2.3 injection
      context =
        context || // cached call
        (this.$vnode && this.$vnode.ssrContext) || // stateful
        (this.parent && this.parent.$vnode && this.parent.$vnode.ssrContext) // functional
      // 2.2 with runInNewContext: true
      if (!context && typeof __VUE_SSR_CONTEXT__ !== 'undefined') {
        context = __VUE_SSR_CONTEXT__
      }
      // inject component styles
      if (injectStyles) {
        injectStyles.call(this, context)
      }
      // register component module identifier for async chunk inferrence
      if (context && context._registeredComponents) {
        context._registeredComponents.add(moduleIdentifier)
      }
    }
    // used by ssr in case component is cached and beforeCreate
    // never gets called
    options._ssrRegister = hook
  } else if (injectStyles) {
    hook = shadowMode
      ? function () {
        injectStyles.call(
          this,
          (options.functional ? this.parent : this).$root.$options.shadowRoot
        )
      }
      : injectStyles
  }

  if (hook) {
    if (options.functional) {
      // for template-only hot-reload because in that case the render fn doesn't
      // go through the normalizer
      options._injectStyles = hook
      // register for functional component in vue file
      var originalRender = options.render
      options.render = function renderWithStyleInjection (h, context) {
        hook.call(context)
        return originalRender(h, context)
      }
    } else {
      // inject component registration as beforeCreate hook
      var existing = options.beforeCreate
      options.beforeCreate = existing
        ? [].concat(existing, hook)
        : [hook]
    }
  }

  return {
    exports: scriptExports,
    options: options
  }
}

// CONCATENATED MODULE: ./src/packages/icon/icon.vue





/* normalize component */

var component = normalizeComponent(
  icon_iconvue_type_script_lang_js_,
  iconvue_type_template_id_508b7854_render,
  iconvue_type_template_id_508b7854_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var icon = (component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/cell/cell.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var cellvue_type_script_lang_js_ = ({
  name: 'nut-cell',
  props: {
    title: {
      type: String,
      default: ''
    },
    subTitle: {
      type: String,
      default: ''
    },
    desc: {
      type: String,
      default: ''
    },
    isLink: {
      type: Boolean,
      default: false
    },
    linkUrl: {
      type: String,
      default: 'javascript:void(0)'
    },
    showIcon: {
      type: Boolean,
      default: false
    },
    bgColor: {
      type: String,
      default: '#fff'
    },
    to: {
      type: String,
      default: ''
    },
    target: {
      type: String,
      default: '_self'
    }
  },
  components: {
    'nut-icon': icon
  },
  data: function data() {
    return {};
  },
  methods: {
    clickCell: function clickCell() {
      this.$emit('click-cell');
    },
    jumpPage: function jumpPage() {
      if (!this.to) return false;
      this.$router.push(this.to);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/cell/cell.vue?vue&type=script&lang=js&
 /* harmony default export */ var cell_cellvue_type_script_lang_js_ = (cellvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/cell/cell.vue





/* normalize component */

var cell_component = normalizeComponent(
  cell_cellvue_type_script_lang_js_,
  render,
  staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var cell = (cell_component.exports);
// EXTERNAL MODULE: ./src/packages/cell/cell.scss
var cell_cell = __webpack_require__(23);

// CONCATENATED MODULE: ./src/packages/cell/index.js



cell.install = function (Vue) {
  Vue.component(cell.name, cell);
};

/* harmony default export */ var packages_cell = (cell);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/dialog/dialog.vue?vue&type=template&id=a052a778&
var dialogvue_type_template_id_a052a778_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return (_vm.destroy)?_c('div',{class:['nut-dialog-wrapper', _vm.customClass, { 'nut-dialog-image-wrapper': _vm.type === 'image' }],attrs:{"id":_vm.id}},[_c('transition',{attrs:{"name":_vm.animation ? 'nutFade' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.curVisible),expression:"curVisible"}],class:'nut-dialog-mask',style:({ background: _vm.maskBgStyle }),on:{"click":_vm.modalClick}})]),_vm._v(" "),_c('transition',{attrs:{"name":_vm.animation ? 'nutEase' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.curVisible),expression:"curVisible"}],staticClass:"nut-dialog-box",on:{"click":_vm.modalClick}},[_c('div',{staticClass:"nut-dialog",on:{"click":function($event){$event.stopPropagation();}}},[(_vm.closeBtn)?_c('a',{staticClass:"nut-dialog-close",attrs:{"href":"javascript:;"},on:{"click":_vm.closeBtnClick}}):_vm._e(),_vm._v(" "),(_vm.type === 'image')?[_c('a',{staticClass:"nut-dialog-link",attrs:{"href":"javascript:;"},on:{"click":_vm.imageLinkClick}},[_c('img',{staticClass:"nut-dialog-image",attrs:{"src":_vm.imgSrc,"alt":""}})])]:[_c('div',{staticClass:"nut-dialog-body"},[(_vm.title)?_c('span',{staticClass:"nut-dialog-title",domProps:{"innerHTML":_vm._s(_vm.title)}}):_vm._e(),_vm._v(" "),(_vm.$slots.default)?_c('div',{staticClass:"nut-dialog-content",style:({ textAlign: _vm.textAlign })},[_vm._t("default")],2):(_vm.content)?_c('div',{staticClass:"nut-dialog-content",style:({ textAlign: _vm.textAlign }),domProps:{"innerHTML":_vm._s(_vm.content)}}):_vm._e()]),_vm._v(" "),(!_vm.noFooter)?_c('div',{staticClass:"nut-dialog-footer"},[(!_vm.noCancelBtn)?_c('button',{staticClass:"nut-dialog-btn nut-dialog-cancel",on:{"click":function($event){return _vm.cancelBtnClick(_vm.cancelAutoClose)}}},[_vm._v(_vm._s(_vm.cancelBtnTxt || _vm.nutTranslate('lang.cancelBtnTxt')))]):_vm._e(),_vm._v(" "),(!_vm.noOkBtn)?_c('button',{staticClass:"nut-dialog-btn nut-dialog-ok",class:{ disabled: _vm.okBtnDisabled },attrs:{"disabled":_vm.okBtnDisabled},on:{"click":_vm.okBtnClick}},[_vm._v(_vm._s(_vm.okBtnTxt || _vm.nutTranslate('lang.okBtnTxt')))]):_vm._e()]):_vm._e()]],2)])])],1):_vm._e()}
var dialogvue_type_template_id_a052a778_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/dialog/dialog.vue?vue&type=template&id=a052a778&

// CONCATENATED MODULE: ./src/mixins/locale/index.js

/* harmony default export */ var mixins_locale = ({
  methods: {
    nutTranslate: function nutTranslate() {
      return i18n.apply(this, arguments);
    }
  }
});
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/dialog/dialog.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


var lockMaskScroll = function (bodyCls) {
  var scrollTop;
  return {
    afterOpen: function afterOpen() {
      scrollTop = document.scrollingElement.scrollTop || document.body.scrollTop;
      document.body.classList.add(bodyCls);
      document.body.style.top = -scrollTop + 'px';
    },
    beforeClose: function beforeClose() {
      if (document.body.classList.contains(bodyCls)) {
        document.body.classList.remove(bodyCls);
        document.scrollingElement.scrollTop = scrollTop;
      }
    }
  };
}('dialog-open');

/* harmony default export */ var dialogvue_type_script_lang_js_ = ({
  name: 'nut-dialog',
  mixins: [mixins_locale],
  props: {
    id: {
      type: String,
      default: ''
    },
    title: {
      type: String,
      default: ''
    },
    content: {
      type: String,
      default: ''
    },
    type: {
      type: String,
      default: ''
    },
    link: {
      type: String,
      default: ''
    },
    imgSrc: {
      type: String,
      default: ''
    },
    animation: {
      type: Boolean,
      default: true
    },
    lockBgScroll: {
      type: Boolean,
      default: false
    },
    visible: {
      type: Boolean,
      default: false
    },
    closeBtn: {
      type: Boolean,
      default: false
    },
    closeOnClickModal: {
      type: Boolean,
      default: true
    },
    noFooter: {
      type: Boolean,
      default: false
    },
    noOkBtn: {
      type: Boolean,
      default: false
    },
    noCancelBtn: {
      type: Boolean,
      default: false
    },
    cancelBtnTxt: {
      type: String,
      default: ''
    },
    okBtnTxt: {
      type: String,
      default: ''
    },
    okBtnDisabled: {
      type: Boolean,
      default: false
    },
    cancelAutoClose: {
      type: Boolean,
      default: true
    },
    textAlign: {
      type: String,
      default: 'center'
    },
    onOkBtn: {
      type: Function,
      default: null
    },
    onCloseBtn: {
      type: Function,
      default: null
    },
    onCancelBtn: {
      type: Function,
      default: null
    },
    closeCallback: {
      type: Function,
      default: null
    },
    onClickImageLink: {
      type: Function,
      default: null
    },
    maskBgStyle: {
      type: String,
      default: ''
    },
    canDestroy: {
      type: Boolean,
      default: true
    },
    customClass: {
      type: String,
      default: ''
    },
    closeOnPopstate: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      curVisible: false,
      destroy: false
    };
  },
  created: function created() {
    this.destroy = true;
  },
  mounted: function mounted() {
    var that = this;

    if (that.closeOnPopstate) {
      window.addEventListener('popstate', function () {
        that.close();
      });
    }
  },
  methods: {
    modalClick: function modalClick() {
      if (!this.closeOnClickModal) {
        return;
      }

      this.close('modal');
    },
    todestroy: function todestroy() {
      this.canDestroy ? '' : this.destroy = false;
    },
    close: function close(target) {
      this.$emit('close', target);
      this.$emit('close-callback', target);
      this.todestroy();

      if (typeof this.closeCallback === 'function' && this.closeCallback(target) === false) {
        return;
      }

      this.curVisible = false;
    },
    okBtnClick: function okBtnClick() {
      this.$emit('ok-btn-click');

      if (typeof this.onOkBtn === 'function') {
        this.onOkBtn.call(this);
      }
    },
    cancelBtnClick: function cancelBtnClick(autoClose) {
      this.$emit('cancel-btn-click');

      if (!autoClose) {
        return;
      }

      if (typeof this.onCancelBtn === 'function') {
        if (this.onCancelBtn.call(this) === false) {
          return;
        }
      }

      this.close('cancelBtn');
    },
    closeBtnClick: function closeBtnClick() {
      if (typeof this.onCloseBtn === 'function') {
        if (this.onCloseBtn.call(this) === false) {
          return;
        }
      }

      this.close('closeBtn');
    },
    //图片类型弹窗中的链接点击事件，默认跳转
    imageLinkClick: function imageLinkClick() {
      if (this.onClickImageLink && this.onClickImageLink.call(this) === false) {
        return;
      }

      if (this.link) {
        location.href = this.link;
      }
    }
  },
  watch: {
    visible: {
      handler: function handler(val) {
        this.curVisible = val;
      },
      immediate: true
    },
    curVisible: function curVisible(val) {
      if (this.lockBgScroll) {
        //锁定or解锁页面滚动
        lockMaskScroll[val ? 'afterOpen' : 'beforeClose']();
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/dialog/dialog.vue?vue&type=script&lang=js&
 /* harmony default export */ var dialog_dialogvue_type_script_lang_js_ = (dialogvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/dialog/dialog.vue





/* normalize component */

var dialog_component = normalizeComponent(
  dialog_dialogvue_type_script_lang_js_,
  dialogvue_type_template_id_a052a778_render,
  dialogvue_type_template_id_a052a778_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var dialog = (dialog_component.exports);
// CONCATENATED MODULE: ./src/packages/dialog/_dialog.js


var DialogConstructor = external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.extend(dialog);
var inst;

var _dialog_Dialog = function Dialog(options) {
  options.id = options.id || 'nut-dialog-default-id';

  if (options.type === 'image' && typeof options.closeBtn === 'undefined') {
    options.closeBtn = true;
  }

  inst = new DialogConstructor({
    propsData: options
  });
  inst.vm = inst.$mount();
  var dialogDom = document.querySelector('#' + options.id);

  if (options.id && dialogDom) {
    dialogDom.parentNode.replaceChild(inst.$el, dialogDom);
  } else {
    document.body.appendChild(inst.$el);
  } // setTimeout(() => {
  //     //  设置z-index保证最新的弹窗再最上面
  //     let dialogThis = document.querySelector('#'+options.id);
  //     var nutDialogWrapper = document.getElementsByClassName('nut-dialog-wrapper');
  //     var zIndexNum = 100 + (10 * (nutDialogWrapper.length));
  //     dialogThis.style.zIndex = zIndexNum;
  //     setTimeout(function() {
  //         for(var i = 0;i < nutDialogWrapper.length;i++) {
  //             nutDialogWrapper[i].style.zIndex = zIndexNum - 1 - i;
  //         }
  //     }, 0);
  // }, 10);


  external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.nextTick(function () {
    inst.visible = true;
  });
};

_dialog_Dialog.closed = function () {
  if (inst) {
    inst.close();
  }
};

/* harmony default export */ var _dialog = (_dialog_Dialog);
// EXTERNAL MODULE: ./src/packages/dialog/dialog.scss
var dialog_dialog = __webpack_require__(24);

// CONCATENATED MODULE: ./src/packages/dialog/index.js



var DialogArr = [_dialog, dialog];

DialogArr.install = function (Vue) {
  Vue.prototype['$dialog'] = _dialog;
  Vue.component(dialog.name, dialog);
};

/* harmony default export */ var packages_dialog = (DialogArr);
// EXTERNAL MODULE: ./src/packages/icon/icon.scss
var icon_icon = __webpack_require__(7);

// CONCATENATED MODULE: ./src/packages/icon/index.js



icon.install = function (Vue) {
  Vue.component(icon.name, icon);
};

/* harmony default export */ var packages_icon = (icon);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/toast/toast.vue?vue&type=template&id=8b1baa48&
var toastvue_type_template_id_8b1baa48_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('transition',{attrs:{"name":"toastfade"}},[(_vm.visible)?_c('div',{class:_vm.toastBodyClass,style:({
      bottom: _vm.center ? 'auto' : _vm.bottom + 'px',
      'background-color': _vm.coverColor,
    }),attrs:{"id":_vm.id},on:{"click":_vm.clickCover}},[_c('div',{staticClass:"nut-toast-inner",class:_vm.toastClass,style:(Object.assign({}, {'text-align': _vm.textAlignCenter ? 'center' : 'left',
        'background-color': _vm.bgColor},
        _vm.toastStyle))},[(_vm.hasIcon)?_c('span',{staticClass:"nut-toast-icon-wrapper"},[_c('i',{class:['nut-toast-icon', _vm.type, { 'nut-toast-icon-rotate': _vm.type === 'loading' && _vm.loadingRotate }],style:({ 'background-image': _vm.cusIcon })})]):_vm._e(),_vm._v(" "),_c('span',{staticClass:"nut-toast-text",domProps:{"innerHTML":_vm._s(_vm.msg)}})])]):_vm._e()])}
var toastvue_type_template_id_8b1baa48_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/toast/toast.vue?vue&type=template&id=8b1baa48&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/toast/toast.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var toastvue_type_script_lang_js_ = ({
  name: 'nut-toast',
  props: {},
  data: function data() {
    return {
      id: '',
      msg: '',
      visible: false,
      duration: 2000,
      //显示时间(毫秒)
      timer: null,
      center: true,
      type: '',
      customClass: '',
      bottom: 30,
      size: 'base',
      icon: null,
      textAlignCenter: true,
      loadingRotate: true,
      bgColor: 'rgba(46, 46, 46, 0.7)',
      onClose: null,
      textTimer: null,
      cover: false,
      coverColor: 'rgba(0, 0, 0, 0)',
      toastStyle: {},
      toastClass: '',
      timeStamp: null,
      closeOnClickOverlay: false
    };
  },
  watch: {
    visible: function visible(val) {
      if (val) {
        this.show();
      }
    }
  },
  computed: {
    cusIcon: function cusIcon() {
      return this.icon ? "url(\"".concat(this.icon, "\")") : '';
    },
    toastBodyClass: function toastBodyClass() {
      return ['nut-toast', {
        'nut-toast-center': this.center
      }, {
        'nut-toast-has-icon': this.hasIcon
      }, {
        'nut-toast-cover': this.cover
      }, {
        'nut-loading': this.type == 'loading'
      }, this.customClass, 'nut-toast-' + this.size];
    },
    hasIcon: function hasIcon() {
      if (this.type !== 'text') {
        return true;
      } else {
        return this.cusIcon;
      }
    }
  },
  methods: {
    show: function show(force) {
      var _this = this;

      this.clearTimer();
      clearTimeout(this.textTimer);

      if (this.duration) {
        this.timer = setTimeout(function () {
          _this.hide(force);
        }, this.duration);
      }
    },
    hide: function hide(force) {
      var _this2 = this;

      this.clearTimer();
      this.visible = false;

      if (force) {
        clearTimeout(this.textTimer);
      } else {
        this.textTimer = setTimeout(function () {
          clearTimeout(_this2.textTimer);
          _this2.msg = '';
        }, 300);
      }

      typeof this.onClose === 'function' && this.onClose();
    },
    clearTimer: function clearTimer() {
      if (this.timer) {
        clearTimeout(this.timer);
        this.timer = null;
      }
    },
    clickCover: function clickCover() {
      if (this.closeOnClickOverlay) {
        this.hide();
      }
    }
  },
  destroyed: function destroyed() {
    this.textTimer = null;
    this.timer = null;
  }
});
// CONCATENATED MODULE: ./src/packages/toast/toast.vue?vue&type=script&lang=js&
 /* harmony default export */ var toast_toastvue_type_script_lang_js_ = (toastvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/toast/toast.vue





/* normalize component */

var toast_component = normalizeComponent(
  toast_toastvue_type_script_lang_js_,
  toastvue_type_template_id_8b1baa48_render,
  toastvue_type_template_id_8b1baa48_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var toast = (toast_component.exports);
// CONCATENATED MODULE: ./src/packages/toast/_toast.js



function ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }



var ToastConstructor = external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.extend(toast);
var _toast_instance;
var instanceArr = [];
var defaultOptionsMap = {};
var defaultOptions = {
  msg: '',
  visible: false,
  duration: 2000,
  //显示时间(毫秒)
  timer: null,
  center: true,
  type: '',
  customClass: '',
  bottom: 30,
  size: 'base',
  icon: null,
  textAlignCenter: true,
  loadingRotate: true,
  bgColor: 'rgba(36, 36, 36, 0.8)',
  onClose: null,
  textTimer: null,
  cover: false,
  //透明遮罩层
  coverColor: 'rgba(0, 0, 0, 0)',
  timeStamp: null,
  closeOnClickOverlay: false
};

var currentOptions = _objectSpread({}, defaultOptions);

function _showToast() {
  _toast_instance.vm = _toast_instance.$mount();
  document.body.appendChild(_toast_instance.$el);
  external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.nextTick(function () {
    _toast_instance.visible = true;
  });
}

function _getInstance(obj) {
  var opt = _objectSpread(_objectSpread(_objectSpread({
    id: new Date().getTime()
  }, currentOptions), defaultOptionsMap[obj.type]), obj); //有相同id者共用一个实例，否则新增实例


  if (opt['id'] && instanceArr[opt['id']]) {
    _toast_instance = instanceArr[opt['id']];
    _toast_instance.hide(true);
    _toast_instance = extends_default()(_toast_instance, opt);
  } else {
    _toast_instance = new ToastConstructor({
      data: extends_default()(opt, obj)
    });
    opt['id'] && (instanceArr[opt['id']] = _toast_instance);
  }

  _showToast();

  return _toast_instance;
}

function errorMsg(msg) {
  if (!msg) {
    console.warn('[NutUI Toast]: msg不能为空');
    return;
  }
}

var Toast = {
  text: function text(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    errorMsg(msg);
    return _getInstance(_objectSpread(_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'text'
    }));
  },
  success: function success(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    errorMsg(msg);
    return _getInstance(_objectSpread(_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'success'
    }));
  },
  fail: function fail(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    errorMsg(msg);
    return _getInstance(_objectSpread(_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'fail'
    }));
  },
  warn: function warn(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    errorMsg(msg);
    return _getInstance(_objectSpread(_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'warn'
    }));
  },
  loading: function loading(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    obj = _objectSpread(_objectSpread({}, obj), {}, {
      id: obj.id || 'loading',
      msg: msg,
      type: 'loading'
    });
    obj.cover = typeof obj.cover !== 'undefined' ? obj.cover : true; //loading类型默认打开遮罩层

    obj.duration = obj.duration || 0; //loading类型默认不自动关闭

    return _getInstance(obj);
  },
  setDefaultOptions: function setDefaultOptions(type, options) {
    if (typeof type === 'string') {
      defaultOptionsMap[type] = options;
    } else {
      extends_default()(currentOptions, type);
    }
  },
  resetDefaultOptions: function resetDefaultOptions(type) {
    if (typeof type === 'string') {
      defaultOptionsMap[type] = null;
    } else {
      currentOptions = _objectSpread({}, defaultOptions);
      defaultOptionsMap = {};
    }
  }
};
/* harmony default export */ var _toast = (Toast);
// EXTERNAL MODULE: ./src/packages/toast/toast.scss
var toast_toast = __webpack_require__(25);

// CONCATENATED MODULE: ./src/packages/toast/index.js



_toast.install = function (Vue) {
  Vue.prototype['$toast'] = _toast;
};

/* harmony default export */ var packages_toast = (_toast);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/actionsheet/actionsheet.vue?vue&type=template&id=2e124800&
var actionsheetvue_type_template_id_2e124800_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-actionsheet"},[(_vm.isShowMask)?_c('transition',{attrs:{"name":_vm.isAnimation ? 'nutFade' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.isVisible),expression:"isVisible"}],staticClass:"nut-actionsheet-mask",on:{"click":_vm.clickActionSheetMask}})]):_vm._e(),_vm._v(" "),_c('transition',{attrs:{"name":_vm.isAnimation ? 'nutSlideUp' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.isVisible),expression:"isVisible"}],staticClass:"nut-actionsheet-panel"},[_c('div',{staticClass:"nut-actionsheet-custom"},[_vm._t("custom")],2),_vm._v(" "),(_vm.$slots.title || _vm.$slots.subTitle)?_c('dl',{staticClass:"nut-actionsheet-modal"},[_c('dt',{staticClass:"nut-actionsheet-title"},[_vm._t("title")],2),_vm._v(" "),_c('dd',{staticClass:"nut-actionsheet-sub-title"},[_vm._t("sub-title")],2)]):_vm._e(),_vm._v(" "),_c('ul',{staticClass:"nut-actionsheet-menu"},_vm._l((_vm.menuItems),function(item,index){return _c('li',{key:index,staticClass:"nut-actionsheet-item",class:{ 'nut-actionsheet-item-active': _vm.isHighlight(item), 'nut-actionsheet-item-disabled': item.disable },on:{"click":function($event){return _vm.chooseItem(item, index)}}},[_vm._v(_vm._s(item[_vm.optionTag]))])}),0),_vm._v(" "),(_vm.cancelTxt)?_c('div',{staticClass:"nut-actionsheet-cancel",on:{"click":_vm.cancelActionSheet}},[_vm._v(_vm._s(_vm.cancelTxt))]):_vm._e()])])],1)}
var actionsheetvue_type_template_id_2e124800_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/actionsheet/actionsheet.vue?vue&type=template&id=2e124800&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/actionsheet/actionsheet.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var actionsheetvue_type_script_lang_js_ = ({
  name: 'nut-actionsheet',
  props: {
    isAnimation: {
      type: Boolean,
      default: true
    },
    isLockBgScroll: {
      type: Boolean,
      default: false
    },
    isVisible: {
      type: Boolean,
      default: false
    },
    isShowMask: {
      type: Boolean,
      default: true
    },
    isClickChooseClose: {
      type: Boolean,
      default: true
    },
    isClickCloseMask: {
      type: Boolean,
      default: true
    },
    cancelTxt: {
      type: String,
      default: ''
    },
    optionTag: {
      type: String,
      default: 'name'
    },
    chooseTagValue: {
      type: String,
      default: ''
    },
    menuItems: {
      type: Array,
      default: function _default() {
        return [];
      }
    }
  },
  data: function data() {
    return {};
  },
  watch: {
    isVisible: function isVisible(value) {
      !!value && this.$emit('open');

      if (this.isLockBgScroll) {
        if (value) {
          document.body.classList.add('nut-overflow-hidden');
        } else {
          this.removeLockScrool();
        }
      }
    }
  },
  deactivated: function deactivated() {
    this.removeLockScroll();
  },
  destroyed: function destroyed() {
    this.removeLockScroll();
  },
  methods: {
    removeLockScroll: function removeLockScroll() {
      document.body.classList.remove('nut-overflow-hidden');
    },
    isHighlight: function isHighlight(item) {
      return this.chooseTagValue && this.chooseTagValue == item[this.optionTag] || this.chooseTagValue === 0;
    },
    closeActionSheet: function closeActionSheet() {
      this.$emit('close');
    },
    cancelActionSheet: function cancelActionSheet() {
      this.closeActionSheet();
      this.$emit('cancel');
    },
    clickActionSheetMask: function clickActionSheetMask() {
      this.isClickCloseMask && this.closeActionSheet();
    },
    chooseItem: function chooseItem(item, index) {
      if (!item.disable) {
        if (this.isClickChooseClose) {
          this.closeActionSheet();
        }

        this.$emit('choose', item, index);
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/actionsheet/actionsheet.vue?vue&type=script&lang=js&
 /* harmony default export */ var actionsheet_actionsheetvue_type_script_lang_js_ = (actionsheetvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/actionsheet/actionsheet.vue





/* normalize component */

var actionsheet_component = normalizeComponent(
  actionsheet_actionsheetvue_type_script_lang_js_,
  actionsheetvue_type_template_id_2e124800_render,
  actionsheetvue_type_template_id_2e124800_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var actionsheet = (actionsheet_component.exports);
// EXTERNAL MODULE: ./src/packages/actionsheet/actionsheet.scss
var actionsheet_actionsheet = __webpack_require__(8);

// CONCATENATED MODULE: ./src/packages/actionsheet/index.js



actionsheet.install = function (Vue) {
  Vue.component(actionsheet.name, actionsheet);
};

/* harmony default export */ var packages_actionsheet = (actionsheet);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tab/tab.vue?vue&type=template&id=435c3a2e&
var tabvue_type_template_id_435c3a2e_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-tab-part"},[_c('div',{staticClass:"nut-tab",class:{ 'nut-tab-horizontal': _vm.positionNavCss }},[(_vm.positionNav == 'right' || _vm.positionNav == 'bottom')?_c('div',{ref:"items",staticClass:"nut-tab-item"},[_vm._t("default")],2):_vm._e(),_vm._v(" "),_c('div',{ref:"navlist",class:_vm.titleClass,style:(_vm.customHeight)},[(_vm.isShowLine)?_c('b',{class:_vm.navBarClass,style:(_vm.navBarStyle)}):_vm._e(),_vm._v(" "),_vm._l((_vm.tabTitleList),function(value,index){return _c('span',{key:index,class:[_vm.titleNavList, 'nut-title-nav', { 'nut-tab-disable': value.disable }, { 'nut-tab-active': _vm.activeIndex == index }]},[_c('a',{staticClass:"nut-tab-link",on:{"click":function($event){return _vm.switchTab(index, $event, value.disable)}}},[(!!value.tabSlot)?_vm._t(value.tabSlot,null,{"item":value}):(!!value.badge)?_c('nut-badge',{attrs:{"value":value.badge.value,"max":value.badge.max,"zIndex":value.badge.zIndex,"isDot":value.badge.isDot,"hidden":value.badge.hidden,"top":value.badge.top,"left":value.badge.left}},[(value.iconUrl)?_c('i',{staticClass:"nut-tab-icon",style:({ backgroundImage: 'url(' + value.iconUrl + ')' })}):_vm._e(),_vm._v("\n            "+_vm._s(value.tabTitle)+"\n          ")]):[(value.iconUrl)?_c('i',{staticClass:"nut-tab-icon",style:({ backgroundImage: 'url(' + value.iconUrl + ')' })}):_vm._e(),_vm._v("\n            "+_vm._s(value.tabTitle)+"\n          ")]],2)])})],2),_vm._v(" "),(_vm.positionNav == 'top' || _vm.positionNav == 'left')?_c('div',{ref:"items",staticClass:"nut-tab-item",style:(_vm.customHeight)},[_vm._t("default")],2):_vm._e()])])}
var tabvue_type_template_id_435c3a2e_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/tab/tab.vue?vue&type=template&id=435c3a2e&

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/toConsumableArray.js
var toConsumableArray = __webpack_require__(0);
var toConsumableArray_default = /*#__PURE__*/__webpack_require__.n(toConsumableArray);

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tab/tab.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var tabvue_type_script_lang_js_ = ({
  name: 'nut-tab',
  props: {
    isScroll: {
      type: Boolean,
      default: false
    },
    isShowLine: {
      type: Boolean,
      default: true
    },
    defIndex: {
      type: Number,
      default: 0
    },
    positionNav: {
      type: String,
      default: 'top'
    },
    initData: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    wrapperHeight: {
      type: [String, Number],
      default: '200'
    },
    lineWidth: {
      type: Number,
      default: 0
    }
  },
  data: function data() {
    return {
      tabTitleList: [],
      activeIndex: this.defIndex,
      initX: '0',
      navWidth: 0,
      tapWidth: 0
    };
  },
  watch: {
    isScroll: function isScroll() {
      this.updeteTab();
    },
    lineWidth: function lineWidth() {
      this.updeteTab();
    },
    defIndex: function defIndex() {
      this.updeteTab();
    },
    initData: {
      handler: function handler() {
        this.updeteTab();
      },
      deep: true
    }
  },
  computed: {
    //下面有些样式名称是为了兼容之前的版本
    positionNavCss: function positionNavCss() {
      if (this.positionNav === 'left' || this.positionNav === 'right') return true;
    },
    titleClass: function titleClass() {
      if (this.positionNav == 'top') {
        return 'nut-tab-title';
      }

      return 'nut-tab-title-' + this.positionNav + 'nav';
    },
    navBarClass: function navBarClass() {
      if (this.positionNav == 'top') {
        return 'nav-bar';
      }

      return 'nav-bar-' + this.positionNav;
    },
    titleNavList: function titleNavList() {
      if (this.positionNav == 'top' || this.positionNav == 'bottom') {
        if (this.isScroll) {
          return 'nut-title-nav-scroll';
        }

        return 'nut-title-nav-list';
      } else {
        if (this.isScroll) {
          return 'nut-title-vertical-scroll';
        }

        return 'nut-title-nav-' + this.positionNav + 'nav';
      }
    },
    navBarStyle: function navBarStyle() {
      if (this.positionNav === 'top' || this.positionNav === 'bottom') {
        return {
          transform: "translateX(".concat(this.initX, "px)"),
          //width: this.navWidth + 'px'
          width: (this.lineWidth ? this.lineWidth : this.navWidth) + 'px'
        };
      }

      return {
        transform: "translateY(".concat(this.initX, "px)"),
        //height: this.navWidth + 'px'
        height: (this.lineWidth ? this.lineWidth : this.navWidth) + 'px'
      };
    },
    customHeight: function customHeight() {
      if (this.isScroll && (this.positionNav === 'left' || this.positionNav === 'right')) {
        return {
          height: this.wrapperHeight + 'px'
        };
      } else {
        return null;
      }
    }
  },
  mounted: function mounted() {
    var _this = this;

    this.$nextTick(function () {
      _this.$slots.default && _this.updeteTab(_this.$slots.default);
    });
  },
  methods: {
    updeteTab: function updeteTab() {
      var _this2 = this;

      this.$nextTick(function () {
        _this2.tabTitleList = [];
        _this2.activeIndex = _this2.defIndex;

        _this2.initTab(toConsumableArray_default()(_this2.$slots.default));
      });
    },
    initTab: function initTab(slot) {
      var _this3 = this;

      for (var i = 0; i < slot.length; i++) {
        var slotTag = slot[i].tag;

        if (typeof slotTag == 'string' && slotTag.indexOf('nut-tab-panel') != -1) {
          var attrs = slot[i].data.attrs;
          var item = {
            tabTitle: attrs['tab-title'] || attrs['tabTitle'],
            disable: attrs.disable === false,
            iconUrl: attrs['iconUrl'] || attrs['icon-url'],
            tabSlot: attrs['tab-slot'] || attrs['tabSlot'] || '',
            badge: attrs['badge'] || false
          };
          this.tabTitleList.push(item);
          var slotElm = slot[i].elm;

          if (slotElm) {
            slotElm.classList.add('hide');

            if (this.activeIndex == i) {
              slotElm.classList.remove('hide');
            }
          }
        }
      }

      this.$nextTick(function () {
        var tapWidth;

        if (_this3.positionNav == 'top' || _this3.positionNav == 'bottom') {
          _this3.navWidth = _this3.$refs.navlist.querySelector('.nut-title-nav').offsetWidth;
          tapWidth = _this3.$refs.navlist.offsetWidth;
        } else {
          _this3.navWidth = _this3.$refs.navlist.querySelector('.nut-title-nav').offsetHeight;
          tapWidth = _this3.$refs.navlist.offsetHeight;
        } // this.initX = parseInt(this.navWidth * this.defIndex);
        // this.tapWidth = tapWidth / 2 - this.navWidth / 2;


        if (_this3.lineWidth > 0 && _this3.lineWidth < _this3.navWidth) {
          _this3.initX = parseInt((_this3.navWidth - _this3.lineWidth) / 2 + _this3.navWidth * _this3.defIndex);
        } else {
          _this3.initX = parseInt(_this3.navWidth * _this3.defIndex);
          _this3.tapWidth = tapWidth / 2 - _this3.navWidth / 2;
        }
      });
    },
    findParent: function findParent(event, myclass) {
      var parentCpt = event.target;
      var flag = 0; //避免死循环

      while (parentCpt && flag < 10) {
        flag++;

        if (parentCpt.className && parentCpt.className === myclass) {
          break;
        }

        parentCpt = parentCpt.parentNode;
      }

      return parentCpt;
    },
    switchTab: function switchTab(index, event, disable) {
      if (!disable) {
        this.activeIndex = index; // this.initX = parseInt(this.navWidth * index);

        if (this.lineWidth > 0 && this.lineWidth < this.navWidth) {
          this.initX = parseInt((this.navWidth - this.lineWidth) / 2 + this.navWidth * index);
        } else {
          this.initX = parseInt(this.navWidth * index);
        }

        if (this.positionNav == 'top' || this.positionNav == 'bottom') {
          this.$refs.navlist.scroll(this.initX - this.tapWidth, 0);
        } else {
          this.$refs.navlist.scroll(0, this.initX - this.tapWidth);
        }

        var nutTab = this.findParent(event, 'nut-tab-part');
        var items = this.$refs.items.children;

        for (var i = 0; i < items.length; i++) {
          if (i == index) {
            items[i].classList.remove('hide');
          } else {
            items[i].classList.add('hide');
          }
        }

        this.$emit('tab-switch', index, event);
        this.$emit('tabSwitch', index, event); //兼容以前驼峰法命名
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/tab/tab.vue?vue&type=script&lang=js&
 /* harmony default export */ var tab_tabvue_type_script_lang_js_ = (tabvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/tab/tab.vue





/* normalize component */

var tab_component = normalizeComponent(
  tab_tabvue_type_script_lang_js_,
  tabvue_type_template_id_435c3a2e_render,
  tabvue_type_template_id_435c3a2e_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var tab = (tab_component.exports);
// EXTERNAL MODULE: ./src/packages/tab/tab.scss
var tab_tab = __webpack_require__(9);

// CONCATENATED MODULE: ./src/packages/tab/index.js



tab.install = function (Vue) {
  Vue.component(tab.name, tab);
};

/* harmony default export */ var packages_tab = (tab);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabpanel/tabpanel.vue?vue&type=template&id=76d1f316&
var tabpanelvue_type_template_id_76d1f316_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-tab-panel hide"},[_vm._t("default")],2)}
var tabpanelvue_type_template_id_76d1f316_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/tabpanel/tabpanel.vue?vue&type=template&id=76d1f316&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabpanel/tabpanel.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var tabpanelvue_type_script_lang_js_ = ({
  name: 'nut-tab-panel',
  props: {},
  data: function data() {
    return {};
  },
  computed: {},
  mounted: function mounted() {},
  methods: {}
});
// CONCATENATED MODULE: ./src/packages/tabpanel/tabpanel.vue?vue&type=script&lang=js&
 /* harmony default export */ var tabpanel_tabpanelvue_type_script_lang_js_ = (tabpanelvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/tabpanel/tabpanel.vue





/* normalize component */

var tabpanel_component = normalizeComponent(
  tabpanel_tabpanelvue_type_script_lang_js_,
  tabpanelvue_type_template_id_76d1f316_render,
  tabpanelvue_type_template_id_76d1f316_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var tabpanel = (tabpanel_component.exports);
// EXTERNAL MODULE: ./src/packages/tabpanel/tabpanel.scss
var tabpanel_tabpanel = __webpack_require__(28);

// CONCATENATED MODULE: ./src/packages/tabpanel/index.js



tabpanel.install = function (Vue) {
  Vue.component(tabpanel.name, tabpanel);
};

/* harmony default export */ var packages_tabpanel = (tabpanel);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabbar/tabbar.vue?vue&type=template&id=1322287e&
var tabbarvue_type_template_id_1322287e_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-tabbar",class:{ bottom: _vm.bottom }},_vm._l((_vm.tabList),function(value,index){return _c('a',{key:value.tabTitle,staticClass:"tabbar-nav",class:[{ curr: index == _vm.currIndex }, _vm.type],on:{"click":function($event){return _vm.switchTabs(value, index)}}},[_c('span',{staticClass:"icon-box"},[(value.num && value.num <= 99)?_c('b',{staticClass:"tips num"},[_vm._v(_vm._s(value.num))]):(value.num && value.num > 100)?_c('b',{staticClass:"tips"},[_vm._v(_vm._s('...'))]):_vm._e(),_vm._v(" "),(value.icon)?[_c('div',{staticClass:"icon",style:({ backgroundImage: ("url(" + (index == _vm.currIndex ? value.activeIcon : value.icon) + ")") })})]:_vm._e(),_vm._v(" "),_c('span',{class:['tabbar-nav-word', { 'big-word': !value.icon }]},[_vm._v(_vm._s(value.tabTitle))])],2)])}),0)}
var tabbarvue_type_template_id_1322287e_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/tabbar/tabbar.vue?vue&type=template&id=1322287e&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabbar/tabbar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var tabbarvue_type_script_lang_js_ = ({
  name: 'nut-tabbar',
  props: {
    tabbarList: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    bottom: {
      type: Boolean,
      default: false
    },
    type: {
      type: String,
      default: 'based'
    },
    replace: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      currIndex: null,
      tabList: this.tabbarList
    };
  },
  mounted: function mounted() {
    this.initBar();
  },
  watch: {
    tabbarList: {
      handler: function handler(value) {
        this.tabList = value;
        this.initBar();
      },
      deep: true
    }
  },
  methods: {
    initBar: function initBar() {
      var _this = this;

      this.tabList.forEach(function (item, index) {
        if (item.curr) {
          _this.currIndex = index;
        }
      });
    },
    switchTabs: function switchTabs(value, index) {
      this.currIndex = index;

      if (this.replace) {
        //替换url
        window.location.replace(value.href);
      } else {
        if (value.href) {
          window.location.href = value.href;
        }
      }

      this.$emit('tab-switch', value, index);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/tabbar/tabbar.vue?vue&type=script&lang=js&
 /* harmony default export */ var tabbar_tabbarvue_type_script_lang_js_ = (tabbarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/tabbar/tabbar.vue





/* normalize component */

var tabbar_component = normalizeComponent(
  tabbar_tabbarvue_type_script_lang_js_,
  tabbarvue_type_template_id_1322287e_render,
  tabbarvue_type_template_id_1322287e_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var tabbar = (tabbar_component.exports);
// EXTERNAL MODULE: ./src/packages/tabbar/tabbar.scss
var tabbar_tabbar = __webpack_require__(29);

// CONCATENATED MODULE: ./src/packages/tabbar/index.js



tabbar.install = function (Vue) {
  Vue.component(tabbar.name, tabbar);
};

/* harmony default export */ var packages_tabbar = (tabbar);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/calendar/calendar.vue?vue&type=template&id=36c95750&
var calendarvue_type_template_id_36c95750_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('transition',{attrs:{"name":_vm.animation}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.childIsVisible),expression:"childIsVisible"}],staticClass:"nut-calendar"},[_c('div',{staticClass:"nut-calendar-control"},[((_vm.type == 'range' && _vm.currDate && _vm.currDate.length == 2) || _vm.type != 'range')?_c('span',{staticClass:"nut-calendar-confirm-btn",on:{"click":_vm.confirm}},[_vm._v(_vm._s(_vm.nutTranslate('lang.okBtnTxt')))]):_vm._e(),_vm._v(" "),_c('span',{staticClass:"nut-calendar-cancel-btn",on:{"click":_vm.closeActionSheet}},[_vm._v(_vm._s(_vm.nutTranslate('lang.cancelBtnTxt')))]),_vm._v(" "),_c('div',{staticClass:"nut-calendar-title"},[_vm._v(_vm._s(_vm.title || _vm.nutTranslate('lang.calendar.title')))]),_vm._v(" "),_c('div',{staticClass:"nut-calendar-week"},_vm._l((_vm.week),function(item,index){return _c('span',{key:index},[_vm._v(_vm._s(item))])}),0)]),_vm._v(" "),_c('div',{staticClass:"nut-calendar-months",on:{"touchstart":function($event){$event.stopPropagation();return _vm.touchStart($event)},"touchmove":function($event){$event.stopPropagation();$event.preventDefault();return _vm.touchMove($event)},"touchend":function($event){$event.stopPropagation();return _vm.touchEnd($event)}}},[_c('div',{ref:"months",staticClass:"nut-calendar-months-panel"},[_c('div',{staticClass:"nut-calendar-loading-tip"},[_vm._v(_vm._s(!_vm.unLoadPrev ? _vm.nutTranslate('lang.calendar.loadPrevMonth') : _vm.nutTranslate('lang.calendar.noMoreMonth')))]),_vm._v(" "),_vm._l((_vm.monthsData),function(month,index){return _c('div',{key:index,staticClass:"nut-calendar-month"},[_c('div',{staticClass:"nut-calendar-month-title"},[_vm._v(_vm._s(month.title))]),_vm._v(" "),_c('div',{staticClass:"nut-calendar-month-con"},[_c('div',{staticClass:"nut-calendar-month-item"},[_vm._l((month.monthData),function(day,i){return [_c('div',{key:i,staticClass:"nut-calendar-month-day",class:_vm.getClass(day, month),on:{"click":function($event){return _vm.chooseDay(day, month)}}},[_c('span',[_vm._v(_vm._s(day.type == 'curr' ? day.day : ''))]),_vm._v(" "),(_vm.isStartTip(day, month))?_c('span',{staticClass:"nut-calendar-day-tip"},[_vm._v(_vm._s(_vm.nutTranslate('lang.calendar.start')))]):(_vm.isEndTip(day, month))?_c('span',{staticClass:"nut-calendar-day-tip"},[_vm._v(_vm._s(_vm.nutTranslate('lang.calendar.end')))]):_vm._e()])]})],2)])])})],2)])])])}
var calendarvue_type_template_id_36c95750_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/calendar/calendar.vue?vue&type=template&id=36c95750&

// CONCATENATED MODULE: ./src/utils/date.js
var Utils = {
  /**
   * 是否为闫年
   * @return {Boolse} true|false
   */
  isLeapYear: function isLeapYear(y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
  },

  /**
   * 返回星期数
   * @return {Number}
   */
  getWhatDay: function getWhatDay(year, month, day) {
    var date = new Date(year + '/' + month + '/' + day);
    var index = date.getDay();
    var dayNames = ['星期日', '星期一', '星期二', '星期三', '星期四', '星期五', '星期六'];
    return dayNames[index];
  },

  /**
   * 返回星期数
   * @return {Number}
   */
  getMonthPreDay: function getMonthPreDay(year, month) {
    var date = new Date(year + '/' + month + '/01');
    var day = date.getDay();

    if (day == 0) {
      day = 7;
    }

    return day;
  },

  /**
   * 返回月份天数
   * @return {Number}
   */
  getMonthDays: function getMonthDays(year, month) {
    if (/^0/.test(month)) {
      month = month.split('')[1];
    }

    return [0, 31, this.isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][month];
  },

  /**
   * 补齐数字位数
   * @return {string}
   */
  getNumTwoBit: function getNumTwoBit(n) {
    n = Number(n);
    return (n > 9 ? '' : '0') + n;
  },

  /**
   * 日期对象转成字符串
   * @return {string}
   */
  date2Str: function date2Str(date, split) {
    if (typeof date == 'string') return date;
    split = split || '-';
    var y = date.getFullYear();
    var m = this.getNumTwoBit(date.getMonth() + 1);
    var d = this.getNumTwoBit(date.getDate());
    return [y, m, d].join(split);
  },

  /**
   * 返回日期格式字符串
   * @param {Number} 0返回今天的日期、1返回明天的日期，2返回后天得日期，依次类推
   * @return {string} '2014-12-31'
   */
  getDay: function getDay(i) {
    i = i || 0;
    var date = new Date();
    var diff = i * (1000 * 60 * 60 * 24);
    date = new Date(date.getTime() + diff);
    return this.date2Str(date);
  },

  /**
   * 时间戳转换为日期格式
   * @return {String}
   */
  timestampToDate: function timestampToDate(timestamp) {
    var date = new Date(timestamp);
    return date.getFullYear() + '-' + getNumTwoBit(date.getMonth() + 1) + '-' + getNumTwoBit(date.getDate());
  },

  /**
   * 时间比较
   * @return {Boolean}
   */
  compareDate: function compareDate(date1, date2) {
    var startTime = new Date(date1.replace('-', '/').replace('-', '/'));
    var endTime = new Date(date2.replace('-', '/').replace('-', '/'));

    if (startTime >= endTime) {
      return false;
    }

    return true;
  },

  /**
   * 时间比较
   * @return {Boolean}
   */
  compareDateArr: function compareDateArr(date1, date2) {
    var startTime = new Date();
    startTime.setFullYear(parseInt(date1[0]), parseInt(date1[1]) - 1, parseInt(date1[2]));
    startTime.setHours(parseInt(date1[3]), parseInt(date1[4]));
    var endTime = new Date();
    endTime.setFullYear(parseInt(date2[0]), parseInt(date2[1]) - 1, parseInt(date2[2]));
    endTime.setHours(parseInt(date2[3]), parseInt(date2[4]));

    if (startTime >= endTime) {
      return false;
    }

    return true;
  },

  /**
   * 时间是否相等
   * @return {Boolean}
   */
  isEqual: function isEqual(date1, date2) {
    var startTime = new Date(date1).getTime();
    var endTime = new Date(date2).getTime();

    if (startTime == endTime) {
      return true;
    }

    return false;
  },
  getDateArr: function getDateArr(str) {
    return [this.getYear(str), this.getMonth(str), this.getDate(str), this.getHour(str), this.getMinute(str)];
  },
  isDateString: function isDateString(str) {
    return /\d{4}(\-|\/|.)\d{1,2}\1\d{1,2}/.test(str) || /^([01][0-9]|2[0-3])(:[0-5][0-9]){1,2}$/.test(str);
  },
  getYear: function getYear(value) {
    return this.isDateString(value) ? value.split(' ')[0].split(/-|\/|\./)[0] : value.getFullYear();
  },
  getMonth: function getMonth(value) {
    return this.isDateString(value) ? value.split(' ')[0].split(/-|\/|\./)[1] : value.getMonth() + 1;
  },
  getDate: function getDate(value) {
    return this.isDateString(value) ? value.split(' ')[0].split(/-|\/|\./)[2] : value.getDate();
  },
  getHour: function getHour(value) {
    if (this.isDateString(value)) {
      var str = value.split(' ')[1] || '00:00:00';
      return str.split(':')[0];
    }

    return value.getHours();
  },
  getMinute: function getMinute(value) {
    if (this.isDateString(value)) {
      var str = value.split(' ')[1] || '00:00:00';
      return str.split(':')[1];
    }

    return value.getMinutes();
  }
};
/* harmony default export */ var date = (Utils);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/calendar/calendar.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var calendarvue_type_script_lang_js_ = ({
  name: 'nut-calendar',
  mixins: [mixins_locale],
  props: {
    type: {
      type: String,
      default: 'one'
    },
    animation: {
      type: String,
      default: 'nutSlideUp'
    },
    isAutoBackFill: {
      type: Boolean,
      default: false
    },
    isOpenRangeSelect: {
      type: Boolean,
      default: false
    },
    isVisible: {
      type: Boolean,
      default: false
    },
    title: {
      type: String
    },
    defaultValue: {
      type: String | Array,
      default: null
    },
    startDate: {
      type: String,
      //default: null
      default: date.getDay(0)
    },
    endDate: {
      type: String,
      //default: null
      default: date.getDay(365)
    }
  },
  watch: {
    isVisible: function isVisible(newValue, oldValue) {
      this.childIsVisible = newValue;
    },
    defaultValue: {
      handler: function handler(oldValue, val) {
        if (val) {
          this.resetRender();
        }
      },
      immediate: true
    }
  },
  data: function data() {
    var week = this.nutTranslate('lang.calendar.week');
    return {
      childIsVisible: false,
      currDate: null,
      week: week.split(','),
      unLoadPrev: false,
      unLoadNext: false,
      touchParams: {
        startY: 0,
        endY: 0,
        startTime: 0,
        endTime: 0
      },
      transformY: 0,
      scrollDistance: 0,
      defaultData: null,
      chooseData: [],
      monthsData: [],
      dayPrefix: 'nut-calendar-month-day'
    };
  },
  computed: {
    isRange: function isRange() {
      return this.type === 'range';
    }
  },
  methods: {
    isActive: function isActive(day, month) {
      return this.isRange && day.type == 'curr' && this.getClass(day, month) == 'nut-calendar-month-day-active';
    },
    isStartTip: function isStartTip(day, month) {
      if (this.isActive(day, month)) {
        return this.isStart(this.getCurrDate(day, month));
      } else {
        return false;
      }
    },
    isEndTip: function isEndTip(day, month) {
      return this.isActive(day, month);
    },
    getCurrData: function getCurrData(type) {
      var monthData = type == 'prev' ? this.monthsData[0] : this.monthsData[this.monthsData.length - 1];
      var year = parseInt(monthData.curData[0]);
      var month = parseInt(monthData.curData[1].toString().replace(/^0/, ''));

      switch (type) {
        case 'prev':
          month == 1 && (year -= 1);
          month = month == 1 ? 12 : --month;
          break;

        case 'next':
          month == 12 && (year += 1);
          month = month == 12 ? 1 : ++month;
          break;
      }

      return [year, date.getNumTwoBit(month), monthData.curData[2]];
    },
    getDaysStatus: function getDaysStatus(days, type) {
      // 修复：当某个月的1号是周日时，月份下方会空出来一行
      if (type == 'prev' && days >= 7) {
        days -= 7;
      }

      return Array.from(Array(days), function (v, k) {
        return {
          day: k + 1,
          type: type
        };
      });
    },
    getMonth: function getMonth(curData, type) {
      var preMonthDays = date.getMonthPreDay(curData[0], curData[1]);
      var currMonthDays = date.getMonthDays(curData[0], curData[1]);
      var nextMonthDays = 42 - preMonthDays - currMonthDays;
      var title = this.nutTranslate('lang.calendar.monthTitle', {
        year: curData[0],
        month: curData[1]
      });
      var monthInfo = {
        curData: curData,
        title: title,
        monthData: [].concat(toConsumableArray_default()(this.getDaysStatus(preMonthDays, 'prev')), toConsumableArray_default()(this.getDaysStatus(currMonthDays, 'curr')))
      };

      if (type == 'next') {
        if (!this.endData || !date.compareDate("".concat(this.endData[0], "-").concat(this.endData[1], "-").concat(date.getMonthDays(this.endData[0], this.endData[1])), "".concat(curData[0], "-").concat(curData[1], "-").concat(curData[2]))) {
          this.monthsData.push(monthInfo);
        } else {
          this.unLoadNext = true;
        }
      } else {
        if (!this.startData || !date.compareDate("".concat(curData[0], "-").concat(curData[1], "-").concat(curData[2]), "".concat(this.startData[0], "-").concat(this.startData[1], "-01"))) {
          this.monthsData.unshift(monthInfo);
        } else {
          this.unLoadPrev = true;
        }
      }
    },
    getCurrDate: function getCurrDate(day, month, isRange) {
      return isRange ? month.curData[3] + '-' + month.curData[4] + '-' + date.getNumTwoBit(day.day) : month.curData[0] + '-' + month.curData[1] + '-' + date.getNumTwoBit(day.day);
    },
    isStart: function isStart(currDate) {
      return date.isEqual(this.currDate[0], currDate);
    },
    isEnd: function isEnd(currDate) {
      return date.isEqual(this.currDate[1], currDate);
    },
    splitDate: function splitDate(date) {
      return date.split('-');
    },
    getClass: function getClass(day, month, isRange) {
      var currDate = this.getCurrDate(day, month, isRange);

      if (day.type == 'curr') {
        if (!this.isRange && date.isEqual(this.currDate, currDate) || this.isRange && (this.isStart(currDate) || this.isEnd(currDate))) {
          return "".concat(this.dayPrefix, "-active");
        } else if (this.startDate && date.compareDate(currDate, this.startDate) || this.endDate && date.compareDate(this.endDate, currDate)) {
          return "".concat(this.dayPrefix, "-disabled");
        } else if (this.isRange & this.currDate.length == 2 && date.compareDate(this.currDate[0], currDate) && date.compareDate(currDate, this.currDate[1])) {
          return "".concat(this.dayPrefix, "-choose");
        } else {
          return null;
        }
      } else {
        return "".concat(this.dayPrefix, "-disabled");
      }
    },
    chooseDay: function chooseDay(day, month, isFirst, isRange) {
      if (this.getClass(day, month, isRange) != "".concat(this.dayPrefix, "-disabled")) {
        var days = toConsumableArray_default()(month.curData);

        days = isRange ? days.splice(3) : days.splice(0, 3);
        days[2] = typeof day.day == 'number' ? date.getNumTwoBit(day.day) : day.day;
        days[3] = "".concat(days[0], "-").concat(days[1], "-").concat(days[2]);
        days[4] = date.getWhatDay(days[0], days[1], days[2]);

        if (!this.isRange) {
          this.currDate = days[3];
          this.chooseData = toConsumableArray_default()(days);
        } else {
          if (this.currDate.length == 2) {
            this.currDate = [days[3]];
          } else {
            if (date.compareDate(this.currDate[0], days[3])) {
              this.currDate.push(days[3]);
            } else {
              this.currDate.unshift(days[3]);
            }
          }

          if (this.chooseData.length == 2 || !this.chooseData.length) {
            this.chooseData = toConsumableArray_default()(days);
          } else {
            if (date.compareDate(this.chooseData[3], days[3])) {
              this.chooseData = [toConsumableArray_default()(this.chooseData), toConsumableArray_default()(days)];
            } else {
              this.chooseData = [toConsumableArray_default()(days), toConsumableArray_default()(this.chooseData)];
            }
          }
        }

        if (this.isAutoBackFill && !isFirst) {
          this.confirm();
        }
      }
    },
    confirm: function confirm() {
      if (this.isRange && this.chooseData.length == 2 || !this.isRange) {
        this.$emit('choose', this.chooseData);
        this.childIsVisible = false;
        this.$emit('update:is-visible', false);
      }
    },
    resetRender: function resetRender() {
      this.chooseData.splice(0);
      this.monthsData.splice(0);
      this.scrollDistance = 0;
      this.translateY = 0;
      this.setTransform(this.scrollDistance);
      this.initData();
    },
    closeActionSheet: function closeActionSheet() {
      this.childIsVisible = false;
      this.$emit('update:is-visible', false);
      this.$emit('close');
      this.resetRender();
    },
    touchStart: function touchStart(event) {
      var changedTouches = event.changedTouches[0];
      this.touchParams.startY = changedTouches.pageY;
      this.touchParams.startTime = event.timestamp || Date.now();
      this.transformY = this.scrollDistance;
    },
    touchMove: function touchMove(event) {
      //event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;

      if (Math.abs(move) < 5) {
        return false;
      }

      this.setMove(move);
    },
    touchEnd: function touchEnd(event) {
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;

      if (Math.abs(move) < 5) {
        return false;
      }

      var updateMove = move + this.transformY;
      var h = window.innerHeight || document.documentElement.clientHeight || document.body.clientHeight;
      var offsetHeight = this.$refs.months.offsetHeight;

      if (updateMove > 0) {
        this.getMonth(this.getCurrData('prev'), 'prev');
      } else if (updateMove < -offsetHeight + h * 2) {
        this.getMonth(this.getCurrData('next'), 'next');

        if (Math.abs(move) >= 300) {
          this.getMonth(this.getCurrData('next'), 'next');
        }
      }

      var moveTime = this.touchParams.lastTime - this.touchParams.startTime;

      if (moveTime <= 300) {
        move = move * 2;
        moveTime = moveTime + 1000;
        this.setMove(move, 'end', moveTime);
      } else {
        this.setMove(move, 'end');
      }
    },
    setTransform: function setTransform() {
      var translateY = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;
      var type = arguments.length > 1 ? arguments[1] : undefined;
      var time = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 1000;

      if (type === 'end') {
        this.$refs.months.style.webkitTransition = "transform ".concat(time, "ms cubic-bezier(0.19, 1, 0.22, 1)"); //this.$refs.months.style.transition = `transform ${time}ms cubic-bezier(0.19, 1, 0.22, 1)`;
      } else {
        this.$refs.months.style.webkitTransition = ''; //this.$refs.months.style.transition = '';
      }

      this.$refs.months.style.webkitTransform = "translateY(".concat(translateY, "px)"); //this.$refs.months.style.transform = `translateY(${translateY}px)`;

      this.scrollDistance = translateY;
    },
    setMove: function setMove(move, type, time) {
      var updateMove = move + this.transformY;
      var h = window.innerHeight || document.documentElement.clientHeight || document.body.clientHeight;
      var offsetHeight = this.$refs.months.offsetHeight;

      if (type === 'end') {
        // 限定滚动距离
        if (updateMove > 0) {
          updateMove = 0;
        }

        if (updateMove < 0 && updateMove < -offsetHeight + h - 70) {
          updateMove = -offsetHeight + h - 70;
        }

        if (offsetHeight <= h && this.monthsData.length == 1) {
          updateMove = 0;
        }

        var endMove = updateMove;
        this.setTransform(endMove, type, time);
      } else {
        if (updateMove > 0 && updateMove > 100) {
          updateMove = 100;
        }

        if (updateMove < -offsetHeight + h - 170 && this.monthsData.length > 1) {
          updateMove = -offsetHeight + h - 170;
        }

        if (updateMove < 0 && updateMove < -100 && this.monthsData.length == 1) {
          updateMove = -100;
        }

        this.setTransform(updateMove);
      }
    },
    initData: function initData() {
      this.startData = this.startDate ? this.splitDate(this.startDate) : null;
      this.endData = this.endDate ? this.splitDate(this.endDate) : null;

      if (!this.defaultValue) {
        this.currDate = this.isRange ? [date.date2Str(new Date()), date.getDay(2)] : date.date2Str(new Date());
      } else {
        this.currDate = this.isRange ? toConsumableArray_default()(this.defaultValue) : this.defaultValue;
      }

      if (this.isRange) {
        if (this.startDate && date.compareDate(this.currDate[0], this.startDate)) {
          this.currDate.splice(0, 1, this.startDate);
        }

        if (this.endDate && date.compareDate(this.endDate, this.currDate[1])) {
          this.currDate.splice(1, 1, this.endDate);
        }

        this.defaultData = [].concat(toConsumableArray_default()(this.splitDate(this.currDate[0])), toConsumableArray_default()(this.splitDate(this.currDate[1])));
      } else {
        if (this.startDate && date.compareDate(this.currDate, this.startDate)) {
          this.currDate = this.startDate;
        } else if (this.endDate && !date.compareDate(this.currDate, this.endDate)) {
          this.currDate = this.endDate;
        }

        this.defaultData = toConsumableArray_default()(this.splitDate(this.currDate));
      }

      this.getMonth(this.defaultData, 'next');
      var i = 1;

      do {
        this.getMonth(this.getCurrData('next'), 'next');
      } while (i++ < 4);

      if (this.isRange) {
        this.chooseDay({
          day: this.defaultData[2],
          type: 'curr'
        }, this.monthsData[0], true);
        this.chooseDay({
          day: this.defaultData[5],
          type: 'curr'
        }, this.monthsData[0], true, true);
      } else {
        this.chooseDay({
          day: this.defaultData[2],
          type: 'curr'
        }, this.monthsData[0], true);
      }
    }
  },
  mounted: function mounted() {
    this.initData();
  }
});
// CONCATENATED MODULE: ./src/packages/calendar/calendar.vue?vue&type=script&lang=js&
 /* harmony default export */ var calendar_calendarvue_type_script_lang_js_ = (calendarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/calendar/calendar.vue





/* normalize component */

var calendar_component = normalizeComponent(
  calendar_calendarvue_type_script_lang_js_,
  calendarvue_type_template_id_36c95750_render,
  calendarvue_type_template_id_36c95750_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var calendar = (calendar_component.exports);
// EXTERNAL MODULE: ./src/packages/calendar/calendar.scss
var calendar_calendar = __webpack_require__(30);

// CONCATENATED MODULE: ./src/packages/calendar/index.js



calendar.install = function (Vue) {
  Vue.component(calendar.name, calendar);
};

/* harmony default export */ var packages_calendar = (calendar);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/datepicker/datepicker.vue?vue&type=template&id=220f81c4&
var datepickervue_type_template_id_220f81c4_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('nut-picker',{attrs:{"is-visible":_vm.isVisible,"title":_vm.title,"list-data":_vm.listData,"default-value-data":_vm.defaultValueData,"custom-class-name":"nut-datepicker"},on:{"close":function($event){return _vm.switchPicker('isVisible')},"confirm":_vm.setChooseValue,"choose":_vm.updateChooseValue,"close-update":_vm.closeUpdateChooseValue}})}
var datepickervue_type_template_id_220f81c4_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/datepicker/datepicker.vue?vue&type=template&id=220f81c4&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/picker/picker.vue?vue&type=template&id=55164f84&
var pickervue_type_template_id_55164f84_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('nut-actionsheet',{attrs:{"is-visible":_vm.isVisible},on:{"close":_vm.closeActionSheet}},[_c('div',{staticClass:"nut-picker",class:_vm.customClassName ? _vm.customClassName : null,attrs:{"slot":"custom"},slot:"custom"},[_c('div',{staticClass:"nut-picker-control"},[_c('span',{staticClass:"nut-picker-cancel-btn",on:{"click":_vm.closeActionSheet}},[_vm._v(_vm._s(_vm.nutTranslate('lang.cancelBtnTxt')))]),_vm._v(" "),_c('div',{staticClass:"nut-picker-title"},[_vm._v(_vm._s(_vm.title ? _vm.title : ''))]),_vm._v(" "),_c('span',{staticClass:"nut-picker-confirm-btn",on:{"click":_vm.confirm}},[_vm._v(_vm._s(_vm.nutTranslate('lang.okBtnTxt')))])]),_vm._v(" "),_c('div',{staticClass:"nut-picker-panel"},[_vm._l((_vm.listData),function(item,index){return [_c('nut-picker-slot',{key:index,ref:("picker-slot-" + index),refInFor:true,attrs:{"default-value":_vm.chooseValueData[index],"is-update":_vm.isUpdate,"list-data":item,"key-index":index},on:{"chooseItem":_vm.chooseItem}})]})],2)])])}
var pickervue_type_template_id_55164f84_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/picker/picker.vue?vue&type=template&id=55164f84&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/picker/picker-slot.vue?vue&type=template&id=5cbc7e83&
var picker_slotvue_type_template_id_5cbc7e83_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-picker-list"},[_c('div',{ref:"roller",staticClass:"nut-picker-roller"},_vm._l((_vm.listData),function(item,index){return _c('div',{key:item.label ? item.label : index,staticClass:"nut-picker-roller-item",class:{ 'nut-picker-roller-item-hidden': _vm.isHidden(index + 1) },style:(_vm.setRollerStyle(index + 1))},[_vm._v("\n      "+_vm._s(item.value ? item.value : item)+"\n    ")])}),0),_vm._v(" "),_c('div',{staticClass:"nut-picker-content"},[_c('div',{ref:"list",staticClass:"nut-picker-list-panel"},[_vm._l((_vm.listData),function(item,index){return _c('div',{key:item.label ? item.label : index,staticClass:"nut-picker-item"},[_vm._v(_vm._s(item.value ? item.value : item)+"\n      ")])}),_vm._v(" "),(_vm.listData && _vm.listData.length === 1)?_c('div',{staticClass:"nut-picker-placeholder"}):_vm._e()],2)]),_vm._v(" "),_c('div',{staticClass:"nut-picker-mask"}),_vm._v(" "),_c('div',{staticClass:"nut-picker-indicator"})])}
var picker_slotvue_type_template_id_5cbc7e83_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/picker/picker-slot.vue?vue&type=template&id=5cbc7e83&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/picker/picker-slot.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var picker_slotvue_type_script_lang_js_ = ({
  name: 'nut-picker-slot',
  props: {
    listData: {
      type: Array,
      required: true
    },
    defaultValue: {
      type: String | Number
    },
    keyIndex: {
      type: Number,
      default: 0
    },
    isUpdate: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      touchParams: {
        startY: 0,
        endY: 0,
        startTime: 0,
        endTime: 0
      },
      currIndex: 1,
      transformY: 0,
      scrollDistance: 0,
      lineSpacing: 36,
      rotation: 20,
      timer: null
    };
  },
  watch: {
    isUpdate: function isUpdate() {
      this.transformY = 0;
      this.modifyStatus();
    },
    defaultValue: function defaultValue() {
      this.transformY = 0;
      this.modifyStatus();
    }
  },
  methods: {
    updateTransform: function updateTransform(value) {
      var _this = this;

      if (value) {
        this.transformY = 0;
        this.timer = setTimeout(function () {
          _this.modifyStatus(null, value);
        }, 10);
      }
    },
    setRollerStyle: function setRollerStyle(index) {
      return "transform: rotate3d(1, 0, 0, ".concat(-this.rotation * index, "deg) translate3d(0px, 0px, 104px)");
    },
    isHidden: function isHidden(index) {
      if (index >= this.currIndex + 8 || index <= this.currIndex - 8) {
        return true;
      } else {
        return false;
      }
    },
    setTransform: function setTransform() {
      var translateY = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;
      var type = arguments.length > 1 ? arguments[1] : undefined;
      var time = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 1000;
      var deg = arguments.length > 3 ? arguments[3] : undefined;

      if (type === 'end') {
        this.$refs.list.style.webkitTransition = "transform ".concat(time, "ms cubic-bezier(0.19, 1, 0.22, 1)");
        this.$refs.roller.style.webkitTransition = "transform ".concat(time, "ms cubic-bezier(0.19, 1, 0.22, 1)");
      } else {
        this.$refs.list.style.webkitTransition = '';
        this.$refs.roller.style.webkitTransition = '';
      }

      this.$refs.list.style.webkitTransform = "translate3d(0, ".concat(translateY, "px, 0)");
      this.$refs.roller.style.webkitTransform = "rotate3d(1, 0, 0, ".concat(deg, ")");
      this.scrollDistance = translateY;
    },
    setMove: function setMove(move, type, time) {
      var _this2 = this;

      var updateMove = move + this.transformY;

      if (type === 'end') {
        // 限定滚动距离
        if (updateMove > 0) {
          updateMove = 0;
        }

        if (updateMove < -(this.listData.length - 1) * this.lineSpacing) {
          updateMove = -(this.listData.length - 1) * this.lineSpacing;
        } // 设置滚动距离为lineSpacing的倍数值


        var endMove = Math.round(updateMove / this.lineSpacing) * this.lineSpacing;
        var deg = "".concat((Math.abs(Math.round(endMove / this.lineSpacing)) + 1) * this.rotation, "deg");
        this.setTransform(endMove, type, time, deg);
        this.timer = setTimeout(function () {
          _this2.setChooseValue(endMove);
        }, time / 2);
        this.currIndex = Math.abs(Math.round(endMove / this.lineSpacing)) + 1;
      } else {
        var _deg = '0deg';

        if (updateMove < 0) {
          _deg = "".concat((Math.abs(updateMove / this.lineSpacing) + 1) * this.rotation, "deg");
        } else {
          _deg = "".concat((-updateMove / this.lineSpacing + 1) * this.rotation, "deg");
        }

        this.setTransform(updateMove, null, null, _deg);
        this.currIndex = Math.abs(Math.round(updateMove / this.lineSpacing)) + 1;
      }
    },
    setChooseValue: function setChooseValue(move) {
      this.$emit('chooseItem', this.listData[Math.round(-move / this.lineSpacing)], this.keyIndex);
    },
    touchStart: function touchStart(event) {
      event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.startY = changedTouches.pageY;
      this.touchParams.startTime = event.timestamp || Date.now();
      this.transformY = this.scrollDistance;
    },
    touchMove: function touchMove(event) {
      event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;
      this.setMove(move);
    },
    touchEnd: function touchEnd(event) {
      event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;
      var moveTime = this.touchParams.lastTime - this.touchParams.startTime;

      if (moveTime <= 300) {
        move = move * 2;
        moveTime = moveTime + 1000;
        this.setMove(move, 'end', moveTime);
      } else {
        this.setMove(move, 'end');
      }
    },
    modifyStatus: function modifyStatus(type, defaultValue) {
      defaultValue = defaultValue ? defaultValue : this.defaultValue;
      var index = -1;

      if (defaultValue && defaultValue.value) {
        this.listData.some(function (item, idx) {
          if (item.value == defaultValue.value) {
            index = idx;
            return true;
          }
        });
      } else {
        index = this.listData.indexOf(defaultValue);
      }

      this.currIndex = index === -1 ? 1 : index + 1;
      var move = index === -1 ? 0 : index * this.lineSpacing;
      type && this.setChooseValue(-move);
      this.setMove(-move);
    }
  },
  mounted: function mounted() {
    var _this3 = this;

    this.$nextTick(function () {
      _this3.modifyStatus(true); // 监听


      _this3.$el.addEventListener('touchstart', _this3.touchStart);

      _this3.$el.addEventListener('touchmove', _this3.touchMove);

      _this3.$el.addEventListener('touchend', _this3.touchEnd);
    });
  },
  beforeDestroy: function beforeDestroy() {
    // 移除监听
    this.$el.removeEventListener('touchstart', this.touchStart);
    this.$el.removeEventListener('touchmove', this.touchMove);
    this.$el.removeEventListener('touchend', this.touchEnd);
    clearTimeout(this.timer);
  }
});
// CONCATENATED MODULE: ./src/packages/picker/picker-slot.vue?vue&type=script&lang=js&
 /* harmony default export */ var picker_picker_slotvue_type_script_lang_js_ = (picker_slotvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/picker/picker-slot.vue





/* normalize component */

var picker_slot_component = normalizeComponent(
  picker_picker_slotvue_type_script_lang_js_,
  picker_slotvue_type_template_id_5cbc7e83_render,
  picker_slotvue_type_template_id_5cbc7e83_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var picker_slot = (picker_slot_component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/picker/picker.vue?vue&type=script&lang=js&



var _components;

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//




/* harmony default export */ var pickervue_type_script_lang_js_ = ({
  name: 'nut-picker',
  mixins: [mixins_locale],
  props: {
    isVisible: {
      type: Boolean,
      default: false
    },
    customClassName: {
      type: String,
      default: null
    },
    title: {
      type: String,
      default: ' '
    },
    listData: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    defaultValueData: {
      type: Array,
      default: function _default() {
        return [];
      }
    }
  },
  components: (_components = {}, defineProperty_default()(_components, actionsheet.name, actionsheet), defineProperty_default()(_components, picker_slot.name, picker_slot), _components),
  data: function data() {
    return {
      chooseValueData: [],
      cacheValueData: [],
      isUpdate: false
    };
  },
  watch: {
    defaultValueData: function defaultValueData() {
      this.chooseValueData = toConsumableArray_default()(this.defaultValueData);
      this.cacheValueData = toConsumableArray_default()(this.defaultValueData);
      this.$emit('confirm', this.cacheValueData);
    }
  },
  methods: {
    updateChooseValue: function updateChooseValue(self, index, value) {
      self.cacheValueData.splice(index, 1, value);
      var ref = "picker-slot-".concat(index);
      self.$refs[ref] && self.$refs[ref][0].updateTransform(value);
    },
    closeActionSheet: function closeActionSheet() {
      this.isUpdate = !this.isUpdate;
      this.cacheValueData = toConsumableArray_default()(this.chooseValueData);
      this.$emit('close');
      this.$emit('close-update', this, this.chooseValueData);
    },
    confirm: function confirm() {
      this.$emit('confirm', this.cacheValueData);
      this.chooseValueData = toConsumableArray_default()(this.cacheValueData);
      this.$emit('close');
    },
    chooseItem: function chooseItem(value, index) {
      if (this.cacheValueData[index] !== value) {
        this.cacheValueData[index] = value;
        this.$emit('choose', this, index, value, this.cacheValueData);
      }
    }
  },
  created: function created() {
    if (this.defaultValueData && this.defaultValueData.length) {
      this.chooseValueData = toConsumableArray_default()(this.defaultValueData);
    } else {
      var defaultValueData = [];
      this.listData.map(function (item, index) {
        defaultValueData.push(item[0]);
      });
      this.chooseValueData = [].concat(defaultValueData);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/picker/picker.vue?vue&type=script&lang=js&
 /* harmony default export */ var picker_pickervue_type_script_lang_js_ = (pickervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/picker/picker.vue





/* normalize component */

var picker_component = normalizeComponent(
  picker_pickervue_type_script_lang_js_,
  pickervue_type_template_id_55164f84_render,
  pickervue_type_template_id_55164f84_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var picker = (picker_component.exports);
// EXTERNAL MODULE: ./src/packages/picker/picker.scss
var picker_picker = __webpack_require__(10);

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/datepicker/datepicker.vue?vue&type=script&lang=js&


//
//
//
//
//
//
//
//
//
//
//
//
//
//



/* harmony default export */ var datepickervue_type_script_lang_js_ = ({
  name: 'nut-datepicker',
  props: {
    type: {
      type: String,
      default: 'date'
    },
    isSetSecond: {
      type: Boolean,
      default: false
    },
    isVisible: {
      type: Boolean,
      default: true
    },
    isUse12Hours: {
      type: Boolean,
      default: false
    },
    isAm: {
      type: Boolean,
      default: true
    },
    minuteStep: {
      type: Number,
      default: 1
    },
    secondStep: {
      type: Number,
      default: 1
    },
    isShowChinese: {
      type: Boolean,
      default: true
    },
    title: {
      type: String,
      default: null
    },
    defaultValue: {
      type: String,
      default: null
    },
    startDate: {
      type: String,
      default: '2000-01-01'
    },
    endDate: {
      type: String,
      default: date.date2Str(new Date())
    },
    startHour: {
      type: Number | String,
      default: 0
    },
    endHour: {
      type: Number | String,
      default: 23
    }
  },
  data: function data() {
    return {
      listData: [],
      defaultValueData: null,
      startDateArr: null,
      endDateArr: null,
      startYear: null,
      endYear: null,
      cacheDefaultData: [],
      cacheListData: [],
      updateYear: null,
      updateMonth: null,
      updateDay: null,
      updateHour: null,
      use12Hours: ['上午', '下午'],
      chinese: !this.isShowChinese ? new Array(6).fill('') : this.type == 'time' ? this.isUse12Hours ? ['时', '分', ''] : ['时', '分', '秒'] : ['年', '月', '日', '时', '分']
    };
  },
  components: defineProperty_default()({}, picker.name, picker),
  created: function created() {
    this.init();
  },
  computed: {
    dateRange: function dateRange() {
      var startDate = this.startDate,
          endDate = this.endDate,
          defaultValue = this.defaultValue;
      return {
        startDate: startDate,
        endDate: endDate,
        defaultValue: defaultValue
      };
    }
  },
  watch: {
    dateRange: function dateRange(newValue, oldValue) {
      this.init();
    }
  },
  methods: {
    init: function init() {
      if (this.startDate && date.isDateString(this.startDate)) {
        this.startDateArr = date.getDateArr(this.startDate);
      } else {
        this.startDateArr = date.getDateArr('2000-01-01');
      }

      if (this.endDate && date.isDateString(this.endDate)) {
        this.endDateArr = date.getDateArr(this.endDate);
      } else {
        this.endDateArr = date.date2Str(new Date());
      } // 结束时间小于开始时间，结束时间重置为开始时间


      if (date.compareDateArr(this.endDateArr, this.startDateArr)) {
        // this.endDate = this.startDate;
        this.endDateArr = this.startDateArr;
      } // this.startDateArr = this.startDate.replace(/-/g, '/').split('/');
      // this.endDateArr = this.endDate.replace(/-/g, '/').split('/');


      this.initListData();
    },
    initListData: function initListData() {
      this.resetDefaultValue();

      switch (this.type) {
        case 'date':
          this.cacheListData = [this.getYears(), this.getMonths(this.defaultValueData[0]), this.getDays(this.defaultValueData[0], this.defaultValueData[1])].concat();
          break;

        case 'datetime':
          this.cacheListData = [this.getYears(), this.getMonths(this.defaultValueData[0]), this.getDays(this.defaultValueData[0], this.defaultValueData[1]), this.getChangeHours(this.defaultValueData[0], this.defaultValueData[1], this.defaultValueData[2]), this.getChangeMinutes(this.defaultValueData[0], this.defaultValueData[1], this.defaultValueData[2], this.defaultValueData[3])].concat();
          break;

        case 'time':
          this.cacheListData = [this.getHours(), this.getMinutes()].concat();

          if (this.isUse12Hours) {
            this.cacheListData = [].concat(toConsumableArray_default()(this.cacheListData), [this.use12Hours]);
          } else {
            this.cacheListData = this.isSetSecond ? [].concat(toConsumableArray_default()(this.cacheListData), [this.getSeconds()]) : toConsumableArray_default()(this.cacheListData);
          }

          break;
      }

      this.listData = toConsumableArray_default()(this.cacheListData);
    },
    resetDefaultValue: function resetDefaultValue() {
      var cacheDefaultValue = null;

      if (!this.defaultValue || !date.isDateString(this.defaultValue)) {
        switch (this.type) {
          case 'time':
            cacheDefaultValue = this.isSetSecond ? "00:00:00" : "00:00";
            break;

          case 'date':
          case 'datetime':
            cacheDefaultValue = "".concat(this.startDateArr[0], "-").concat(this.startDateArr[1], "-").concat(this.startDateArr[2], " ").concat(this.startDateArr[3], ":").concat(this.startDateArr[4]);
            break;
        }
      } else {
        cacheDefaultValue = this.defaultValue;
      }

      var splitArr = cacheDefaultValue.split(' ');

      if (this.type === 'time') {
        var timeArr = splitArr[0].split(':');
        this.isUse12Hours && timeArr.push(this.isAm ? this.use12Hours[0] : this.use12Hours[1]);
        this.cacheDefaultData = this.getCacheData(timeArr);
      } else {
        var cacheData = toConsumableArray_default()(splitArr[0].replace(/-/g, '/').split('/'));

        if (this.type == 'datetime') {
          cacheData = [].concat(toConsumableArray_default()(cacheData), toConsumableArray_default()(splitArr[1].split(':')));
        }

        this.cacheDefaultData = this.getCacheData(cacheData);
        this.updateYear = this.cacheDefaultData[0];
        this.updateMonth = this.cacheDefaultData[1];
        this.updateDay = this.cacheDefaultData[2];
        this.updateHour = this.cacheDefaultData[3];
      }

      this.defaultValueData = toConsumableArray_default()(this.cacheDefaultData);
    },
    getCacheData: function getCacheData(data) {
      var _this = this;

      var cacheData = [];
      data.map(function (item, index) {
        item < 10 && (item = item.replace(/^0/g, ''));
        cacheData.push("".concat(item).concat(_this.chinese[index]));
      });
      return cacheData;
    },
    getYears: function getYears() {
      var cacheYears = [];

      for (var i = this.startDateArr[0]; i <= this.endDateArr[0]; i++) {
        cacheYears.push("".concat(i).concat(this.chinese[0]));
      }

      return cacheYears;
    },
    getMonths: function getMonths(year) {
      year = this.removeChinese(year);
      var cacheMonths = [];

      for (var i = 1; i <= 12; i++) {
        if (!(year == this.startDateArr[0] && i < this.startDateArr[1]) && !(year == this.endDateArr[0] && i > this.endDateArr[1])) {
          cacheMonths.push("".concat(i).concat(this.chinese[1]));
        }
      }

      return cacheMonths;
    },
    getDays: function getDays(year, month) {
      var _this2 = this;

      year = this.removeChinese(year);
      month = this.removeChinese(month);
      var days = Array.from(Array(date.getMonthDays(year, month)), function (v, k) {
        if (!(year == _this2.startDateArr[0] && month == parseInt(_this2.startDateArr[1]) && k + 1 < parseInt(_this2.startDateArr[2])) && !(year == _this2.endDateArr[0] && month == parseInt(_this2.endDateArr[1]) && k + 1 > parseInt(_this2.endDateArr[2]))) {
          return "".concat(k + 1).concat(_this2.chinese[2]);
        }
      });
      return days.filter(function (item) {
        return item;
      });
    },
    getChangeHours: function getChangeHours(year, month, day) {
      var _this3 = this;

      year = this.removeChinese(year);
      month = this.removeChinese(month).padStart(2, '0');
      day = this.removeChinese(day).padStart(2, '0');
      var hours = Array.from(Array(24).keys()).map(function (hour) {
        var startEqualState = year == _this3.startDateArr[0] && month == _this3.startDateArr[1] && day == _this3.startDateArr[2];
        var endEqualState = year == _this3.endDateArr[0] && month == _this3.endDateArr[1] && day == _this3.endDateArr[2];
        var startHour = _this3.startDateArr[3],
            endHour = _this3.endDateArr[3];
        var resHour = undefined;

        if (startEqualState && endEqualState) {
          if (hour >= parseInt(startHour) && hour <= parseInt(endHour)) {
            resHour = hour;
          }
        } else if (startEqualState) {
          if (hour >= parseInt(startHour)) {
            resHour = hour;
          }
        } else if (endEqualState) {
          if (hour <= parseInt(endHour)) {
            resHour = hour;
          }
        } else {
          resHour = hour;
        }

        if (resHour == 0) {
          resHour = '0';
        }

        return resHour ? "".concat(resHour).concat(_this3.chinese[3]) : undefined;
      });
      return hours.filter(function (item) {
        return item;
      });
    },
    getChangeMinutes: function getChangeMinutes(year, month, day, hour) {
      var _this4 = this;

      year = this.removeChinese(year);
      month = this.removeChinese(month).padStart(2, '0');
      day = this.removeChinese(day).padStart(2, '0');
      hour = this.removeChinese(hour).padStart(2, '0');
      var minutes = Array.from(Array(60).keys()).map(function (minute) {
        var startEqualState = year == _this4.startDateArr[0] && month == _this4.startDateArr[1] && day == _this4.startDateArr[2] && hour == _this4.startDateArr[3];
        var endEqualState = year == _this4.endDateArr[0] && month == _this4.endDateArr[1] && day == _this4.endDateArr[2] && hour == _this4.endDateArr[3];
        var startMinute = _this4.startDateArr[4],
            endMinute = _this4.endDateArr[4];
        var resMinute = undefined;

        if (startEqualState && endEqualState) {
          if (minute >= parseInt(startMinute) && minute <= parseInt(endMinute)) {
            resMinute = minute;
          }
        } else if (startEqualState) {
          if (minute >= parseInt(startMinute)) {
            resMinute = minute;
          }
        } else if (endEqualState) {
          if (minute <= parseInt(endMinute)) {
            resMinute = minute;
          }
        } else {
          resMinute = minute;
        }

        if (resMinute == 0) {
          resMinute = '0';
        }

        return resMinute % _this4.minuteStep == 0 ? "".concat(resMinute).concat(_this4.chinese[4]) : undefined;
      });
      return minutes.filter(function (item) {
        return item;
      });
    },
    getHours: function getHours() {
      var _this5 = this;

      var endHour = this.endHour;

      if (this.isUse12Hours) {
        endHour = 11;
      }

      var hours = Array.from(Array(parseInt(endHour) + 1), function (v, k) {
        if (_this5.isUse12Hours && k == 0) {
          k = 12;
        }

        if (k >= _this5.startHour) {
          return "".concat(k).concat(_this5.type == 'time' ? _this5.chinese[0] : _this5.chinese[3]);
        }
      });
      return hours.filter(function (item) {
        return item;
      });
    },
    getMinutes: function getMinutes() {
      var _this6 = this;

      var minutes = Array.from(Array(60), function (v, k) {
        if (k == 0 || k % _this6.minuteStep == 0) {
          return "".concat(k).concat(_this6.type == 'time' ? _this6.chinese[1] : _this6.chinese[4]);
        }
      });
      return minutes.filter(function (item) {
        return item;
      });
    },
    getSeconds: function getSeconds() {
      var _this7 = this;

      var seconds = Array.from(Array(60), function (v, k) {
        if (k == 0 || k % _this7.secondStep == 0) {
          return "".concat(k).concat(_this7.type == 'time' ? _this7.chinese[2] : _this7.chinese[5]);
        }
      });
      return seconds.filter(function (item) {
        return item;
      });
    },
    setChooseValue: function setChooseValue(chooseData) {
      var _this8 = this;

      var cacheChooseData = [];
      chooseData.map(function (item, index) {
        if (_this8.isUse12Hours && _this8.type == 'time' && index == 2) {
          cacheChooseData.push(item);
        } else {
          cacheChooseData.push(date.getNumTwoBit(_this8.removeChinese(item)));
        }
      });

      if (/^date/.test(this.type)) {
        switch (this.type) {
          case 'date':
            cacheChooseData.push("".concat(cacheChooseData[0], "-").concat(cacheChooseData[1], "-").concat(cacheChooseData[2]));
            break;

          case 'datetime':
            cacheChooseData.push("".concat(cacheChooseData[0], "-").concat(cacheChooseData[1], "-").concat(cacheChooseData[2], " ").concat(cacheChooseData[3], ":").concat(cacheChooseData[4]));
            break;
        }

        var week = date.getWhatDay(cacheChooseData[0], cacheChooseData[1], cacheChooseData[2]);
        cacheChooseData.push(week);
      } else {
        cacheChooseData.push("".concat(cacheChooseData[0], ":").concat(cacheChooseData[1]).concat(this.isSetSecond ? ':' + cacheChooseData[2] : ''));
      }

      this.$emit('choose', cacheChooseData);
    },
    removeChinese: function removeChinese(value) {
      return value.toString().replace(/([^\u0000-\u00FF])/g, '');
    },
    updateLinkage: function updateLinkage(self, index, value, chooseValue, cacheValueData) {
      if (!value || !cacheValueData[index] || this.type == 'time') {
        return false;
      }

      value = this.removeChinese(value);

      switch (index) {
        case 1:
          //year
          this.updateYear = value;
          this.listData.splice(index, 1, this.getMonths(value));
          chooseValue = chooseValue ? chooseValue : cacheValueData[index];
          var curMonthsData = this.listData[index];

          if (curMonthsData.indexOf(chooseValue) === -1) {
            chooseValue = curMonthsData[0];
          }

          self && self.updateChooseValue(self, index, chooseValue);
          this.updateLinkage(self, 2, cacheValueData[index], null, cacheValueData);
          break;

        case 2:
          //month
          this.updateMonth = value;
          this.listData.splice(index, 1, this.getDays(parseInt(this.updateYear), value));
          chooseValue = chooseValue ? chooseValue : cacheValueData[index];
          var curDaysData = this.listData[index];

          if (curDaysData.indexOf(chooseValue) === -1) {
            if (curDaysData.length < 28) {
              chooseValue = curDaysData[0];
            } else {
              var curChooseDay = parseInt(this.removeChinese(chooseValue));
              var days = curDaysData.length;
              chooseValue = (curChooseDay > days ? days : curChooseDay) + this.chinese[2];
            }
          }

          self && self.updateChooseValue(self, index, chooseValue);
          this.updateLinkage(self, 3, cacheValueData[index], null, cacheValueData);
          break;

        case 3:
          //day
          this.updateDay = value;
          this.listData.splice(index, 1, this.getChangeHours(parseInt(this.updateYear), parseInt(this.updateMonth), value));
          chooseValue = chooseValue ? chooseValue : cacheValueData[index];
          var curHoursData = this.listData[index];

          if (curHoursData.indexOf(chooseValue) === -1) {
            chooseValue = curHoursData[0];
          }

          self && self.updateChooseValue(self, index, chooseValue);
          this.updateLinkage(self, 4, cacheValueData[index], null, cacheValueData);
          break;

        case 4:
          //hour
          this.updateHour = value;
          this.listData.splice(index, 1, this.getChangeMinutes(parseInt(this.updateYear), parseInt(this.updateMonth), parseInt(this.updateDay), parseInt(this.updateHour), value));
          chooseValue = chooseValue ? chooseValue : cacheValueData[index];
          var curMinuteData = this.listData[index];

          if (curMinuteData.indexOf(chooseValue) === -1) {
            chooseValue = curMinuteData[0];
          }

          self && self.updateChooseValue(self, index, chooseValue);
      }
    },
    updateChooseValue: function updateChooseValue(self, index, value, cacheValueData) {
      switch (index) {
        case 0: //year

        case 1: //month

        case 2: //day

        case 3:
          //hour
          this.updateLinkage(self, index + 1, value, null, cacheValueData);
          break;

        case 4:
          //min
          break;
      }
    },
    closeUpdateChooseValue: function closeUpdateChooseValue(self, chooseData) {
      this.updateLinkage(self, 1, chooseData[0], chooseData[1], chooseData);
    },
    switchPicker: function switchPicker(param) {
      this.$emit('close');
    }
  }
});
// CONCATENATED MODULE: ./src/packages/datepicker/datepicker.vue?vue&type=script&lang=js&
 /* harmony default export */ var datepicker_datepickervue_type_script_lang_js_ = (datepickervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/datepicker/datepicker.vue





/* normalize component */

var datepicker_component = normalizeComponent(
  datepicker_datepickervue_type_script_lang_js_,
  datepickervue_type_template_id_220f81c4_render,
  datepickervue_type_template_id_220f81c4_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var datepicker = (datepicker_component.exports);
// EXTERNAL MODULE: ./src/packages/datepicker/datepicker.scss
var datepicker_datepicker = __webpack_require__(31);

// CONCATENATED MODULE: ./src/packages/datepicker/index.js



datepicker.install = function (Vue) {
  Vue.component(datepicker.name, datepicker);
};

/* harmony default export */ var packages_datepicker = (datepicker);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/navbar/navbar.vue?vue&type=template&id=43684a05&
var navbarvue_type_template_id_43684a05_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-navbar"},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.leftShow),expression:"leftShow"}],staticClass:"nav-left"},[_c('div',{staticClass:"back",on:{"click":function($event){return _vm.$emit('on-click-back')}}},[_vm._t("back-icon",[_c('i',{staticClass:"back-icon"})])],2),_vm._v(" "),_vm._t("left")],2),_vm._v(" "),_c('div',{staticClass:"nav-center"},[_c('h3',{staticClass:"nav-title",on:{"click":function($event){return _vm.$emit('on-click-title')}}},[_vm._t("default",[_c('span',{directives:[{name:"show",rawName:"v-show",value:(_vm.title),expression:"title"}]},[_vm._v(_vm._s(_vm.title))])])],2)]),_vm._v(" "),_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.rightShow),expression:"rightShow"}],staticClass:"nav-right"},[_vm._t("right"),_vm._v(" "),_c('div',{staticClass:"more",on:{"click":function($event){return _vm.$emit('on-click-more')}}},[_vm._t("more-icon",[_c('i',{staticClass:"more-icon"})])],2)],2)])}
var navbarvue_type_template_id_43684a05_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/navbar/navbar.vue?vue&type=template&id=43684a05&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/navbar/navbar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var navbarvue_type_script_lang_js_ = ({
  name: 'nut-navbar',
  props: {
    title: {
      type: String,
      default: 'NavBar'
    },
    leftShow: {
      type: Boolean,
      default: true
    },
    rightShow: {
      type: Boolean,
      default: true
    }
  },
  data: function data() {
    return {};
  },
  methods: {
    onClickBack: function onClickBack() {
      // this.$emit('on-click-back');
      this.$router ? this.$router.back() : window.history.back();
    }
  }
});
// CONCATENATED MODULE: ./src/packages/navbar/navbar.vue?vue&type=script&lang=js&
 /* harmony default export */ var navbar_navbarvue_type_script_lang_js_ = (navbarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/navbar/navbar.vue





/* normalize component */

var navbar_component = normalizeComponent(
  navbar_navbarvue_type_script_lang_js_,
  navbarvue_type_template_id_43684a05_render,
  navbarvue_type_template_id_43684a05_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var navbar = (navbar_component.exports);
// EXTERNAL MODULE: ./src/packages/navbar/navbar.scss
var navbar_navbar = __webpack_require__(32);

// CONCATENATED MODULE: ./src/packages/navbar/index.js



navbar.install = function (Vue) {
  Vue.component(navbar.name, navbar);
};

/* harmony default export */ var packages_navbar = (navbar);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/noticebar/noticebar.vue?vue&type=template&id=e62265e2&
var noticebarvue_type_template_id_e62265e2_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.showNoticeBar),expression:"showNoticeBar"}],staticClass:"nut-noticebar",class:{ withicon: _vm.closeMode, close: _vm.closeMode, wrapable: _vm.wrapable },style:(_vm.barStyle),on:{"click":_vm.handleClick}},[(_vm.iconShow)?_c('div',{staticClass:"left-icon",style:({ 'background-image': ("url(" + _vm.iconBg + ")") })},[(!_vm.iconBg)?_c('nut-icon',{attrs:{"type":"notice","color":_vm.color,"size":"16px"}}):_vm._e()],1):_vm._e(),_vm._v(" "),_c('div',{ref:"wrap",staticClass:"wrap"},[_c('div',{ref:"content",staticClass:"content",class:[_vm.animationClass, { 'nut-ellipsis': !_vm.scrollable && !_vm.wrapable }],style:(_vm.contentStyle),on:{"animationend":_vm.onAnimationEnd,"webkitAnimationEnd":_vm.onAnimationEnd}},[_vm._t("default",[_vm._v(_vm._s(_vm.text))])],2)]),_vm._v(" "),(_vm.closeMode)?_c('div',{staticClass:"right-icon",on:{"click":function($event){$event.stopPropagation();return _vm.onClickIcon($event)}}},[_c('nut-icon',{attrs:{"type":"cross","color":_vm.color,"size":"11px"}})],1):_vm._e()])}
var noticebarvue_type_template_id_e62265e2_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/noticebar/noticebar.vue?vue&type=template&id=e62265e2&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/noticebar/noticebar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var noticebarvue_type_script_lang_js_ = ({
  name: 'nut-noticebar',
  props: {
    text: {
      type: String,
      default: ''
    },
    closeMode: {
      type: Boolean,
      default: false
    },
    wrapable: {
      type: Boolean,
      default: false
    },
    leftIcon: {
      type: String,
      default: ''
    },
    color: {
      type: String,
      default: '#F9911B'
    },
    background: {
      type: String,
      default: 'rgba(254,250,216,1)'
    },
    delay: {
      type: [String, Number],
      default: 1
    },
    scrollable: {
      type: Boolean,
      default: true
    },
    speed: {
      type: Number,
      default: 50
    }
  },
  data: function data() {
    return {
      wrapWidth: 0,
      firstRound: true,
      duration: 0,
      offsetWidth: 0,
      showNoticeBar: true,
      animationClass: ''
    };
  },
  computed: {
    iconShow: function iconShow() {
      if (this.leftIcon == 'close') {
        return false;
      } else {
        return true;
      }
    },
    barStyle: function barStyle() {
      return {
        color: this.color,
        background: this.background
      };
    },
    contentStyle: function contentStyle() {
      return {
        paddingLeft: this.firstRound ? 0 : this.wrapWidth + 'px',
        animationDelay: (this.firstRound ? this.delay : 0) + 's',
        animationDuration: this.duration + 's'
      };
    },
    iconBg: function iconBg() {
      var iconBg = null;

      if (this.leftIcon) {
        iconBg = this.leftIcon;
      }

      return iconBg;
    }
  },
  watch: {
    text: {
      handler: function handler(val, newVal) {
        var _this = this;

        // console.log(val, newVal, this.showNoticeBar == false, 'text');
        if (this.showNoticeBar == false) {
          return;
        }

        this.$nextTick(function () {
          var _this$$refs = _this.$refs,
              wrap = _this$$refs.wrap,
              content = _this$$refs.content;

          if (!wrap || !content) {
            return;
          }

          var wrapWidth = wrap.getBoundingClientRect().width;
          var offsetWidth = content.getBoundingClientRect().width; // console.log(wrapWidth, offsetWidth, 'text222');

          if (_this.scrollable && offsetWidth > wrapWidth) {
            _this.wrapWidth = wrapWidth;
            _this.offsetWidth = offsetWidth;
            _this.duration = offsetWidth / _this.speed;
            _this.animationClass = 'play';
          } else {
            _this.animationClass = '';
          }
        });
      },
      immediate: true
    }
  },
  methods: {
    handleClick: function handleClick(event) {
      this.$emit('click', event);
    },
    onClickIcon: function onClickIcon(event) {
      this.showNoticeBar = !this.closeMode;
      this.$emit('close', event);
    },
    onAnimationEnd: function onAnimationEnd() {
      var _this2 = this;

      this.firstRound = false;
      this.$nextTick(function () {
        _this2.duration = (_this2.offsetWidth + _this2.wrapWidth) / _this2.speed;
        _this2.animationClass = 'play-infinite';
      });
    }
  }
});
// CONCATENATED MODULE: ./src/packages/noticebar/noticebar.vue?vue&type=script&lang=js&
 /* harmony default export */ var noticebar_noticebarvue_type_script_lang_js_ = (noticebarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/noticebar/noticebar.vue





/* normalize component */

var noticebar_component = normalizeComponent(
  noticebar_noticebarvue_type_script_lang_js_,
  noticebarvue_type_template_id_e62265e2_render,
  noticebarvue_type_template_id_e62265e2_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var noticebar = (noticebar_component.exports);
// EXTERNAL MODULE: ./src/packages/noticebar/noticebar.scss
var noticebar_noticebar = __webpack_require__(33);

// CONCATENATED MODULE: ./src/packages/noticebar/index.js



noticebar.install = function (Vue) {
  Vue.component(noticebar.name, noticebar);
};

/* harmony default export */ var packages_noticebar = (noticebar);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/switch/switch.vue?vue&type=template&id=4b7a9d67&
var switchvue_type_template_id_4b7a9d67_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-switch",class:[{ 'nut-switch-active': _vm.isActive }, 'nut-switch-' + _vm.size, { 'nut-switch-disabled': _vm.disabled }],on:{"click":_vm.toggle}},[_c('div',{staticClass:"nut-switch-btn"}),_vm._v(" "),(_vm.isActive)?_c('div',{staticClass:"nut-switch-label"},[_vm._v(_vm._s(_vm.arrLabel[0]))]):_c('div',{staticClass:"nut-switch-label"},[_vm._v(_vm._s(_vm.arrLabel[1]))])])}
var switchvue_type_template_id_4b7a9d67_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/switch/switch.vue?vue&type=template&id=4b7a9d67&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/switch/switch.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
/* harmony default export */ var switchvue_type_script_lang_js_ = ({
  name: 'nut-switch',
  props: {
    active: {
      type: Boolean,
      default: false
    },
    size: {
      type: String,
      default: 'base'
    },
    disabled: {
      type: Boolean,
      default: false
    },
    label: {
      type: String,
      default: ''
    }
  },
  data: function data() {
    return {
      isActive: false,
      arrLabel: (this.label || '').split('|')
    };
  },
  created: function created() {
    this.isActive = this.active;
  },
  watch: {
    active: function active(newVal) {
      this.isActive = newVal;
    }
  },
  methods: {
    toggle: function toggle() {
      var _this = this;

      var status = this.isActive;

      if (!this.disabled) {
        this.isActive = !status;
        setTimeout(function () {
          _this.$emit('change', _this.isActive);

          _this.$emit('update:active', _this.isActive);
        }, 300);
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/switch/switch.vue?vue&type=script&lang=js&
 /* harmony default export */ var switch_switchvue_type_script_lang_js_ = (switchvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/switch/switch.vue





/* normalize component */

var switch_component = normalizeComponent(
  switch_switchvue_type_script_lang_js_,
  switchvue_type_template_id_4b7a9d67_render,
  switchvue_type_template_id_4b7a9d67_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var switch_switch = (switch_component.exports);
// EXTERNAL MODULE: ./src/packages/switch/switch.scss
var packages_switch_switch = __webpack_require__(34);

// CONCATENATED MODULE: ./src/packages/switch/index.js



switch_switch.install = function (Vue) {
  Vue.component(switch_switch.name, switch_switch);
};

/* harmony default export */ var packages_switch = (switch_switch);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/slider/slider.vue?vue&type=template&id=4a76a954&
var slidervue_type_template_id_4a76a954_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-slider"},[(_vm.showRangeTxt)?_c('div',{staticClass:"nut-slider-left-text"},[_vm._v(_vm._s(_vm.range[0]))]):_vm._e(),_vm._v(" "),_c('div',{staticClass:"nut-slider-box",on:{"click":_vm.onClick}},[_c('div',{class:['nut-slider-Handle', { 'nut-slider-ani': _vm.ani }],style:({ left: _vm.posi + 'px' }),on:{"touchstart":_vm.onTouchStart,"touchmove":_vm.onTouchMove,"touchend":_vm.onTouchEnd,"click":_vm.onTouchEnd,"touchcancel":_vm.onTouchEnd}},[(_vm.showLabel)?_c('span',{class:['nut-slider-label', { 'nut-slider-label-always': _vm.showLabelAlways }]},[_vm._v(_vm._s(_vm.current))]):_vm._e()])]),_vm._v(" "),(_vm.showRangeTxt)?_c('div',{staticClass:"nut-slider-right-text"},[_vm._v(_vm._s(_vm.range[1]))]):_vm._e()])}
var slidervue_type_template_id_4a76a954_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/slider/slider.vue?vue&type=template&id=4a76a954&

// CONCATENATED MODULE: ./src/utils/raf.js
function requestAniFrame() {
  if (typeof window !== 'undefined') {
    return window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame || function (callback) {
      window.setTimeout(callback, 1000 / 60);
    };
  } else {
    return function (callback) {
      setTimeout(callback, 1000 / 60);
    };
  }
}

/* harmony default export */ var raf = (requestAniFrame());
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/slider/slider.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var slidervue_type_script_lang_js_ = ({
  name: 'nut-slider',
  props: {
    value: {
      type: [String, Number]
    },
    showLabel: {
      type: Boolean,
      default: false
    },
    showLabelAlways: {
      type: Boolean,
      default: false
    },
    showRangeTxt: {
      type: Boolean,
      default: false
    },
    range: {
      type: Array,
      validator: function validator(value) {
        return value.length === 2 && value[1] > value[0];
      },
      default: function _default() {
        return [0, 10];
      }
    },
    stage: {
      type: [String, Number]
    }
  },
  data: function data() {
    return {
      box: null,
      boxLeft: 0,
      current: 0,
      handle: null,
      posi: null,
      level: null,
      ani: false,
      scheduledAnimationFrame: false
    };
  },
  computed: {
    total: function total() {
      return this.range[1] - this.range[0];
    },
    cell: function cell() {
      return this.total / this.level;
    }
  },
  methods: {
    onTouchStart: function onTouchStart(event) {
      if (event.cancelable) {
        event.preventDefault();
      }

      this.ani = true;
    },
    onTouchMove: function onTouchMove(event) {
      var _this = this;

      if (event.cancelable) {
        event.preventDefault();
      }

      if (this.scheduledAnimationFrame) return;
      this.scheduledAnimationFrame = true;
      raf(function () {
        _this.scheduledAnimationFrame = false;
        var evt = event.touches[0];
        var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
        _this.boxLeft = _this.box.getBoundingClientRect().left;
        var posi = evt.pageX - _this.boxLeft - pageScrollLeft;

        _this.setPosi(posi);
      });
    },
    setVal: function setVal(posi) {
      var trans = posi / this.box.clientWidth * this.total;
      this.current = Math.round(trans / this.cell) * this.cell + this.range[0];
      this.$emit('input', this.current);
    },
    valToPosi: function valToPosi() {
      return (this.current - this.range[0]) * (this.box.clientWidth / this.total);
    },
    setPosi: function setPosi(posi) {
      if (posi < 0 || posi > this.box.clientWidth) return;
      this.posi = posi;
      this.setVal(posi);
    },
    onTouchEnd: function onTouchEnd(event) {
      if (event.cancelable) {
        event.preventDefault();
      }

      this.posi = this.valToPosi();
      this.ani = false;
    },
    onClick: function onClick(event) {
      if (event.cancelable) {
        event.preventDefault();
      }

      var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
      this.boxLeft = this.box.getBoundingClientRect().left;
      var posi = event.pageX - this.boxLeft - pageScrollLeft;
      this.setVal(posi);
      this.posi = this.valToPosi();
    },
    propInit: function propInit() {
      if (this.value !== 'undefined' && this.value >= this.range[0] && this.value <= this.range[1]) {
        this.current = this.value;
      } else {
        this.current = this.range[0];
      }

      if (!this.stage || this.stage > this.range[1] - this.range[0]) {
        this.level = this.range[1] - this.range[0];
      } else {
        this.level = this.stage;
      }

      this.posi = this.valToPosi();
    }
  },
  mounted: function mounted() {
    var _this2 = this;

    this.$nextTick(function () {
      _this2.box = _this2.$el.querySelector('.nut-slider-box');
      _this2.handle = _this2.box.querySelector('.nut-slider-Handle');

      _this2.propInit();
    });
  }
});
// CONCATENATED MODULE: ./src/packages/slider/slider.vue?vue&type=script&lang=js&
 /* harmony default export */ var slider_slidervue_type_script_lang_js_ = (slidervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/slider/slider.vue





/* normalize component */

var slider_component = normalizeComponent(
  slider_slidervue_type_script_lang_js_,
  slidervue_type_template_id_4a76a954_render,
  slidervue_type_template_id_4a76a954_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var slider = (slider_component.exports);
// EXTERNAL MODULE: ./src/packages/slider/slider.scss
var slider_slider = __webpack_require__(35);

// CONCATENATED MODULE: ./src/packages/slider/index.js



slider.install = function (Vue) {
  Vue.component(slider.name, slider);
};

/* harmony default export */ var packages_slider = (slider);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/range/range.vue?vue&type=template&id=ff279bd4&
var rangevue_type_template_id_ff279bd4_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-range"},[(_vm.showRangeTxt)?_c('div',{staticClass:"nut-range-left-text"},[_vm._v(_vm._s(_vm.range[0]))]):_vm._e(),_vm._v(" "),_c('div',{staticClass:"nut-range-box",style:({ background: _vm.boxColor }),on:{"click":_vm.onClick}},[_c('div',{staticClass:"nut-range-area",style:({
        width: Math.abs(_vm.barleft2 - _vm.barleft1) + 'px',
        left: Math.min(_vm.barleft2, _vm.barleft1) + 'px',
        background: _vm.mainColor
      })}),_vm._v(" "),_c('nut-range-bar',{attrs:{"direction":"left","stage":_vm.stage,"range":_vm.range,"values":_vm.rangeValues,"initLeft":_vm.initLeft1,"showLabelAlways":_vm.showLabelAlways,"showLabel":_vm.showLabel,"current":_vm.currentLeft,"ani":_vm.ani,"mainColor":_vm.mainColor},on:{"getPos":_vm.getPosLeft,"update:ani":function($event){_vm.ani=$event}}}),_vm._v(" "),_c('nut-range-bar',{attrs:{"direction":"right","stage":_vm.stage,"range":_vm.range,"values":_vm.rangeValues,"initLeft":_vm.initLeft2,"showLabelAlways":_vm.showLabelAlways,"showLabel":_vm.showLabel,"current":_vm.currentRight,"ani":_vm.ani,"mainColor":_vm.mainColor},on:{"getPos":_vm.getPosRight,"update:ani":function($event){_vm.ani=$event}}})],1),_vm._v(" "),(_vm.showRangeTxt)?_c('div',{staticClass:"nut-range-right-text"},[_vm._v(_vm._s(_vm.range[1]))]):_vm._e()])}
var rangevue_type_template_id_ff279bd4_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/range/range.vue?vue&type=template&id=ff279bd4&

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/slicedToArray.js
var slicedToArray = __webpack_require__(5);
var slicedToArray_default = /*#__PURE__*/__webpack_require__.n(slicedToArray);

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/range/movebar.vue?vue&type=template&id=5c64d29d&
var movebarvue_type_template_id_5c64d29d_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-range-Handle', { 'nut-range-ani': _vm.ani }],style:({ left: _vm.posi + 'px', borderColor: _vm.mainColor, boxShadow: _vm.ani ? '0 0 0 4px ' + _vm.subColor : '' }),on:{"touchstart":_vm.onTouchStart,"touchmove":_vm.onTouchMove,"touchend":_vm.onTouchEnd,"click":_vm.onTouchEnd}},[(_vm.showLabel)?_c('span',{class:['nut-range-label', { 'nut-range-label-always': _vm.showLabelAlways }],style:({ background: _vm.mainColor })},[_c('span',{staticClass:"nut-range-after",style:({ color: _vm.mainColor })},[_vm._v("▼")]),_vm._v("\n    "+_vm._s(_vm.current)+"\n  ")]):_vm._e()])}
var movebarvue_type_template_id_5c64d29d_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/range/movebar.vue?vue&type=template&id=5c64d29d&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/range/movebar.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var movebarvue_type_script_lang_js_ = ({
  name: 'nut-range-bar',
  props: {
    direction: {
      type: String,
      default: 'left'
    },
    range: {
      type: Array,
      validator: function validator(value) {
        return value.length === 2 && value[1] > value[0];
      },
      default: function _default() {
        return [0, 10];
      }
    },
    values: {
      type: Array,
      validator: function validator(value) {
        return value.length === 2 && value[1] >= value[0];
      },
      default: function _default() {
        return [0, 0];
      }
    },
    initLeft: {
      type: Number,
      default: 0
    },
    showLabelAlways: {
      type: Boolean,
      default: false
    },
    showLabel: {
      type: Boolean,
      default: false
    },
    current: {
      type: Number,
      default: 0
    },
    stage: {
      type: Number,
      default: 0
    },
    ani: Boolean,
    mainColor: String,
    subColor: String
  },
  data: function data() {
    return {
      box: null,
      posi: 0,
      scheduledAnimationFrame: false
    };
  },
  watch: {
    initLeft: function initLeft(val) {
      this.posi = this.initLeft;
    }
  },
  computed: {
    total: function total() {
      return this.range[1] - this.range[0];
    }
  },
  methods: {
    onTouchStart: function onTouchStart(event) {
      if (event.cancelable) {
        event.preventDefault();
      }

      this.$emit('update:ani', true);
    },
    onTouchMove: function onTouchMove(event) {
      var _this = this;

      if (event.cancelable) {
        event.preventDefault();
      }

      if (this.scheduledAnimationFrame) return;
      this.scheduledAnimationFrame = true;
      raf(function () {
        _this.scheduledAnimationFrame = false;
        var evt = event.touches[0];
        var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
        _this.boxLeft = _this.box.getBoundingClientRect().left;
        var posi = evt.pageX - _this.boxLeft - pageScrollLeft;

        _this.setPosi(posi, false);
      });
    },
    setPosi: function setPosi(posi, isEnd) {
      if (posi < 0) {
        posi = 0;
      }

      if (posi > this.box.clientWidth) {
        posi = this.box.clientWidth;
      }

      var _this$values = slicedToArray_default()(this.values, 2),
          prevLeft = _this$values[0],
          prevRight = _this$values[1];

      var _this$range = slicedToArray_default()(this.range, 2),
          rangeLeft = _this$range[0],
          rangeRight = _this$range[1];

      if (this.direction === 'left') {
        var maxRight = prevRight - rangeLeft - 1;

        if (posi / this.box.clientWidth >= maxRight / this.total) {
          this.posi = maxRight * (this.box.clientWidth / this.total);
        } else {
          this.posi = posi;
        }
      }

      if (this.direction === 'right') {
        var minLeft = prevLeft - rangeLeft + 1;

        if (posi / this.box.clientWidth <= minLeft / this.total) {
          this.posi = minLeft * (this.box.clientWidth / this.total);
        } else {
          this.posi = posi;
        }
      }

      this.$emit('getPos', this.posi, isEnd);
    },
    onTouchEnd: function onTouchEnd(event) {
      var _this2 = this;

      event.preventDefault();
      var evt = event.changedTouches[0];
      var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
      this.boxLeft = this.box.getBoundingClientRect().left;
      var posi = evt.pageX - this.boxLeft - pageScrollLeft;
      setTimeout(function () {
        _this2.setPosi(posi, true);

        _this2.$emit('update:ani', false);
      }, 50);
    },
    onClick: function onClick(event) {
      event.preventDefault();
      var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
      this.boxLeft = this.box.getBoundingClientRect().left;
      var posi = event.pageX - this.boxLeft - pageScrollLeft;
      this.posi = posi;
      this.$emit('getPos', posi);
    }
  },
  mounted: function mounted() {
    this.box = this.$el.parentNode;
  }
});
// CONCATENATED MODULE: ./src/packages/range/movebar.vue?vue&type=script&lang=js&
 /* harmony default export */ var range_movebarvue_type_script_lang_js_ = (movebarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/range/movebar.vue





/* normalize component */

var movebar_component = normalizeComponent(
  range_movebarvue_type_script_lang_js_,
  movebarvue_type_template_id_5c64d29d_render,
  movebarvue_type_template_id_5c64d29d_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var movebar = (movebar_component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/range/range.vue?vue&type=script&lang=js&


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


function toRGBA(c, opacity) {
  // 16进制、rgb颜色转rgba
  var reg = /(rgb)(\(\d+,\s*\d+,\s*\d+)(\))/;
  if (reg.test(c)) return c.replace(reg, '$1' + (opacity ? 'a' : '') + '$2' + (opacity ? ',' + opacity : '') + '$3');

  if (/^#[0-9a-f]+/.test(c)) {
    if (c.length === 4) {
      c = c.replace(/^#(\d)(\d)(\d)/, '#$1$1$2$2$3$3');
    }

    if (c.length === 7) {
      return toRGBA('rgb(' + parseInt(c.slice(1, 3), 16) + ', ' + parseInt(c.slice(3, 5), 16) + ', ' + parseInt(c.slice(5, 7), 16) + ')', opacity);
    }
  }

  return toRGBA('#ff0000', opacity);
}


/* harmony default export */ var rangevue_type_script_lang_js_ = ({
  name: 'nut-range',
  components: defineProperty_default()({}, movebar.name, movebar),
  props: {
    rangeValues: {
      type: Array,
      validator: function validator(value) {
        return value.length === 2 && value[1] >= value[0];
      },
      default: function _default() {
        return [0, 0];
      }
    },
    color: String,
    showLabel: {
      type: Boolean,
      default: false
    },
    showLabelAlways: {
      type: Boolean,
      default: false
    },
    showRangeTxt: {
      type: Boolean,
      default: false
    },
    range: {
      type: Array,
      validator: function validator(value) {
        return value.length === 2 && value[1] > value[0];
      },
      default: function _default() {
        return [0, 10];
      }
    },
    stage: {
      type: Number,
      default: 1
    }
  },
  data: function data() {
    return {
      box: null,
      boxLeft: 0,
      initLeft1: 0,
      initLeft2: 0,
      currentLeft: 0,
      currentRight: 0,
      barleft1: 0,
      barleft2: 0,
      level: null,
      ani: false,
      prevValues: []
    };
  },
  watch: {
    range: function range() {
      this.init();
    },
    rangeValues: function rangeValues() {
      this.init();
    },
    ani: function ani(flag) {
      if (flag) {
        this.prevValues = this.rangeValues;
      }
    }
  },
  computed: {
    total: function total() {
      return this.range[1] - this.range[0];
    },
    cell: function cell() {
      return this.total / this.level;
    },
    mainColor: function mainColor() {
      return this.color ? toRGBA(this.color) : '';
    },
    boxColor: function boxColor() {
      return this.color ? toRGBA(this.color, 0.3) : '';
    },
    subColor: function subColor() {
      return this.color ? toRGBA(this.color, 0.5) : '';
    }
  },
  methods: {
    init: function init() {
      this.box = this.$el.querySelector('.nut-range-box');
      this.propInit();
    },
    updateRangeValues: function updateRangeValues() {
      var rangeValues = [this.currentLeft, this.currentRight];
      this.$emit('update:rangeValues', rangeValues);
    },
    getPosLeft: function getPosLeft(pos, isEnd) {
      this.barleft1 = pos;
      var currentLeft = this.setCurrent(pos);

      var _this$prevValues = slicedToArray_default()(this.prevValues, 2),
          prevLeft = _this$prevValues[0],
          prevRight = _this$prevValues[1];

      if (isEnd) {
        if (this.stage) {
          var stageNum = 0;

          if (currentLeft > prevLeft) {
            stageNum = Math.ceil(currentLeft / this.stage);
          } else {
            stageNum = Math.floor(currentLeft / this.stage);
          }

          this.currentLeft = stageNum * this.stage;
        } else {
          this.currentLeft = currentLeft;
        }
      } else {
        this.currentLeft = currentLeft;
      }

      if (isEnd) {
        this.updateRangeValues();
      }
    },
    getPosRight: function getPosRight(pos, isEnd) {
      this.barleft2 = pos;
      var currentRight = this.setCurrent(pos);

      var _this$prevValues2 = slicedToArray_default()(this.prevValues, 2),
          prevLeft = _this$prevValues2[0],
          prevRight = _this$prevValues2[1];

      if (isEnd) {
        if (this.stage) {
          var stageNum = 0;

          if (currentRight > prevRight) {
            stageNum = Math.ceil(currentRight / this.stage);
          } else {
            stageNum = Math.floor(currentRight / this.stage);
          }

          this.currentRight = stageNum * this.stage;
        } else {
          this.currentRight = currentRight;
        }
      } else {
        this.currentRight = currentRight;
      }

      if (isEnd) {
        this.updateRangeValues();
      }
    },
    setCurrent: function setCurrent(posi) {
      var trans = posi / this.box.clientWidth * this.total;
      var current = trans / this.cell * this.cell + this.range[0];
      return current > this.range[1] - 1 ? this.range[1] : current < this.range[0] + 1 ? this.range[0] : Math.round(current);
    },
    setVal: function setVal(posi) {
      var trans = posi / this.box.clientWidth * this.total;
      this.current = Math.round(trans / this.cell) * this.cell + this.range[0];
      this.$emit('update:value', this.current);
    },
    valToPosi: function valToPosi(current) {
      var pos = (current - this.range[0]) * (this.box.clientWidth / this.total);
      return pos;
    },
    setPosi: function setPosi(posi) {
      if (posi < 0 || posi > this.box.clientWidth) return;
      this.posi = posi;
      this.setVal(posi);
    },
    onClick: function onClick(event) {
      event.preventDefault();
      var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
      this.boxLeft = this.box.getBoundingClientRect().left;
      var posi = event.pageX - this.boxLeft - pageScrollLeft;
      this.setVal(posi);
      this.posi = this.valToPosi();
    },
    propInit: function propInit() {
      if (!this.stage || this.stage > this.range[1] - this.range[0]) {
        this.level = this.range[1] - this.range[0];
      } else {
        this.level = this.stage;
      }

      this.currentLeft = Math.max(this.rangeValues[0], this.range[0]);
      this.currentRight = Math.max(this.currentLeft, Math.min(this.rangeValues[1], this.range[1]));
      this.initLeft1 = this.valToPosi(this.currentLeft);
      this.initLeft2 = this.valToPosi(this.currentRight);
      this.barleft1 = this.initLeft1;
      this.barleft2 = this.initLeft2;
    }
  },
  mounted: function mounted() {
    var _this = this;

    this.$nextTick(function () {
      _this.init();
    });
  }
});
// CONCATENATED MODULE: ./src/packages/range/range.vue?vue&type=script&lang=js&
 /* harmony default export */ var range_rangevue_type_script_lang_js_ = (rangevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/range/range.vue





/* normalize component */

var range_component = normalizeComponent(
  range_rangevue_type_script_lang_js_,
  rangevue_type_template_id_ff279bd4_render,
  rangevue_type_template_id_ff279bd4_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var range = (range_component.exports);
// EXTERNAL MODULE: ./src/packages/range/range.scss
var range_range = __webpack_require__(36);

// CONCATENATED MODULE: ./src/packages/range/index.js



range.install = function (Vue) {
  Vue.component(range.name, range);
};

/* harmony default export */ var packages_range = (range);
// CONCATENATED MODULE: ./src/packages/picker/index.js



picker.install = function (Vue) {
  Vue.component(picker.name, picker);
};

/* harmony default export */ var packages_picker = (picker);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/progress/progress.vue?vue&type=template&id=7abe3814&
var progressvue_type_template_id_7abe3814_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-progress"},[_c('div',{staticClass:"nut-progress-outer",class:[_vm.showText && !_vm.textInside ? 'nut-progress-outer-part' : '', 'nut-progress-' + _vm.size],style:({ height: _vm.height })},[_c('div',{class:['nut-progress-inner', _vm.status == 'active' ? 'nut-active' : ''],style:(_vm.bgStyle)},[(_vm.showText && _vm.textInside)?_c('div',{staticClass:"nut-progress-text",style:({ lineHeight: _vm.height })},[_c('span',{style:(_vm.textStyle)},[_vm._v(_vm._s(_vm.percentage)+"%")])]):_vm._e()])]),_vm._v(" "),(_vm.showText && !_vm.textInside)?_c('div',{staticClass:"nut-progress-text",style:({ lineHeight: _vm.height })},[_vm._t("default",[(_vm.status == 'text' || _vm.status == 'active')?[_c('span',{style:(_vm.textStyle)},[_vm._v(_vm._s(_vm.percentage)+"%")])]:(_vm.status == 'success' || 'wrong')?[_c('i',{class:_vm.statusIcon})]:_vm._e()])],2):_vm._e()])}
var progressvue_type_template_id_7abe3814_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/progress/progress.vue?vue&type=template&id=7abe3814&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/progress/progress.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var progressvue_type_script_lang_js_ = ({
  name: 'nut-progress',
  props: {
    percentage: {
      type: [Number, String],
      default: 0,
      required: true
    },
    size: {
      type: String,
      default: ''
    },
    status: {
      type: String,
      default: 'text'
    },
    strokeWidth: {
      type: [Number, String],
      default: ''
    },
    textInside: {
      type: Boolean,
      default: false
    },
    showText: {
      type: Boolean,
      default: true
    },
    strokeColor: {
      type: String,
      default: ''
    },
    textColor: {
      tyep: String,
      default: ''
    }
  },
  data: function data() {
    return {
      height: this.strokeWidth + 'px'
    };
  },
  computed: {
    bgStyle: function bgStyle() {
      return {
        width: this.percentage + '%',
        backgroundColor: this.strokeColor || ''
      };
    },
    textStyle: function textStyle() {
      return {
        color: this.textColor || ''
      };
    },
    statusIcon: function statusIcon() {
      return this.status === 'success' ? 'nut-icon-success' : this.status === 'wrong' ? 'nut-icon-fail' : '';
    }
  }
});
// CONCATENATED MODULE: ./src/packages/progress/progress.vue?vue&type=script&lang=js&
 /* harmony default export */ var progress_progressvue_type_script_lang_js_ = (progressvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/progress/progress.vue





/* normalize component */

var progress_component = normalizeComponent(
  progress_progressvue_type_script_lang_js_,
  progressvue_type_template_id_7abe3814_render,
  progressvue_type_template_id_7abe3814_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var progress = (progress_component.exports);
// EXTERNAL MODULE: ./src/packages/progress/progress.scss
var progress_progress = __webpack_require__(37);

// CONCATENATED MODULE: ./src/packages/progress/index.js



progress.install = function (Vue) {
  Vue.component(progress.name, progress);
};

/* harmony default export */ var packages_progress = (progress);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/price/price.vue?vue&type=template&id=039bfd33&
var pricevue_type_template_id_039bfd33_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-price",domProps:{"innerHTML":_vm._s(_vm.priceShow)}},[_c('span')])}
var pricevue_type_template_id_039bfd33_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/price/price.vue?vue&type=template&id=039bfd33&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/price/price.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var pricevue_type_script_lang_js_ = ({
  name: 'nut-price',
  props: {
    price: {
      type: [Number, String],
      default: 0
    },
    needSymbol: {
      type: Boolean,
      default: true
    },
    decimalDigits: {
      type: [Number, String],
      default: 2
    },
    thousands: {
      type: Boolean,
      default: false
    }
  },
  computed: {
    priceShow: function priceShow() {
      var self = this;
      var symbol = self.needSymbol ? '<span class="price-symbol">￥</span>' : '';
      return symbol + self.formatToHump(self.price);
    }
  },
  data: function data() {
    return {};
  },
  methods: {
    //判断是否为小数点
    checkPoint: function checkPoint(num) {
      return String(num).indexOf('.') > 0;
    },
    //将数字转换成驼峰形式
    formatToHump: function formatToHump(num) {
      var self = this;
      num = String(num).replace('￥', '');

      if (self.checkPoint(num)) {
        var numArray = Number(num).toFixed(this.decimalDigits);
        numArray = String(numArray).split('.');
        return '<span class="price-big">' + self.formatThousands(numArray[0]) + '</span><span class="price-point">.</span><span class="price-small">' + self.formatDecimal(numArray[1]) + '</span>';
      } else {
        return '<span class="price-big">' + self.formatThousands(num) + '</span><span class="price-point">.</span><span class="price-small">' + self.formatDecimal(0) + '</span>';
      }
    },
    //根据小数位数格式化小数部分
    formatDecimal: function formatDecimal(decimalNum) {
      var self = this;
      var decimalDigits = self.decimalDigits;
      var result = '0.' + String(decimalNum);
      var resultFixed = (result / 1).toFixed(decimalDigits);
      return String(resultFixed).substring(2, resultFixed.length);
    },
    //千分位显示
    formatThousands: function formatThousands(num) {
      var self = this;
      var result = ''; // let

      if (self.thousands) {
        return (num || 0).toString().replace(/(\d)(?=(?:\d{3})+$)/g, '$1,');
      } else {
        return num;
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/price/price.vue?vue&type=script&lang=js&
 /* harmony default export */ var price_pricevue_type_script_lang_js_ = (pricevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/price/price.vue





/* normalize component */

var price_component = normalizeComponent(
  price_pricevue_type_script_lang_js_,
  pricevue_type_template_id_039bfd33_render,
  pricevue_type_template_id_039bfd33_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var price = (price_component.exports);
// EXTERNAL MODULE: ./src/packages/price/price.scss
var price_price = __webpack_require__(38);

// CONCATENATED MODULE: ./src/packages/price/index.js



price.install = function (Vue) {
  Vue.component(price.name, price);
};

/* harmony default export */ var packages_price = (price);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/row/row.vue?vue&type=template&id=e4176690&
var rowvue_type_template_id_e4176690_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-row",class:_vm.getClassObject()},[_vm._t("default")],2)}
var rowvue_type_template_id_e4176690_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/row/row.vue?vue&type=template&id=e4176690&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/row/row.vue?vue&type=script&lang=js&

//
//
//
//
//
/* harmony default export */ var rowvue_type_script_lang_js_ = ({
  name: 'nut-row',
  props: {
    type: {
      type: String,
      default: ''
    },
    gutter: {
      type: [String, Number],
      default: ''
    },
    tag: {
      type: String,
      default: 'div'
    },
    justify: {
      type: String,
      default: 'start'
    },
    align: {
      type: String,
      default: 'flex-start'
    },
    flexWrap: {
      type: String,
      default: 'nowrap'
    }
  },
  computed: {
    getGutter: function getGutter() {
      return "".concat(this.gutter, "px");
    }
  },
  methods: {
    initCol: function initCol(slot) {
      for (var i = 0; i < slot.length; i++) {
        var tag = slot[i].tag;

        if (typeof tag == 'string') {
          if (tag.indexOf('nut-col') != -1) {
            var slotElm = slot[i].elm;
            slotElm.style.paddingLeft = this.getGutter;
            slotElm.style.paddingRight = this.getGutter;
          }
        }
      }
    },
    getClass: function getClass(prefix, type) {
      return prefix ? type ? "nut-row-".concat(prefix, "-").concat(type) : '' : "nut-row-".concat(type);
    },
    getClassObject: function getClassObject() {
      return "\n                ".concat(this.getClass('', this.type), "  \n                ").concat(this.getClass('justify', this.justify), " \n                ").concat(this.getClass('align', this.align), " \n                ").concat(this.getClass('flex', this.flexWrap), "\n                ");
    }
  },
  mounted: function mounted() {
    var slot = toConsumableArray_default()(this.$slots.default);

    this.initCol(slot);
  }
});
// CONCATENATED MODULE: ./src/packages/row/row.vue?vue&type=script&lang=js&
 /* harmony default export */ var row_rowvue_type_script_lang_js_ = (rowvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/row/row.vue





/* normalize component */

var row_component = normalizeComponent(
  row_rowvue_type_script_lang_js_,
  rowvue_type_template_id_e4176690_render,
  rowvue_type_template_id_e4176690_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var row = (row_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/col/col.vue?vue&type=template&id=8b626f72&
var colvue_type_template_id_8b626f72_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-col",class:_vm.classObject},[_vm._t("default")],2)}
var colvue_type_template_id_8b626f72_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/col/col.vue?vue&type=template&id=8b626f72&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/col/col.vue?vue&type=script&lang=js&


//
//
//
//
//
/* harmony default export */ var colvue_type_script_lang_js_ = ({
  name: 'nut-col',
  props: {
    span: {
      type: [String, Number],
      default: '24'
    },
    offset: {
      type: [String, Number],
      default: '0'
    }
  },
  data: function data() {
    return {
      classObject: {}
    };
  },
  watch: {
    span: {
      handler: function handler(val) {
        if (val) {
          this.classObject = extends_default()(this.classObject, defineProperty_default()({}, 'nut-col-' + val, this.span == val));
        }
      },
      immediate: true
    },
    offset: {
      handler: function handler(val) {
        if (val) {
          this.classObject = extends_default()(this.classObject, defineProperty_default()({}, 'nut-col-offset-' + val, this.offset == val));
        }
      },
      immediate: true
    }
  }
});
// CONCATENATED MODULE: ./src/packages/col/col.vue?vue&type=script&lang=js&
 /* harmony default export */ var col_colvue_type_script_lang_js_ = (colvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/col/col.vue





/* normalize component */

var col_component = normalizeComponent(
  col_colvue_type_script_lang_js_,
  colvue_type_template_id_8b626f72_render,
  colvue_type_template_id_8b626f72_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var col = (col_component.exports);
// CONCATENATED MODULE: ./src/packages/flex/_flex.js



// EXTERNAL MODULE: ./src/packages/flex/flex.scss
var flex = __webpack_require__(39);

// CONCATENATED MODULE: ./src/packages/flex/index.js



row.install = function (Vue) {
  Vue.component(Flex.name, row);
};

col.install = function (Vue) {
  Vue.component(Flex.name, col);
};

/* harmony default export */ var packages_flex = ({
  Row: row,
  Col: col
});
// EXTERNAL MODULE: ./src/packages/col/col.scss
var col_col = __webpack_require__(40);

// CONCATENATED MODULE: ./src/packages/col/index.js



col.install = function (Vue) {
  Vue.component(col.name, col);
};

/* harmony default export */ var packages_col = (col);
// EXTERNAL MODULE: ./src/packages/row/row.scss
var row_row = __webpack_require__(41);

// CONCATENATED MODULE: ./src/packages/row/index.js



row.install = function (Vue) {
  Vue.component(row.name, row);
};

/* harmony default export */ var packages_row = (row);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/steps/steps.vue?vue&type=template&id=0f9c0326&
var stepsvue_type_template_id_0f9c0326_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-steps"},[_vm._t("default")],2)}
var stepsvue_type_template_id_0f9c0326_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/steps/steps.vue?vue&type=template&id=0f9c0326&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/steps/steps.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var stepsvue_type_script_lang_js_ = ({
  name: 'nut-steps',
  props: {
    current: {
      type: Number
    },
    source: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    status: {
      validator: function validator(value) {
        return ['wait', 'process', 'finish', 'error'].includes(value);
      },
      default: 'process'
    }
  },
  data: function data() {
    return {
      steps: [],
      stepOffset: 0
    };
  },
  methods: {
    updateChildProps: function updateChildProps(isInit) {
      var _this = this;

      var total = this.steps.length;
      this.steps.forEach(function (child, index) {
        child.stepNumber = index + 1;

        if (_this.direction === 'horizontal') {
          child.total = total;
        } // 如果已存在status,且在初始化时,则略过
        // todo 如果当前是error,在current改变时需要处理


        if (!(isInit && child.currentStatus)) {
          if (index == _this.current - 1) {
            if (_this.status != 'error') {
              child.currentStatus = 'process';
            } else {
              child.currentStatus = 'error';
            }
          } else if (index < _this.current) {
            child.currentStatus = 'finish';
          } else {
            child.currentStatus = 'wait';
          }
        }

        if (index + 1 === total) {
          child.currentStatus += ' nut-step-last';
        }
      });
    },
    init: function init() {
      if (this.$slots.default) {
        this.steps = this.$slots.default.filter(function (vnode) {
          return !!vnode.componentInstance;
        }).map(function (node) {
          return node.componentInstance;
        });
        this.updateChildProps(true);
      }
    }
  },
  mounted: function mounted() {
    this.init();
  },
  watch: {
    current: function current() {
      this.updateChildProps();
    },
    source: function source() {
      var _this2 = this;

      this.$nextTick(function () {
        _this2.init();
      });
    }
  }
});
// CONCATENATED MODULE: ./src/packages/steps/steps.vue?vue&type=script&lang=js&
 /* harmony default export */ var steps_stepsvue_type_script_lang_js_ = (stepsvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/steps/steps.vue





/* normalize component */

var steps_component = normalizeComponent(
  steps_stepsvue_type_script_lang_js_,
  stepsvue_type_template_id_0f9c0326_render,
  stepsvue_type_template_id_0f9c0326_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var steps = (steps_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/steps/Step.vue?vue&type=template&id=6436ad52&
var Stepvue_type_template_id_6436ad52_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-step clearfix",class:'nut-step-status-' + _vm.currentStatus},[_c('div',{staticClass:"nut-step-line"}),_vm._v(" "),_c('div',{staticClass:"nut-step-index"},[_vm._v(_vm._s(_vm.stepNumber))]),_vm._v(" "),_c('div',{staticClass:"nut-step-main"},[_c('div',{staticClass:"nut-step-title"},[_vm._v(_vm._s(_vm.title || _vm.nutTranslate('lang.steps.step')))]),_vm._v(" "),_c('div',{staticClass:"nut-step-content"},[_vm._v(_vm._s(_vm.content || _vm.nutTranslate('lang.steps.stepDesc')))])])])}
var Stepvue_type_template_id_6436ad52_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/steps/Step.vue?vue&type=template&id=6436ad52&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/steps/Step.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var Stepvue_type_script_lang_js_ = ({
  name: 'nut-step',
  mixins: [mixins_locale],
  props: {
    title: {
      type: String
    },
    content: {
      type: String
    }
  },
  data: function data() {
    return {
      currentStatus: '',
      stepNumber: 0,
      stepStatus: 'nut-step-status'
    };
  },
  methods: {},
  mounted: function mounted() {}
});
// CONCATENATED MODULE: ./src/packages/steps/Step.vue?vue&type=script&lang=js&
 /* harmony default export */ var steps_Stepvue_type_script_lang_js_ = (Stepvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/steps/Step.vue





/* normalize component */

var Step_component = normalizeComponent(
  steps_Stepvue_type_script_lang_js_,
  Stepvue_type_template_id_6436ad52_render,
  Stepvue_type_template_id_6436ad52_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var Step = (Step_component.exports);
// CONCATENATED MODULE: ./src/packages/steps/_steps.js


steps.Step = Step;
/* harmony default export */ var _steps = (steps);
// EXTERNAL MODULE: ./src/packages/steps/steps.scss
var steps_steps = __webpack_require__(42);

// CONCATENATED MODULE: ./src/packages/steps/index.js


var steps_Step = _steps.Step;

_steps.install = function (Vue) {
  Vue.component(_steps.name, _steps);
};

steps_Step.install = function (Vue) {
  Vue.component(steps_Step.name, steps_Step);
};

/* harmony default export */ var packages_steps = ({
  Steps: _steps,
  Step: steps_Step
});
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/button/button.vue?vue&type=template&id=68805ce2&
var buttonvue_type_template_id_68805ce2_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('button',{class:_vm.clsStyle,attrs:{"disabled":_vm.disabled},on:{"click":_vm.clickHandler}},[(_vm.icon != '')?_c('nut-icon',{staticClass:"txt-icon",attrs:{"type":_vm.icon,"color":this.color}}):_vm._e(),_vm._v(" "),_c('span',{style:({ color: this.color })},[_vm._t("default")],2)],1)}
var buttonvue_type_template_id_68805ce2_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/button/button.vue?vue&type=template&id=68805ce2&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/button/button.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//

/* harmony default export */ var buttonvue_type_script_lang_js_ = ({
  name: 'nut-button',
  props: {
    type: {
      type: String,
      default: ''
    },
    shape: {
      type: String,
      default: ''
    },
    icon: {
      type: String,
      default: ''
    },
    disabled: {
      type: Boolean,
      default: false
    },
    block: {
      type: Boolean,
      default: false
    },
    small: {
      type: Boolean,
      default: false
    },
    label: {
      type: Boolean,
      default: false
    },
    color: {
      type: String,
      default: ''
    }
  },
  components: {
    'nut-icon': icon
  },
  computed: {
    clsStyle: function clsStyle() {
      var cls = "nut-button ".concat(this.type, " ").concat(this.shape, " \n            ").concat(this.small ? ' small' : '', " \n            ").concat(this.block ? ' block' : '', " \n            ").concat(this.label ? ' label' : '', "\n            ").concat(!this.$slots.default ? this.small ? 'no-txt-small' : 'no-txt' : '');
      return cls;
    }
  },
  methods: {
    clickHandler: function clickHandler(event) {
      // 如果是loading就阻止点击
      if (this.disabled) {
        return;
      }

      this.$emit('click', event);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/button/button.vue?vue&type=script&lang=js&
 /* harmony default export */ var button_buttonvue_type_script_lang_js_ = (buttonvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/button/button.vue





/* normalize component */

var button_component = normalizeComponent(
  button_buttonvue_type_script_lang_js_,
  buttonvue_type_template_id_68805ce2_render,
  buttonvue_type_template_id_68805ce2_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var button_button = (button_component.exports);
// EXTERNAL MODULE: ./src/packages/button/button.scss
var packages_button_button = __webpack_require__(11);

// CONCATENATED MODULE: ./src/packages/button/index.js



button_button.install = function (Vue) {
  Vue.component(button_button.name, button_button);
};

/* harmony default export */ var packages_button = (button_button);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/badge/badge.vue?vue&type=template&id=592dead7&
var badgevue_type_template_id_592dead7_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-badge"},[_vm._t("default"),_vm._v(" "),_c('sup',{directives:[{name:"show",rawName:"v-show",value:(!_vm.hidden && (_vm.content || _vm.isDot)),expression:"!hidden && (content || isDot)"}],staticClass:"nut-badge__content",class:{ 'is-dot': _vm.isDot },style:(_vm.stl),domProps:{"textContent":_vm._s(_vm.content)}})],2)}
var badgevue_type_template_id_592dead7_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/badge/badge.vue?vue&type=template&id=592dead7&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/badge/badge.vue?vue&type=script&lang=js&
//
//
//
//
//
//
/* harmony default export */ var badgevue_type_script_lang_js_ = ({
  name: 'nut-badge',
  props: {
    value: {
      type: [String, Number]
    },
    max: {
      type: Number,
      default: 10000
    },
    isDot: {
      type: Boolean,
      default: false
    },
    hidden: {
      type: Boolean,
      default: false
    },
    top: {
      type: String,
      default: '0'
    },
    right: {
      type: String,
      default: '0'
    },
    zIndex: {
      type: Number,
      default: 10
    }
  },
  data: function data() {
    return {
      stl: {
        top: this.top,
        right: this.right,
        zIndex: this.zIndex
      }
    };
  },
  computed: {
    content: function content() {
      if (this.isDot) return;
      var value = this.value;
      var max = this.max;

      if (typeof value === 'number' && typeof max === 'number') {
        return max < value ? "".concat(max, "+") : value;
      }

      return value;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/badge/badge.vue?vue&type=script&lang=js&
 /* harmony default export */ var badge_badgevue_type_script_lang_js_ = (badgevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/badge/badge.vue





/* normalize component */

var badge_component = normalizeComponent(
  badge_badgevue_type_script_lang_js_,
  badgevue_type_template_id_592dead7_render,
  badgevue_type_template_id_592dead7_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var badge = (badge_component.exports);
// EXTERNAL MODULE: ./src/packages/badge/badge.scss
var badge_badge = __webpack_require__(43);

// CONCATENATED MODULE: ./src/packages/badge/index.js



badge.install = function (Vue) {
  Vue.component(badge.name, badge);
};

/* harmony default export */ var packages_badge = (badge);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/rate/rate.vue?vue&type=template&id=df51d5a6&
var ratevue_type_template_id_df51d5a6_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-rate"},_vm._l((_vm.total),function(n){return _c('span',{key:n,staticClass:"nut-rate-item",class:[{ 'nut-rate-active': n <= _vm.current }],style:({
      height: _vm.size + 'px',
      width: _vm.size + 'px',
      marginRight: _vm.spacing + 'px',
      backgroundImage: n <= _vm.current ? _vm.checkedIcon : _vm.uncheckedIcon
    }),on:{"click":function($event){return _vm.onClick($event, n)}}})}),0)}
var ratevue_type_template_id_df51d5a6_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/rate/rate.vue?vue&type=template&id=df51d5a6&

// EXTERNAL MODULE: ./src/packages/rate/rate.scss
var rate = __webpack_require__(12);

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/rate/rate.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var ratevue_type_script_lang_js_ = ({
  name: 'nut-rate',
  props: {
    total: {
      type: [String, Number],
      default: 5
    },
    value: {
      type: [String, Number],
      default: 3
    },
    size: {
      type: [String, Number],
      default: 25
    },
    uncheckedIcon: {
      type: String,
      default: null
    },
    checkedIcon: {
      type: String,
      default: null
    },
    readOnly: {
      type: Boolean,
      default: false
    },
    spacing: {
      type: [String, Number],
      default: 20
    }
  },
  data: function data() {
    return {
      current: 3
    };
  },
  created: function created() {
    this.current = this.value;
  },
  methods: {
    onClick: function onClick($event, idx) {
      if (this.readOnly) {
        this.$emit('input', this.current);
        this.$emit('click', this.current);
      } else {
        this.current = idx;
        this.$emit('input', idx);
        this.$emit('click', idx);
      }
    }
  },
  watch: {
    value: function value(newVal, oldVal) {
      this.current = newVal;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/rate/rate.vue?vue&type=script&lang=js&
 /* harmony default export */ var rate_ratevue_type_script_lang_js_ = (ratevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/rate/rate.vue





/* normalize component */

var rate_component = normalizeComponent(
  rate_ratevue_type_script_lang_js_,
  ratevue_type_template_id_df51d5a6_render,
  ratevue_type_template_id_df51d5a6_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var rate_rate = (rate_component.exports);
// CONCATENATED MODULE: ./src/packages/rate/index.js



rate_rate.install = function (Vue) {
  Vue.component(rate_rate.name, rate_rate);
};

/* harmony default export */ var packages_rate = (rate_rate);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/swiper/swiper.vue?vue&type=template&id=54b88066&
var swipervue_type_template_id_54b88066_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-swiper",class:[_vm.direction, { dragging: _vm.dragging }],on:{"touchstart":function($event){return _vm._onTouchStart($event)},"mousedown":function($event){return _vm._onTouchStart($event)}}},[_c('div',{staticClass:"nut-swiper-wrap",style:({
      transform: 'translate3d(' + _vm.translateX + 'px,' + _vm.translateY + 'px,0)',
      'transition-duration': _vm.transitionDuration + 'ms',
      '-webkit-transform': 'translate3d(' + _vm.translateX + 'px,' + _vm.translateY + 'px,0)',
      '-webkit-transition-duration': _vm.transitionDuration + 'ms',
      'transition-timing-function': 'ease'
    }),on:{"transitionend":_vm._onTransitionEnd}},[_vm._t("default")],2),_vm._v(" "),_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.paginationVisible),expression:"paginationVisible"}],staticClass:"nut-swiper-pagination"},_vm._l((_vm.slideEls),function(slide,index){return _c('span',{key:index,staticClass:"swiper-pagination-bullet",class:{ active: index + 1 === _vm.currentPage },on:{"click":function($event){_vm.paginationClickable && _vm.setPage(index + 1, true)}}})}),0)])}
var swipervue_type_template_id_54b88066_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/swiper/swiper.vue?vue&type=template&id=54b88066&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/swiper/swiper.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
var VERTICAL = 'vertical';
var HORIZONTAL = 'horizontal';
/* harmony default export */ var swipervue_type_script_lang_js_ = ({
  name: 'nut-swiper',
  props: {
    direction: {
      type: String,
      default: HORIZONTAL,
      validator: function validator(value) {
        return [VERTICAL, HORIZONTAL].indexOf(value) > -1;
      }
    },
    paginationVisible: {
      type: Boolean,
      default: false
    },
    paginationClickable: {
      type: Boolean,
      default: false
    },
    loop: {
      type: Boolean,
      default: false
    },
    speed: {
      type: Number,
      default: 500
    },
    canDragging: {
      type: Boolean,
      default: true
    },
    autoPlay: {
      type: Number,
      default: 0
    },
    initPage: {
      type: Number,
      default: 1
    },
    lazyLoad: {
      type: Boolean,
      default: false
    },
    lazyLoadUrl: {
      type: String,
      default: ''
    },
    swiperData: {
      type: [Array],
      default: function _default() {
        return [];
      }
    }
  },
  watch: {
    swiperData: function swiperData(newValue, oldValue) {
      this.updateEvent();
    }
  },
  data: function data() {
    return {
      dragging: false,
      currentPage: this.initPage,
      lastPage: 1,
      translateX: 0,
      translateY: 0,
      startTranslate: 0,
      slideEls: [],
      translateOffset: 0,
      //当前偏移初始位置距离
      transitionDuration: 0,
      //切换动画时间
      startPos: null,
      delta: 0,
      //拖动距离
      startTime: null,
      isLoop: this.loop,
      timer: null,
      //自动播放定时器
      domTimer: null,
      //渲染延迟查找
      stopAutoPlay: false,
      //停止自动播放
      swiperWrap: null,
      oneSlideTranslate: 0 //一个slide的大小

    };
  },
  methods: {
    //下一张
    next: function next() {
      var page = this.currentPage;

      if (page < this.slideEls.length || this.isLoop) {
        this.setPage(page + 1, true, 'NEXT');
      } else {
        this._revert();
      }
    },
    //上一张
    prev: function prev() {
      var page = this.currentPage;

      if (page > 1 || this.isLoop) {
        this.setPage(page - 1, true, 'PREV');
      } else {
        this._revert();
      }
    },
    setPage: function setPage(page, isHasAnimation, type) {
      if (page === 0) {
        this.currentPage = this.slideEls.length;
      } else if (page === this.slideEls.length + 1) {
        this.currentPage = 1;
      } else {
        this.currentPage = page;
      }

      this._setTranslate(this._getTranslateOfPage(page));

      if (!isHasAnimation) {
        this._slideClassHandle();
      } else {
        this._onTransitionStart(type);
      }
    },
    isHorizontal: function isHorizontal() {
      return this.direction === HORIZONTAL;
    },
    isVertical: function isVertical() {
      return this.direction === VERTICAL;
    },
    renderLazyDom: function renderLazyDom(slideEls) {
      var _this2 = this;

      slideEls.forEach(function (item, index) {
        var src = item.getAttribute('data-src');

        if (item.className != 'nut-swiper-slide nut-swiper-slide-selected') {
          var dom = document.createElement('div'); //jd 图片占位图)

          if (_this2.lazyLoadUrl) {
            dom.style.backgroundImage = "url('".concat(_this2.lazyLoadUrl, "')");
            dom.className = 'nut-lazy img';
          } else {
            dom.className = 'nut-lazy preloader';
          }

          item.appendChild(dom);
        }
      });
      return true;
    },
    updateEvent: function updateEvent(pageSize) {
      var _this3 = this;

      this.$nextTick(function () {
        _this3.domTimer = setTimeout(function () {
          if (pageSize != undefined) _this3.currentPage = pageSize;
          _this3.swiperWrap = _this3.$el.querySelector('.nut-swiper-wrap');
          _this3.slideEls = toConsumableArray_default()(_this3.swiperWrap.children);
          if (_this3.slideEls.length === 0) return;

          _this3._getSlideDistance(_this3.slideEls[0]);

          if (_this3.autoPlay != 0) {
            _this3.isLoop = true;

            _this3._createAutoPlay();
          }

          _this3.isLoop && _this3._createLoop();

          _this3.setPage(_this3.currentPage, false);

          _this3.lazyLoad && _this3.renderLazyDom(_this3.slideEls) && _this3._imgLazyLoad();
        }, 0);
      });
    },
    _slideClassHandle: function _slideClassHandle() {
      var selectedSlide = this.$el.querySelector('.nut-swiper-slide-selected');
      selectedSlide && selectedSlide.classList.remove('nut-swiper-slide-selected');
      this.slideEls[this.currentPage - 1].classList.add('nut-swiper-slide-selected');
      this.lastPage = this.currentPage;
    },
    _getSlideDistance: function _getSlideDistance(el) {
      var styleArr = getComputedStyle(el);
      var marginTop = styleArr['marginTop'].replace('px', '') - 0;
      var marginBottom = styleArr['marginBottom'].replace('px', '') - 0;
      var marginRight = styleArr['marginRight'].replace('px', '') - 0;
      var marginLeft = styleArr['marginLeft'].replace('px', '') - 0;

      if (this.isHorizontal()) {
        this.oneSlideTranslate = marginRight + marginLeft + el['offsetWidth'];
      } else {
        this.oneSlideTranslate = marginTop + marginBottom + el['offsetHeight'];
      }
    },
    _onTouchStart: function _onTouchStart(e) {
      this.swiperWrap.addEventListener('touchmove', this._onTouchMove, false);
      this.swiperWrap.addEventListener('touchend', this._onTouchEnd, false);
      this.swiperWrap.addEventListener('mousemove', this._onTouchMove, false);
      this.swiperWrap.addEventListener('mouseup', this._onTouchEnd, false);
      this.startPos = this._getTouchPos(e);
      this.delta = 0;
      this.startTranslate = this._getTranslateOfPage(this.currentPage);

      if (this.isLoop) {
        this._setTranslate(this.startTranslate);
      }

      this.startTime = new Date().getTime();
      this.dragging = true;
      this.transitionDuration = 0;
      this.stopAutoPlay = true;
    },
    _onTouchMove: function _onTouchMove(e) {
      if (!this.dragging) return;

      if (this.isHorizontal()) {
        this.delta = this._getTouchPos(e).x - this.startPos.x;
      } else {
        this.delta = this._getTouchPos(e).y - this.startPos.y;
      } //let  isQuickAction = (new Date().getTime() - this.startTime) < 200;


      if (this.canDragging && this._computePreventDefault(e)) {
        e.preventDefault();

        this._setTranslate(this.startTranslate + this.delta);

        this.$emit('slideMove', this._getTranslate(), this.$el);
        this.$emit('slide-move', this._getTranslate(), this.$el);
      }
    },
    _onTouchEnd: function _onTouchEnd(e) {
      if (!this.dragging) return;
      this.dragging = false;
      this.transitionDuration = this.speed;
      var isQuickAction = new Date().getTime() - this.startTime < 1000;

      if (this.delta < -this.oneSlideTranslate / 2 || isQuickAction && this.delta < -15) {
        this.next();
      } else if (this.delta > this.oneSlideTranslate / 2 || isQuickAction && this.delta > 15) {
        this.prev();
      } else {
        this._revert();
      }

      this.swiperWrap.removeEventListener('touchmove', this._onTouchMove, false);
      this.swiperWrap.removeEventListener('touchend', this._onTouchEnd, false);
      this.swiperWrap.removeEventListener('mousemove', this._onTouchMove, false);
      this.swiperWrap.removeEventListener('mouseup', this._onTouchEnd, false);
    },
    _revert: function _revert() {
      this.setPage(this.currentPage, true);
    },
    _computePreventDefault: function _computePreventDefault(e) {
      var pos = this._getTouchPos(e);

      var xDis = Math.abs(this.startPos.x - pos.x);
      var yDis = Math.abs(this.startPos.y - pos.y);

      if (xDis <= 5 && xDis >= 0) {
        return false;
      } else if (yDis > 5 && yDis / xDis > 0.5) {
        return false;
      } else {
        return true;
      }
    },
    _getTouchPos: function _getTouchPos(e) {
      var x = e.changedTouches ? e.changedTouches[0]['pageX'] : e['pageX'];
      var y = e.changedTouches ? e.changedTouches[0]['pageY'] : e['pageY'];
      return {
        x: x,
        y: y
      };
    },
    _onTransitionStart: function _onTransitionStart(type) {
      this.transitionDuration = this.speed;
      this.lazyLoad && this._imgLazyLoad(1);

      if (this._isPageChanged()) {
        this.$emit('slideChangeStart', this.currentPage, this.$el, type);
        this.$emit('slide-change-start', this.currentPage, this.$el, type);
      } else {
        this.$emit('slideRevertStart', this.currentPage, this.$el, type);
        this.$emit('slide-revert-start', this.currentPage, this.$el, type);
      }
    },
    _onTransitionEnd: function _onTransitionEnd() {
      if (this._isPageChanged()) {
        this.$emit('slideChangeEnd', this.currentPage, this.$el);
        this.$emit('slide-change-end', this.currentPage, this.$el);
      } else {
        this.$emit('slideRevertEnd', this.currentPage, this.$el);
        this.$emit('slide-revert-end', this.currentPage, this.$el);
      }

      this.transitionDuration = 0;
      this.delta = 0;
      this.lastPage = this.currentPage;

      this._slideClassHandle();

      if (this.isLoop) {
        this._setTranslate(this._getTranslateOfPage(this.currentPage));
      }

      this.stopAutoPlay = false;
    },
    _isPageChanged: function _isPageChanged() {
      return this.lastPage !== this.currentPage;
    },
    _setTranslate: function _setTranslate(value) {
      var translateName = this.isHorizontal() ? 'translateX' : 'translateY';
      this[translateName] = value;
    },
    _getTranslate: function _getTranslate() {
      var translateName = this.isHorizontal() ? 'translateX' : 'translateY';
      return this[translateName];
    },
    _getTranslateOfPage: function _getTranslateOfPage(page) {
      if (page === 0) return 0;
      var propName = this.isHorizontal() ? 'offsetWidth' : 'offsetHeight';

      var _this = this;

      return -[].reduce.call(this.slideEls, function (total, el, i) {
        return i > page - 2 ? total : total + _this.oneSlideTranslate;
      }, 0) + this.translateOffset;
    },
    _createLoop: function _createLoop() {
      var propName = this.isHorizontal() ? 'offsetWidth' : 'offsetHeight';
      var swiperWrapEl = this.$el.querySelector('.nut-swiper-wrap');
      var duplicateFirstChild = swiperWrapEl.firstElementChild.cloneNode(true);
      var duplicateLastChild = swiperWrapEl.lastElementChild.cloneNode(true);
      swiperWrapEl.insertBefore(duplicateLastChild, swiperWrapEl.firstElementChild);
      swiperWrapEl.appendChild(duplicateFirstChild);
      this.translateOffset = -this.oneSlideTranslate;
    },
    _createAutoPlay: function _createAutoPlay() {
      var _this4 = this;

      clearInterval(this.timer);
      this.timer = setInterval(function () {
        if (!_this4.stopAutoPlay) {
          _this4.next();
        }
      }, this.autoPlay);
    },
    _requestAniFrame: function _requestAniFrame() {
      return window.requestAnimationFrame || window.webkitRequestAnimationFrame || function (callback) {
        window.setTimeout(callback, 1000 / 60);
      };
    },
    _imgLazyLoad: function _imgLazyLoad(type) {
      var _this5 = this;

      var requestAniFrame = this._requestAniFrame();

      var imgLazyLoadEl;
      requestAniFrame(function () {
        imgLazyLoadEl = _this5.swiperWrap.querySelectorAll('.nut-img-lazyload');

        if (type == 1) {
          imgLazyLoadEl = _this5.slideEls[_this5.currentPage - 1].querySelectorAll('.nut-img-lazyload');
        }

        imgLazyLoadEl.forEach(function (item, index) {
          if (!_this5._checkInView(item) && type != 1) return;
          var src = item.getAttribute('data-src');
          var img = new Image();
          img.src = src;

          img.onload = function () {
            var lazyLoadingEle = item.parentElement.querySelector('.nut-lazy');

            if (lazyLoadingEle) {
              item.parentElement.removeChild(lazyLoadingEle);
            }

            item.src = src;
            item.classList.remove('nut-img-lazyload');
          };

          img.onerror = function () {
            item.src = _this5.lazyLoadUrl;
            item.classList.remove('nut-img-lazyload');
          };
        });
      });
    },
    _checkInView: function _checkInView(imgItem) {
      var imgRect = imgItem.getBoundingClientRect();
      var swiperRect = this.$el.getBoundingClientRect();
      var imgTop = imgRect.top;
      var imgLeft = imgRect.left;
      var swiperWidth = this.$el.clientWidth;
      var swiperHeight = this.$el.clientHeight;
      var swiperTop = swiperRect.top;
      var swiperLeft = swiperRect.left;
      var isInView = true;

      if (imgTop > swiperTop + swiperHeight || imgLeft > swiperLeft + swiperWidth) {
        isInView = false;
      }

      return isInView;
    }
  },
  created: function created() {},
  mounted: function mounted() {
    this._onTouchMove = this._onTouchMove.bind(this);
    this._onTouchEnd = this._onTouchEnd.bind(this);
    this.updateEvent();
  },
  destroyed: function destroyed() {
    this.timer && clearInterval(this.timer);
    this.domTimer && clearTimeout(this.domTimer);
  },
  activated: function activated() {
    if (this.keepAlive) {
      this.keepAlive = false;
      this.updateEvent();
    }
  },
  deactivated: function deactivated() {
    this.keepAlive = true;
    this.timer && clearInterval(this.timer);
    this.domTimer && clearTimeout(this.domTimer);
  }
});
// CONCATENATED MODULE: ./src/packages/swiper/swiper.vue?vue&type=script&lang=js&
 /* harmony default export */ var swiper_swipervue_type_script_lang_js_ = (swipervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/swiper/swiper.vue





/* normalize component */

var swiper_component = normalizeComponent(
  swiper_swipervue_type_script_lang_js_,
  swipervue_type_template_id_54b88066_render,
  swipervue_type_template_id_54b88066_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var swiper = (swiper_component.exports);
// EXTERNAL MODULE: ./src/packages/swiper/swiper.scss
var swiper_swiper = __webpack_require__(44);

// CONCATENATED MODULE: ./src/packages/swiper/index.js



swiper.install = function (Vue) {
  Vue.component(swiper.name, swiper);
};

/* harmony default export */ var packages_swiper = (swiper);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/menu/menu.vue?vue&type=template&id=34f80202&
var menuvue_type_template_id_34f80202_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-menu"},[_c('transition',{attrs:{"name":!_vm.isAnimation ? 'nutFade' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.isVisible),expression:"isVisible"}],staticClass:"nut-menu-mask",on:{"click":_vm.clickMenuMask}})]),_vm._v(" "),_c('transition',{attrs:{"name":!_vm.isAnimation ? 'nutSlideDown' : ''}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.isVisible),expression:"isVisible"}],staticClass:"nut-menu-panel"},[(_vm.type === 'simple' && !_vm.$slots.custom)?_c('div',{staticClass:"menu-simple"},[_c('ul',_vm._l((_vm.datalist),function(item,index){return _c('li',{key:index,class:item.selected ? 'selected' : '',on:{"click":function($event){return _vm.selectedItem(item, index)}}},[_vm._v("\n            "+_vm._s(item.text)+"\n            "),(item.selected)?_c('span',[_c('nut-icon',{attrs:{"type":"tick","color":"#f0250f"}})],1):_vm._e()])}),0)]):_vm._e(),_vm._v(" "),(_vm.type === 'multiple' && _vm.mulstyle === 'style1')?_c('div',{staticClass:"menu-multiple-style1"},[_c('ul',_vm._l((_vm.datalist),function(item,index){return _c('li',{key:index,class:{ selected: item.selected ? true : false, col2: _vm.col == 2 ? true : false, col3: _vm.col == 3 ? true : false },on:{"click":function($event){return _vm.selectMutiple(index)}}},[_c('nut-checkbox',{attrs:{"size":"small","disabled":!item.selected && _vm.max <= _vm.list.filter(function (value) { return value.selected == true; }).length ? true : false},model:{value:(item.selected),callback:function ($$v) {_vm.$set(item, "selected", $$v)},expression:"item.selected"}},[_vm._v(_vm._s(item.text))])],1)}),0),_vm._v(" "),_c('nut-button-group',[_c('nut-button',{attrs:{"type":"light"},on:{"click":_vm.resetMenu}},[_vm._v(_vm._s(_vm.resetBtnTxt))]),_vm._v(" "),_c('nut-button',{on:{"click":_vm.sureMenu}},[_vm._v(_vm._s(_vm.okBtnTxt))])],1)],1):_vm._e(),_vm._v(" "),(_vm.type === 'multiple' && _vm.mulstyle === 'style2')?_c('div',{staticClass:"menu-multiple-style2"},[_c('ul',_vm._l((_vm.datalist),function(item,index){return _c('li',{key:index,class:{ selected: item.selected ? true : false, col2: _vm.col == 2 ? true : false, col3: _vm.col == 3 ? true : false },on:{"click":function($event){return _vm.selectMutiple(index)}}},[_c('a',{attrs:{"href":"javascript:void(0);"}},[_vm._v(_vm._s(item.text))])])}),0),_vm._v(" "),_c('nut-button-group',[_c('nut-button',{attrs:{"type":"light"},on:{"click":_vm.resetMenu}},[_vm._v(_vm._s(_vm.resetBtnTxt))]),_vm._v(" "),_c('nut-button',{on:{"click":_vm.sureMenu}},[_vm._v(_vm._s(_vm.okBtnTxt))])],1)],1):_vm._e(),_vm._v(" "),(_vm.type === 'multiple' && _vm.mulstyle === 'style3')?_c('div',{staticClass:"menu-multiple-style3"},[_c('ul',_vm._l((_vm.datalist),function(item,index){return _c('li',{key:index,class:{ selected: item.selected ? true : false, col2: _vm.col == 2 ? true : false, col3: _vm.col == 3 ? true : false },on:{"click":function($event){return _vm.selectMutiple(index)}}},[_c('label',[_vm._v(_vm._s(item.text))])])}),0),_vm._v(" "),_c('nut-button-group',[_c('nut-button',{attrs:{"type":"light"},on:{"click":_vm.resetMenu}},[_vm._v(_vm._s(_vm.resetBtnTxt))]),_vm._v(" "),_c('nut-button',{on:{"click":_vm.sureMenu}},[_vm._v(_vm._s(_vm.okBtnTxt))])],1)],1):_vm._e(),_vm._v(" "),(_vm.$slots.custom)?_c('div',{staticClass:"menu-custom"},[_vm._t("custom",[_vm._v(_vm._s(_vm.custom))])],2):_vm._e()])])],1)}
var menuvue_type_template_id_34f80202_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/menu/menu.vue?vue&type=template&id=34f80202&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/checkbox/checkbox.vue?vue&type=template&id=26d19cb3&
var checkboxvue_type_template_id_26d19cb3_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('label',{class:['nut-checkbox', 'nut-checkbox-size-' + _vm.size]},[_c('input',{class:{ 'nut-checkbox-ani': _vm.animation },attrs:{"type":"checkbox","name":_vm.name,"disabled":_vm.disabled},domProps:{"checked":_vm.isChecked,"value":_vm.submittedValue},on:{"change":_vm.changeEvt}}),_vm._v(" "),(_vm.label)?_c('span',{staticClass:"nut-checkbox-label"},[_vm._v("\n    "+_vm._s(_vm.label)+"\n  ")]):_c('span',{staticClass:"nut-checkbox-label"},[_vm._t("default")],2)])}
var checkboxvue_type_template_id_26d19cb3_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/checkbox/checkbox.vue?vue&type=template&id=26d19cb3&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/checkbox/checkbox.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var checkboxvue_type_script_lang_js_ = ({
  name: 'nut-checkbox',
  props: {
    name: {
      type: String
    },
    size: {
      type: [String, Number, Boolean],
      default: 'base'
    },
    label: {
      type: String,
      default: ''
    },
    value: {
      required: true
    },
    trueValue: {
      default: true
    },
    falseValue: {
      default: false
    },
    submittedValue: {
      type: String,
      default: 'on' // HTML default

    },
    checked: {
      type: Boolean,
      default: false
    },
    disabled: {
      type: Boolean,
      default: false
    },
    animation: {
      type: Boolean,
      default: true
    }
  },
  watch: {
    value: function value() {
      this.isChecked = this.looseEqual(this.value, this.trueValue);
    },
    checked: function checked(newValue, oldValue) {
      this.isChecked = newValue;
    }
  },
  data: function data() {
    return {
      isChecked: this.value == this.trueValue || this.checked
    };
  },
  mounted: function mounted() {
    this.$emit('update:checked', this.isChecked ? this.trueValue : this.falseValue, this.label);
    this.$emit('input', this.isChecked ? this.trueValue : this.falseValue, this.label);
  },
  methods: {
    isObject: function isObject(obj) {
      return obj !== null && typeof_default()(obj) === 'object';
    },
    looseEqual: function looseEqual(a, b) {
      return a == b || (this.isObject(a) && this.isObject(b) ? JSON.stringify(a) === JSON.stringify(b) : false);
    },
    changeEvt: function changeEvt(event) {
      var isCheckedPrevious = this.isChecked;
      var isChecked = event.target.checked;
      this.$emit('input', isChecked ? this.trueValue : this.falseValue, this.label, event);

      if (isCheckedPrevious !== isChecked) {
        this.$emit('change', isChecked ? this.trueValue : this.falseValue, this.label, event);
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/checkbox/checkbox.vue?vue&type=script&lang=js&
 /* harmony default export */ var checkbox_checkboxvue_type_script_lang_js_ = (checkboxvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/checkbox/checkbox.vue





/* normalize component */

var checkbox_component = normalizeComponent(
  checkbox_checkboxvue_type_script_lang_js_,
  checkboxvue_type_template_id_26d19cb3_render,
  checkboxvue_type_template_id_26d19cb3_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var checkbox_checkbox = (checkbox_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/buttongroup/buttongroup.vue?vue&type=template&id=37a34025&
var buttongroupvue_type_template_id_37a34025_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:_vm.cls},[_vm._t("default")],2)}
var buttongroupvue_type_template_id_37a34025_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/buttongroup/buttongroup.vue?vue&type=template&id=37a34025&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/buttongroup/buttongroup.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var buttongroupvue_type_script_lang_js_ = ({
  name: 'nut-buttongroup',
  props: {
    shape: {
      type: String,
      default: ''
    },
    type: {
      type: String,
      default: ''
    }
  },
  data: function data() {
    return {
      cls: ''
    };
  },
  mounted: function mounted() {
    this.cls = "nut-buttongroup ".concat(this.shape, " ").concat(this.type);
  }
});
// CONCATENATED MODULE: ./src/packages/buttongroup/buttongroup.vue?vue&type=script&lang=js&
 /* harmony default export */ var buttongroup_buttongroupvue_type_script_lang_js_ = (buttongroupvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/buttongroup/buttongroup.vue





/* normalize component */

var buttongroup_component = normalizeComponent(
  buttongroup_buttongroupvue_type_script_lang_js_,
  buttongroupvue_type_template_id_37a34025_render,
  buttongroupvue_type_template_id_37a34025_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var buttongroup = (buttongroup_component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/menu/menu.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//






var menuvue_type_script_lang_js_lockMaskScroll = function (bodyCls) {
  var scrollTop;
  return {
    afterOpen: function afterOpen() {
      scrollTop = document.scrollingElement.scrollTop || document.body.scrollTop;
      document.body.classList.add(bodyCls);
      document.body.style.top = -scrollTop + 'px';
    },
    beforeClose: function beforeClose() {
      if (document.body.classList.contains(bodyCls)) {
        document.body.classList.remove(bodyCls);
        document.scrollingElement.scrollTop = scrollTop;
      }
    }
  };
}('dialog-open');

/* harmony default export */ var menuvue_type_script_lang_js_ = ({
  name: 'nut-menu',
  mixins: [mixins_locale],
  components: {
    'nut-button': button_button,
    'nut-button-group': buttongroup,
    'nut-checkbox': checkbox_checkbox,
    'nut-icon': icon
  },
  props: {
    isAnimation: {
      //是否有动画效果
      type: Boolean,
      default: false
    },
    isVisible: {
      //是否显示
      type: Boolean,
      default: false
    },
    type: {
      //单选 simple  多选  multiple
      type: String,
      default: 'simple'
    },
    col: {
      //显示的列数
      type: [Number, String],
      default: 1
    },
    mulstyle: {
      //多选样式,支持三种多选样式 style1 style2 style3
      type: [String],
      default: 'style1'
    },
    max: {
      type: [String, Number],
      default: 5
    },
    custom: {
      type: String,
      default: ''
    },
    list: {
      type: Array,
      default: function _default() {
        return [];
      }
    }
  },
  watch: {
    isVisible: function isVisible(val) {
      menuvue_type_script_lang_js_lockMaskScroll[val ? 'afterOpen' : 'beforeClose']();
    }
  },
  data: function data() {
    return {
      datalist: []
    };
  },
  mounted: function mounted() {
    this.datalist = this.list;
  },
  computed: {
    okBtnTxt: function okBtnTxt() {
      return this.nutTranslate('lang.okBtnTxt');
    },
    resetBtnTxt: function resetBtnTxt() {
      return this.nutTranslate('lang.menu.resetBtnTxt');
    }
  },
  methods: {
    clickMenuMask: function clickMenuMask() {
      this.$emit('close');
    },
    selectedItem: function selectedItem(item, index) {
      this.$emit('choose', item, index);
    },
    selectMutiple: function selectMutiple(index) {
      if (!this.datalist[index].selected) {
        //判断设置的最大可选项
        var count = 0;
        this.datalist.forEach(function (item) {
          if (item.selected) count++;
        });

        if (count >= this.max) {
          this.$emit('maxTip');
          return;
        }
      }

      this.$set(this.datalist[index], 'selected', !this.datalist[index].selected);
    },
    resetMenu: function resetMenu() {
      this.datalist.map(function (value, key) {
        return value.selected = false;
      });
      this.$emit('reset', this.datalist);
    },
    sureMenu: function sureMenu() {
      this.$emit('close');
      this.$emit('ok', this.datalist);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/menu/menu.vue?vue&type=script&lang=js&
 /* harmony default export */ var menu_menuvue_type_script_lang_js_ = (menuvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/menu/menu.vue





/* normalize component */

var menu_component = normalizeComponent(
  menu_menuvue_type_script_lang_js_,
  menuvue_type_template_id_34f80202_render,
  menuvue_type_template_id_34f80202_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var menu = (menu_component.exports);
// EXTERNAL MODULE: ./src/packages/menu/menu.scss
var menu_menu = __webpack_require__(45);

// CONCATENATED MODULE: ./src/packages/menu/index.js



menu.install = function (Vue) {
  Vue.component(menu.name, menu);
};

/* harmony default export */ var packages_menu = (menu);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/stepper/stepper.vue?vue&type=template&id=7d8fce78&
var steppervue_type_template_id_7d8fce78_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:{ 'nut-stepper': !_vm.simple, 'nut-stepper-simple': _vm.simple }},[_c('span',{class:{ 'nut-stepper-grey': _vm.isGray },domProps:{"innerHTML":_vm._s(__webpack_require__(20))},on:{"click":function($event){return _vm.reduce()}}}),_vm._v(" "),_c('input',{style:({ visibility: _vm.showNum ? 'visible' : 'hidden' }),attrs:{"type":"number","min":_vm.minNum,"max":_vm.max,"readonly":_vm.readonly || !_vm.isLegal},domProps:{"value":_vm._f("maxv")(_vm.num,_vm.minNum, _vm.max)},on:{"input":_vm.numchange,"keyup":_vm.checknum,"focus":_vm.focus,"blur":_vm.blur}}),_vm._v(" "),_c('div',{class:['nut-stepper-fake', _vm.showAddAnim ? 'nut-stepper-transition' : 'nut-stepper-none-transition'],style:({
      visibility: _vm.showAddAnim ? 'visible' : 'hidden',
      transform: 'translate(0,' + _vm.animTranslate_add + '%)',
      '-ms-transform': 'translate(0,' + _vm.animTranslate_add + '%)',
      '-moz-transform': 'translate(0,' + _vm.animTranslate_add + '%)',
      '-webkit-transform': 'translate(0,' + _vm.animTranslate_add + '%)',
      '-o-transform': 'translate(0,' + _vm.animTranslate_add + '%)'
    })},[_c('div',[_vm._v(_vm._s(_vm.animNum[0]))]),_vm._v(" "),_c('div',[_vm._v(_vm._s(_vm.animNum[1]))])]),_vm._v(" "),_c('div',{class:['nut-stepper-fake-', _vm.showReduceAnim ? 'nut-stepper-transition' : 'nut-stepper-none-transition'],style:({
      visibility: _vm.showReduceAnim ? 'visible' : 'hidden',
      transform: 'translate(0,' + _vm.animTranslate_ + '%)',
      '-ms-transform': 'translate(0,' + _vm.animTranslate_ + '%)',
      '-moz-transform': 'translate(0,' + _vm.animTranslate_ + '%)',
      '-webkit-transform': 'translate(0,' + _vm.animTranslate_ + '%)',
      '-o-transform': 'translate(0,' + _vm.animTranslate_ + '%)'
    })},[_c('div',[_vm._v(_vm._s(_vm.animNum[0]))]),_vm._v(" "),_c('div',[_vm._v(_vm._s(_vm.animNum[1]))])]),_vm._v(" "),_c('span',{class:{ 'nut-stepper-grey': (_vm.max && Number(_vm.num) > _vm.max - _vm.step) || !_vm.isLegal },domProps:{"innerHTML":_vm._s(__webpack_require__(21))},on:{"click":function($event){return _vm.add()}}})])}
var steppervue_type_template_id_7d8fce78_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/stepper/stepper.vue?vue&type=template&id=7d8fce78&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/stepper/stepper.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var steppervue_type_script_lang_js_ = ({
  name: 'nut-stepper',
  props: {
    simple: {
      type: Boolean,
      default: true
    },
    min: {
      type: [Number, String],
      default: 0
    },
    max: {
      type: [Number, String],
      default: Infinity
    },
    step: {
      type: [Number, String],
      default: 1
    },
    readonly: {
      type: Boolean,
      default: false
    },
    transition: {
      type: Boolean,
      default: true
    },
    value: {
      type: [String, Number],
      required: true
    },
    decimalPlaces: {
      type: Number,
      default: 0
    }
  },
  data: function data() {
    return {
      tempNum: '',
      focusing: false,
      num: this.value,
      minNum: this.min,
      showNum: true,
      showAddAnim: false,
      showReduceAnim: false,
      animNum: [this.value, this.value],
      animTranslate_add: 0,
      animTranslate_: -100,
      isLegal: true //是否合法 isLegal

    };
  },
  filters: {
    maxv: function maxv(v, min, max) {
      var val = v;
      if (val > max) val = max;
      if (val < min) val = min;
      return val;
    }
  },
  watch: {
    value: {
      handler: function handler(v, ov) {
        if (v > this.max) v = this.max;
        if (v < this.minNum) v = this.minNum;
        this.num = v > 0 ? this.fixedDecimalPlaces(v) : v;
        this.$emit('change', this.num);
      },
      immediate: true
    },
    min: {
      handler: function handler(v, ov) {
        this.isLegal = true;

        if (v < this.max) {
          this.minNum = v;
        } else {
          this.isLegal = false;
        }
      },
      immediate: true
    },
    max: {
      handler: function handler(v, ov) {
        this.isLegal = true;

        if (v <= this.min) {
          this.isLegal = false;
        }
      },
      immediate: true
    }
  },
  computed: {
    isGray: function isGray() {
      return (this.focusing ? this.tempNum : this.num) - this.step < this.min;
    }
  },
  methods: {
    focus: function focus(e) {
      if (this.readonly || !this.isLegal) return; // clear val temporary when focus, e...s

      var v = this.num;
      this.tempNum = v;
      this.minNum = ''; // this.num = '';

      this.focusing = true;
      this.$emit('focus', e, this.num);
    },
    blur: function blur(e) {
      if (this.readonly || !this.isLegal) return this.$emit('blur', e, this.num);
      var v = e.target.value;
      this.minNum = this.min;
      this.focusing = false;

      if (v) {
        if (v > this.max) v = this.max;
        if (v < this.minNum) v = this.minNum;
        this.num = v;
      } else {
        this.num = this.tempNum;
      }

      this.$emit('update:value', this.num);
      this.$emit('blur', e, this.num);
    },
    checknum: function checknum(e) {
      var v = e.target.value; // this.minNum = this.min;

      this.focusing = false;
      if (v > this.max) v = this.max;
      if (v < this.minNum) v = this.minNum;
      e.target.value = v;
      this.num = v;
    },
    numchange: function numchange(e) {
      var v = e.target.value;
      if (v > this.max) v = this.max;
      if (v < this.minNum) v = this.minNum;
      e.target.value = v;
      this.num = v;
      this.$emit('update:value', this.num);
      this.$emit('change', this.num);
    },
    fixedDecimalPlaces: function fixedDecimalPlaces(v) {
      return Number(v).toFixed(this.decimalPlaces); // .replace(/(\d+\.[^0]*)0+$/, '$1').replace(/\.$/, '')
    },
    add: function add() {
      var _this = this;

      this.num = Number(this.num);

      if (this.num <= this.max - this.step && this.max > this.minNum) {
        var _this$fixedDecimalPla = this.fixedDecimalPlaces(this.num + Number(this.step)).split('.'),
            _this$fixedDecimalPla2 = slicedToArray_default()(_this$fixedDecimalPla, 2),
            n1 = _this$fixedDecimalPla2[0],
            n2 = _this$fixedDecimalPla2[1];

        var fixedLen = n2 ? n2.length : 0;
        this.num = parseFloat(n1 + (n2 ? '.' + n2 : '')).toFixed(fixedLen);

        if (this.transition) {
          this.showNum = false;
          this.showAddAnim = true;
          this.showReduceAnim = false;
          this.animNum = [parseFloat(this.num - this.step).toFixed(fixedLen), this.num];
          this.animTranslate_add = -100;
          var f = this.$el.querySelector('.nut-stepper-fake');
          f.addEventListener('webkitTransitionEnd', function () {
            _this.showNum = true;
            _this.showAddAnim = false;
            _this.animTranslate_add = 0;
          });
        }

        this.$emit('update:value', this.num);
        this.$emit('add', this.num);
      } else {
        this.$emit('add-no-allow');
      }
    },
    animEnd: function animEnd() {
      // unbind
      this.showNum = true;
    },
    reduce: function reduce() {
      var _this2 = this;

      if (this.num - this.step >= this.minNum) {
        var _this$fixedDecimalPla3 = this.fixedDecimalPlaces(this.num - Number(this.step)).split('.'),
            _this$fixedDecimalPla4 = slicedToArray_default()(_this$fixedDecimalPla3, 2),
            n1 = _this$fixedDecimalPla4[0],
            n2 = _this$fixedDecimalPla4[1];

        var fixedLen = n2 ? n2.length : 0;
        this.num = parseFloat(n1 + (n2 ? '.' + n2 : '')).toFixed(fixedLen);

        if (this.transition) {
          this.showNum = false;
          this.showAddAnim = false;
          this.showReduceAnim = true;
          this.animNum = [this.num, this.num];
          this.animTranslate_ = 0;
          var f = this.$el.querySelector('.nut-stepper-fake-');
          f.addEventListener('webkitTransitionEnd', function () {
            _this2.showNum = true;
            _this2.showReduceAnim = false;
            _this2.animTranslate_ = -100;
          });
        }

        this.$emit('update:value', this.num);
        this.$emit('reduce', this.num);
      } else {
        this.$emit('reduce-no-allow');
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/stepper/stepper.vue?vue&type=script&lang=js&
 /* harmony default export */ var stepper_steppervue_type_script_lang_js_ = (steppervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/stepper/stepper.vue





/* normalize component */

var stepper_component = normalizeComponent(
  stepper_steppervue_type_script_lang_js_,
  steppervue_type_template_id_7d8fce78_render,
  steppervue_type_template_id_7d8fce78_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var stepper = (stepper_component.exports);
// EXTERNAL MODULE: ./src/packages/stepper/stepper.scss
var stepper_stepper = __webpack_require__(46);

// CONCATENATED MODULE: ./src/packages/stepper/index.js



stepper.install = function (Vue) {
  Vue.component(stepper.name, stepper);
};

/* harmony default export */ var packages_stepper = (stepper);
// EXTERNAL MODULE: ./src/packages/buttongroup/buttongroup.scss
var buttongroup_buttongroup = __webpack_require__(47);

// CONCATENATED MODULE: ./src/packages/buttongroup/index.js



buttongroup.install = function (Vue) {
  Vue.component(buttongroup.name, buttongroup);
};

/* harmony default export */ var packages_buttongroup = (buttongroup);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/searchbar/searchbar.vue?vue&type=template&id=157dd368&
var searchbarvue_type_template_id_157dd368_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-searchbar', _vm.customClass ? _vm.customClass : '']},[_c('div',{staticClass:"search-input",class:[_vm.animation ? 'nut-search-ani' : '', _vm.inputFocusAnimation ? 'focus' : '']},[_c('form',{attrs:{"id":"input-form"},on:{"submit":function($event){$event.preventDefault();}}},[(_vm.hasIcon)?_c('nut-icon',{attrs:{"type":"search","size":_vm.searchIconSize,"color":_vm.searchIconColor}}):_vm._e(),_vm._v(" "),_c('input',{ref:"searchInput",attrs:{"type":"search","placeholder":_vm.placeText || _vm.nutTranslate('lang.searchbar.placeText')},domProps:{"value":_vm.value},on:{"keyup":function($event){if(!$event.type.indexOf('key')&&_vm._k($event.keyCode,"enter",13,$event.key,"Enter")){ return null; }return _vm.submitFun($event)},"input":_vm.inputFun,"blur":_vm.blurFun,"focus":_vm.focusFun}}),_vm._v(" "),_c('span',{staticClass:"close-icon",class:_vm.hasCloseIcon ? 'show' : '',on:{"click":_vm.clearInput}},[_c('nut-icon',{attrs:{"type":"circle-cross","size":_vm.clearIconSize,"color":_vm.clearIconColor}})],1)],1)]),_vm._v(" "),(_vm.hasSearchButton)?_c('a',{staticClass:"btn-search",attrs:{"href":"javascript:;"},on:{"click":_vm.submitFun}},[(_vm.hasTextButton)?_c('span',[_vm._v(_vm._s(_vm.textInfo || _vm.nutTranslate('lang.searchbar.textInfo')))]):_c('nut-icon',{attrs:{"type":"search","size":_vm.searchBtnIconSize,"color":_vm.searchBtnIconColor}})],1):_vm._e()])}
var searchbarvue_type_template_id_157dd368_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/searchbar/searchbar.vue?vue&type=template&id=157dd368&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/searchbar/searchbar.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var searchbarvue_type_script_lang_js_ = ({
  name: 'nut-searchbar',
  mixins: [mixins_locale],
  props: {
    hasIcon: {
      type: Boolean,
      default: false
    },
    searchIconSize: {
      type: String,
      default: '20px'
    },
    searchIconColor: {
      type: String,
      default: '#2e2d2d'
    },
    searchBtnIconSize: {
      type: String,
      default: '20px'
    },
    searchBtnIconColor: {
      type: String,
      default: '#2e2d2d'
    },
    clearIconSize: {
      type: String,
      default: '15px'
    },
    clearIconColor: {
      type: String,
      default: '#2e2d2d'
    },
    placeText: {
      type: String
    },
    hasSearchButton: {
      type: Boolean,
      default: true
    },
    hasTextButton: {
      type: Boolean,
      default: false
    },
    textInfo: {
      type: String
    },
    animation: {
      type: Boolean,
      default: true
    },
    customClass: {
      type: String,
      default: ''
    },
    value: {
      type: [String, Number],
      default: ''
    }
  },
  components: defineProperty_default()({}, icon.name, icon),
  data: function data() {
    return {
      inputFocusAnimation: false
    };
  },
  watch: {
    value: function value(newValue, oldValue) {
      this.updateValue('change');
    }
  },
  computed: {
    hasCloseIcon: function hasCloseIcon() {
      return this.value ? true : false;
    }
  },
  mounted: function mounted() {},
  methods: {
    updateValue: function updateValue() {
      var trigger = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 'input';
      var searchInputValue = trigger == 'change' ? this.value : this.$refs.searchInput.value;
      this.$emit(trigger, searchInputValue);
    },
    //清空 input 输入
    clearInput: function clearInput() {
      this.$emit('clear', '');
      this.$emit('input', '');
    },
    focusFun: function focusFun() {
      this.inputFocusAnimation = true;
      this.$emit('focus');
    },
    inputFun: function inputFun() {
      this.updateValue();
    },
    blurFun: function blurFun() {
      this.inputFocusAnimation = false;
      this.updateValue('blur');
    },
    submitFun: function submitFun() {
      this.updateValue('submit');
    },
    // 失去焦点
    blur: function blur() {
      this.$refs.searchInput.blur();
    },
    //js控制获取焦点
    focus: function focus() {
      this.$nextTick(function () {
        this.$refs.searchInput.focus();
      });
    }
  }
});
// CONCATENATED MODULE: ./src/packages/searchbar/searchbar.vue?vue&type=script&lang=js&
 /* harmony default export */ var searchbar_searchbarvue_type_script_lang_js_ = (searchbarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/searchbar/searchbar.vue





/* normalize component */

var searchbar_component = normalizeComponent(
  searchbar_searchbarvue_type_script_lang_js_,
  searchbarvue_type_template_id_157dd368_render,
  searchbarvue_type_template_id_157dd368_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var searchbar = (searchbar_component.exports);
// EXTERNAL MODULE: ./src/packages/searchbar/searchbar.scss
var searchbar_searchbar = __webpack_require__(48);

// CONCATENATED MODULE: ./src/packages/searchbar/index.js



searchbar.install = function (Vue) {
  Vue.component(searchbar.name, searchbar);
};

/* harmony default export */ var packages_searchbar = (searchbar);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/imagepicker/imagepicker.vue?vue&type=template&id=7ec248d6&scoped=true&
var imagepickervue_type_template_id_7ec248d6_scoped_true_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-imagepicker"},[_c('div',{staticClass:"img-list"},[_c('transition-group',{attrs:{"name":_vm.animation ? 'nutEase' : ''}},_vm._l((this.list),function(item){return _c('div',{key:item.id,staticClass:"img-item",style:({ width: _vm.width + 'px', height: _vm.height + 'px', marginRight: _vm.margin + 'px' }),on:{"click":function($event){_vm.delMode == 'tap' ? _vm.deleteImg(item.id) : _vm.preview(item.id)},"touchstart":function($event){_vm.delMode == 'longtap' ? _vm.touchStart(item.id) : ''},"touchmove":function($event){_vm.delMode == 'longtap' ? _vm.touchMove(item.id) : ''},"touchend":function($event){_vm.delMode == 'longtap' ? _vm.touchEnd(item.id) : ''}}},[_c('a',{attrs:{"href":"javascript:;"}},[_c('img',{attrs:{"src":item.src,"alt":""}})])])}),0),_vm._v(" "),_c('div',{directives:[{name:"show",rawName:"v-show",value:(this.list.length < this.max),expression:"this.list.length < this.max"}],staticClass:"add-icon",style:({ width: _vm.width + 'px', height: _vm.height + 'px' })},[_c('i',[_c('svg',{attrs:{"xmlns":"http://www.w3.org/2000/svg","viewBox":"0 0 16 16"}},[_c('g',{attrs:{"fill-rule":"evenodd"}},[_c('rect',{attrs:{"y":"6","width":"16","height":"4","rx":"2"}}),_vm._v(" "),_c('rect',{attrs:{"transform":"rotate(90 8 8)","y":"6","width":"16","height":"4","rx":"2"}})])])]),_vm._v(" "),_c('input',{attrs:{"type":"file","name":"files","multiple":_vm.ismultiple ? 'multiple' : '',"accept":_vm.accept},on:{"change":_vm.addImg}})])],1)])}
var imagepickervue_type_template_id_7ec248d6_scoped_true_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/imagepicker/imagepicker.vue?vue&type=template&id=7ec248d6&scoped=true&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/imagepicker/imagepicker.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var imagepickervue_type_script_lang_js_ = ({
  name: 'nut-imagepicker',
  props: {
    animation: {
      type: [Boolean],
      default: true
    },
    width: {
      type: [String, Number],
      default: 100
    },
    height: {
      type: [String, Number],
      default: 100
    },
    margin: {
      type: [String, Number],
      default: 5
    },
    max: {
      //允许上传的最大数量
      type: [Number, String],
      default: 9
    },
    accept: {
      type: [String],
      default: 'image/*'
    },
    ismultiple: {
      //是否开启多图片上传
      type: [Boolean],
      default: false
    },
    delMode: {
      //删除图片的方式，支持tap、longtap
      type: [String],
      default: 'tap'
    },
    longTapTime: {
      type: [Number],
      default: 500
    },
    autoUpload: {
      //选择完图片之后是否自动完成上传
      type: [Boolean, String],
      default: false
    },
    imgList: {
      type: Array,
      default: function _default() {
        return [];
      }
    }
  },
  data: function data() {
    return {
      timeOutEvent: 0,
      list: []
    };
  },
  mounted: function mounted() {
    this.list = this.imgList;
  },
  methods: {
    addImg: function addImg(event) {
      var self = this; //限制图片上传数量

      var file = event.target.files;
      var fileArr = Array.from(file);

      if (file.length > self.max - self.list.length) {
        fileArr = fileArr.filter(function (item, index) {
          return index < self.max - self.list.length;
        });
      }

      if (self.autoUpload) {
        //自动上传
        self.$emit('imgMsg', {
          code: 1,
          msg: fileArr
        });
        self.$emit('img-msg', {
          code: 1,
          msg: fileArr
        });
      } else {
        fileArr.forEach(function (item, index) {
          var reader = new FileReader();

          reader.onload = function (evt) {
            self.list.push({
              id: Math.random(),
              src: evt.target.result
            });
            event.target.value = '';
          };

          reader.readAsDataURL(item);
        });
        self.$emit('imgMsg', {
          code: 2,
          msg: fileArr
        });
        self.$emit('img-msg', {
          code: 2,
          msg: fileArr
        });
      }
    },
    preview: function preview(id) {
      this.$emit('imgMsg', {
        code: 4,
        msg: id
      });
      this.$emit('img-msg', {
        code: 4,
        msg: id
      });
    },
    deleteImg: function deleteImg(id) {
      this.list = this.list.filter(function (item) {
        return item.id != id;
      });
      this.$emit('update:imgList', this.list);
      this.$emit('imgMsg', {
        code: 3,
        msg: id
      });
      this.$emit('img-msg', {
        code: 3,
        msg: id
      });
    },
    touchStart: function touchStart(id) {
      var _this = this;

      // console.log(this.longTapTime);
      this.timeOutEvent = setTimeout(function () {
        _this.deleteImg(id);
      }, this.longTapTime);
      return false;
    },
    touchMove: function touchMove(id) {
      clearTimeout(this.timeOutEvent);
      return false;
    },
    touchEnd: function touchEnd(id) {
      clearTimeout(this.timeOutEvent); //清除定时器

      this.timeOutEvent = 0;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/imagepicker/imagepicker.vue?vue&type=script&lang=js&
 /* harmony default export */ var imagepicker_imagepickervue_type_script_lang_js_ = (imagepickervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/imagepicker/imagepicker.vue





/* normalize component */

var imagepicker_component = normalizeComponent(
  imagepicker_imagepickervue_type_script_lang_js_,
  imagepickervue_type_template_id_7ec248d6_scoped_true_render,
  imagepickervue_type_template_id_7ec248d6_scoped_true_staticRenderFns,
  false,
  null,
  "7ec248d6",
  null
  
)

/* harmony default export */ var imagepicker = (imagepicker_component.exports);
// EXTERNAL MODULE: ./src/packages/imagepicker/imagepicker.scss
var imagepicker_imagepicker = __webpack_require__(49);

// CONCATENATED MODULE: ./src/packages/imagepicker/index.js



imagepicker.install = function (Vue) {
  Vue.component(imagepicker.name, imagepicker);
};

/* harmony default export */ var packages_imagepicker = (imagepicker);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/radio/radio.vue?vue&type=template&id=3fdb2ec0&
var radiovue_type_template_id_3fdb2ec0_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('label',{class:['nut-radio', 'nut-radio-size-' + _vm.currentSize],on:{"click":_vm.clickEvt}},[_c('input',{class:{ 'nut-radio-ani': _vm.isAnimated },attrs:{"type":"radio","disabled":_vm.isDisabled,"label":_vm.label},domProps:{"value":_vm.currentValue,"checked":_vm.currentValue === _vm.label}}),_vm._v(" "),_c('span',{staticClass:"nut-radio-label"},[_vm._t("default")],2)])}
var radiovue_type_template_id_3fdb2ec0_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/radio/radio.vue?vue&type=template&id=3fdb2ec0&

// CONCATENATED MODULE: ./src/mixins/findCptUpward/index.js
/* harmony default export */ var findCptUpward = ({
  methods: {
    findCptUpward: function findCptUpward(cptName) {
      var parentCpt = this.$parent;

      while (parentCpt) {
        if (parentCpt.$options.name === cptName) {
          this.parent = parentCpt;
          break;
        }

        parentCpt = parent.$parent;
      }
    }
  }
});
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/radio/radio.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var radiovue_type_script_lang_js_ = ({
  name: 'nut-radio',
  mixins: [findCptUpward],
  props: {
    value: {
      type: [String, Number, Boolean],
      default: false
    },
    label: [String, Number, Boolean],
    size: {
      type: String,
      default: 'base'
    },
    disabled: {
      type: Boolean,
      default: false
    },
    animated: {
      type: Boolean,
      default: true
    }
  },
  data: function data() {
    return {
      parent: null
    };
  },
  computed: {
    currentValue: {
      get: function get() {
        return this.parent ? this.parent.value : this.value;
      },
      set: function set(val) {
        (this.parent || this).$emit('input', val);
      }
    },
    currentSize: function currentSize() {
      return this.parent ? this.parent.size || this.size : this.size;
    },
    isDisabled: function isDisabled() {
      return this.parent ? this.parent.disabled || this.disabled : this.disabled;
    },
    isAnimated: function isAnimated() {
      return this.parent ? this.parent.animated && this.animated : this.animated;
    }
  },
  created: function created() {
    this.findCptUpward('nut-radiogroup');
  },
  methods: {
    clickEvt: function clickEvt(event) {
      if (this.isDisabled) {
        return false;
      }

      this.currentValue = this.label;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/radio/radio.vue?vue&type=script&lang=js&
 /* harmony default export */ var radio_radiovue_type_script_lang_js_ = (radiovue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/radio/radio.vue





/* normalize component */

var radio_component = normalizeComponent(
  radio_radiovue_type_script_lang_js_,
  radiovue_type_template_id_3fdb2ec0_render,
  radiovue_type_template_id_3fdb2ec0_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var radio_radio = (radio_component.exports);
// EXTERNAL MODULE: ./src/packages/radio/radio.scss
var packages_radio_radio = __webpack_require__(50);

// CONCATENATED MODULE: ./src/packages/radio/index.js



radio_radio.install = function (Vue) {
  Vue.component(radio_radio.name, radio_radio);
};

/* harmony default export */ var packages_radio = (radio_radio);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/radiogroup/radiogroup.vue?vue&type=template&id=41de577b&
var radiogroupvue_type_template_id_41de577b_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-radiogroup"},[_vm._t("default")],2)}
var radiogroupvue_type_template_id_41de577b_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/radiogroup/radiogroup.vue?vue&type=template&id=41de577b&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/radiogroup/radiogroup.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var radiogroupvue_type_script_lang_js_ = ({
  name: 'nut-radiogroup',
  props: {
    value: {
      type: [String, Number, Boolean],
      default: false
    },
    disabled: {
      type: Boolean,
      default: false
    },
    size: {
      type: String,
      default: 'base'
    },
    animated: {
      type: Boolean,
      default: true
    }
  }
});
// CONCATENATED MODULE: ./src/packages/radiogroup/radiogroup.vue?vue&type=script&lang=js&
 /* harmony default export */ var radiogroup_radiogroupvue_type_script_lang_js_ = (radiogroupvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/radiogroup/radiogroup.vue





/* normalize component */

var radiogroup_component = normalizeComponent(
  radiogroup_radiogroupvue_type_script_lang_js_,
  radiogroupvue_type_template_id_41de577b_render,
  radiogroupvue_type_template_id_41de577b_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var radiogroup = (radiogroup_component.exports);
// EXTERNAL MODULE: ./src/packages/radiogroup/radiogroup.scss
var radiogroup_radiogroup = __webpack_require__(51);

// CONCATENATED MODULE: ./src/packages/radiogroup/index.js



radiogroup.install = function (Vue) {
  Vue.component(radiogroup.name, radiogroup);
};

/* harmony default export */ var packages_radiogroup = (radiogroup);
// EXTERNAL MODULE: ./src/packages/checkbox/checkbox.scss
var packages_checkbox_checkbox = __webpack_require__(13);

// CONCATENATED MODULE: ./src/packages/checkbox/index.js



checkbox_checkbox.install = function (Vue) {
  Vue.component(checkbox_checkbox.name, checkbox_checkbox);
};

/* harmony default export */ var packages_checkbox = (checkbox_checkbox);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/checkboxgroup/checkboxgroup.vue?vue&type=template&id=2354b2a6&
var checkboxgroupvue_type_template_id_2354b2a6_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-checkboxgroup', { vertical: _vm.vertical }, _vm.customClass]},_vm._l((_vm.checkBoxData),function(item,index){return _c('div',{key:item[_vm.keys.id],staticClass:"checkbox-item"},[_c('nut-checkbox',{attrs:{"name":_vm.name || item[_vm.keys.name],"disabled":_vm.disabled || item[_vm.keys.disabled],"label":item[_vm.keys.label],"animation":_vm.animation,"size":item.size ? item.size : _vm.size,"id":item[_vm.keys.id],"checked":item.checked},on:{"update:checked":function($event){return _vm.$set(item, "checked", $event)},"change":function($event){return _vm.changeEvt(arguments, item)}},model:{value:(_vm.checkboxValues[index]),callback:function ($$v) {_vm.$set(_vm.checkboxValues, index, $$v)},expression:"checkboxValues[index]"}},[_vm._v(_vm._s(item[_vm.keys.label] || item[_vm.keys.value] || item)+"\n    ")])],1)}),0)}
var checkboxgroupvue_type_template_id_2354b2a6_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/checkboxgroup/checkboxgroup.vue?vue&type=template&id=2354b2a6&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/checkboxgroup/checkboxgroup.vue?vue&type=script&lang=js&


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var checkboxgroupvue_type_script_lang_js_ = ({
  name: 'nut-checkboxgroup',
  props: {
    name: String,
    checkBoxData: {
      type: Array,
      required: true
    },
    value: {
      type: Array,
      required: true
    },
    keys: {
      type: Object,
      default: function _default() {
        return {
          id: 'id',
          name: 'name',
          class: 'class',
          label: 'label',
          value: 'value',
          disabled: 'disabled'
        };
      }
    },
    customClass: {
      type: String,
      default: ''
    },
    label: {
      type: [String, Number, Boolean],
      default: ''
    },
    size: {
      type: [String, Number],
      default: 'base'
    },
    disabled: {
      type: Boolean,
      default: false
    },
    animation: {
      type: Boolean,
      default: true
    },
    vertical: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      ignoreChange: false,
      checkboxValues: [],
      initialValue: []
    };
  },
  components: defineProperty_default()({}, checkbox_checkbox.name, checkbox_checkbox),
  watch: {
    value: function value() {
      this.init();
    }
  },
  mounted: function mounted() {
    this.init();
  },
  methods: {
    init: function init() {
      var _this = this;

      this.initialValue = this.value;
      this.checkBoxData.map(function (item) {
        if (typeof_default()(item) === 'object') {
          item.checked = _this.isOptionCheckedByDefault(item);
        }
      });
    },
    isObject: function isObject(obj) {
      return obj !== null && typeof_default()(obj) === 'object';
    },
    looseIndexOf: function looseIndexOf(arr, val) {
      for (var i = 0; i < arr.length; i++) {
        if (this.looseEqual(arr[i], val)) {
          return i;
        }
      }

      return -1;
    },
    isOptionCheckedByDefault: function isOptionCheckedByDefault(item) {
      return this.looseIndexOf(this.initialValue, item[this.keys.value] || item) > -1;
    },
    looseEqual: function looseEqual(a, b) {
      return a == b || (this.isObject(a) && this.isObject(b) ? JSON.stringify(a) === JSON.stringify(b) : false);
    },
    changeEvt: function changeEvt(args, item) {
      if (this.ignoreChange) {
        return;
      }

      var checked = args[0];
      var label = args[1];
      var e = args[2];
      var value = [];
      var itemValue = item[this.keys.value] || item;
      var i = this.looseIndexOf(this.value, itemValue);

      if (checked && i < 0) {
        value = this.value.concat(itemValue);
      }

      if (!checked && i > -1) {
        value = this.value.slice(0, i).concat(this.value.slice(i + 1));
      }

      this.$emit('input', value);
      this.$emit('change', value, label, e);
    },
    toggleAll: function toggleAll(checked) {
      if (checked === false) {
        this.$emit('input', []);
        return;
      }

      if (checked === true) {
        this.checkBoxData.map(function (item) {
          item.checked = true;
        });
      }

      if (!checked) {
        this.checkBoxData.map(function (item) {
          item.checked = !item.checked;
        });
      }

      var value = [],
          label = [];
      var resData = this.checkBoxData.filter(function (item) {
        if (item.checked) {
          value.push(item.value);
          label.push(item.label);
        }

        return item.checked;
      });
      this.$emit('input', value);
      this.$emit('change', value, label, null);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/checkboxgroup/checkboxgroup.vue?vue&type=script&lang=js&
 /* harmony default export */ var checkboxgroup_checkboxgroupvue_type_script_lang_js_ = (checkboxgroupvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/checkboxgroup/checkboxgroup.vue





/* normalize component */

var checkboxgroup_component = normalizeComponent(
  checkboxgroup_checkboxgroupvue_type_script_lang_js_,
  checkboxgroupvue_type_template_id_2354b2a6_render,
  checkboxgroupvue_type_template_id_2354b2a6_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var checkboxgroup = (checkboxgroup_component.exports);
// EXTERNAL MODULE: ./src/packages/checkboxgroup/checkboxgroup.scss
var checkboxgroup_checkboxgroup = __webpack_require__(52);

// CONCATENATED MODULE: ./src/packages/checkboxgroup/index.js



checkboxgroup.install = function (Vue) {
  Vue.component(checkboxgroup.name, checkboxgroup);
};

/* harmony default export */ var packages_checkboxgroup = (checkboxgroup);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/shortpassword/shortpassword.vue?vue&type=template&id=0f4bfa14&
var shortpasswordvue_type_template_id_0f4bfa14_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.show),expression:"show"}],staticClass:"nut-short-pwd"},[_c('transition',{attrs:{"name":"fade"}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.show),expression:"show"}],staticClass:"nut-mask",on:{"click":_vm.closeLayer}})]),_vm._v(" "),_c('transition',{attrs:{"name":_vm.layerTran}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.show),expression:"show"}],staticClass:"nut-layer",class:{ 'nut-layer-center': _vm.isCenter }},[_c('div',{staticClass:"nut-title"},[_c('span',{staticClass:"nut-close",on:{"click":_vm.closeLayer}}),_vm._v("\n        "+_vm._s(_vm.nutTranslate('lang.shortpassword.tip1'))+"\n      ")]),_vm._v(" "),_c('div',{staticClass:"nut-input-w"},[_c('input',{directives:[{name:"model",rawName:"v-model",value:(_vm.shortpwdValue),expression:"shortpwdValue"}],ref:"realInput",staticClass:"nut-real-input",attrs:{"type":"tel","maxlength":"6","autocomplete":"off","autofocus":"autofocus"},domProps:{"value":(_vm.shortpwdValue)},on:{"input":[function($event){if($event.target.composing){ return; }_vm.shortpwdValue=$event.target.value},function($event){return _vm.shortpwdInput($event)}]}}),_vm._v(" "),_c('div',{ref:"nutFakeList",staticClass:"nut-fake-list"},[_c('ul',_vm._l((_vm.fakeInputItems),function(item){return _c('li',{key:item.id},[_c('input',{directives:[{name:"model",rawName:"v-model",value:(item.val),expression:"item.val"}],attrs:{"type":"password","maxlength":"1"},domProps:{"value":(item.val)},on:{"input":function($event){if($event.target.composing){ return; }_vm.$set(item, "val", $event.target.value)}}})])}),0)]),_vm._v(" "),(_vm.link != '')?_c('div',{staticClass:"nut-forget"},[_c('a',{attrs:{"href":_vm.link}},[_vm._v(_vm._s(_vm.nutTranslate('lang.shortpassword.tip2')))])]):_vm._e()])])])],1)}
var shortpasswordvue_type_template_id_0f4bfa14_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/shortpassword/shortpassword.vue?vue&type=template&id=0f4bfa14&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/shortpassword/shortpassword.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var shortpasswordvue_type_script_lang_js_ = ({
  name: 'nut-shortpassword',
  mixins: [mixins_locale],
  props: {
    visible: {
      type: Boolean,
      default: false
    },
    link: {
      type: String,
      default: 'javascript:;'
    },
    type: {
      type: String,
      default: 'bottom'
    }
  },
  data: function data() {
    return {
      shortpwdValue: '',
      regExp: /^[0-9]*$/,
      // fakeCursorStyle:{
      // 	display:'none',
      // 	left:'0px'
      // },
      fakeInputItems: [{
        id: 1,
        val: ''
      }, {
        id: 2,
        val: ''
      }, {
        id: 3,
        val: ''
      }, {
        id: 4,
        val: ''
      }, {
        id: 5,
        val: ''
      }, {
        id: 6,
        val: ''
      }],
      timer: null,
      isCenter: this.type == 'bottom' ? false : true,
      layerTran: this.type == 'bottom' ? 'popup' : 'fade',
      show: false
    };
  },
  watch: {
    visible: function visible(val, oldVal) {
      var _this = this;

      if (!val) {
        clearTimeout(this.timer);
        this.timer = setTimeout(function () {
          _this.show = val;
        }, 100);
      } else {
        this.show = val;
      }
    }
  },
  methods: {
    closeLayer: function closeLayer() {
      var _this2 = this;

      this.timer = setTimeout(function () {
        _this2.$emit('close');
      }, 300);
    },
    shortpwdInput: function shortpwdInput(e) {
      var _this3 = this;

      var val = e.target.value;

      if (this.regExp.test(val)) {
        //位移假光标
        if (val.length < 6) {
          var num = this.$refs.nutFakeList.offsetLeft + 26;
          var left = val.length * 54 + num; // this.fakeCursorStyle = {
          // 	'left':left+'px',
          // 	'display':'block'
          // }
        } else {
          // this.fakeCursorStyle = {
          // 	'display':'none'
          // }
          this.$refs.realInput.blur();
          this.timer = setTimeout(function () {
            //如果是6位输入满，将直接关闭弹层，给出输入的值
            _this3.$emit('close', val);

            _this3.shortpwdValue = '';
            _this3.fakeInputItems = [{
              id: 1,
              val: ''
            }, {
              id: 2,
              val: ''
            }, {
              id: 3,
              val: ''
            }, {
              id: 4,
              val: ''
            }, {
              id: 5,
              val: ''
            }, {
              id: 6,
              val: ''
            }];
          }, 300);
        }

        for (var i = 0; i < val.length; i++) {
          this.fakeInputItems[i].val = val[i];
        }
      } else {
        //清空非数字
        this.shortpwdValue = val.replace(/\D/g, '');
      } //删除操作的时候同步假密码框


      for (var i = 0; i < 6; i++) {
        if (i >= val.length) {
          this.fakeInputItems[i].val = '';
        }
      }
    }
  },
  computed: {},
  mounted: function mounted() {},
  destroyed: function destroyed() {
    this.timer = null;
  }
});
// CONCATENATED MODULE: ./src/packages/shortpassword/shortpassword.vue?vue&type=script&lang=js&
 /* harmony default export */ var shortpassword_shortpasswordvue_type_script_lang_js_ = (shortpasswordvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/shortpassword/shortpassword.vue





/* normalize component */

var shortpassword_component = normalizeComponent(
  shortpassword_shortpasswordvue_type_script_lang_js_,
  shortpasswordvue_type_template_id_0f4bfa14_render,
  shortpasswordvue_type_template_id_0f4bfa14_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var shortpassword = (shortpassword_component.exports);
// EXTERNAL MODULE: ./src/packages/shortpassword/shortpassword.scss
var shortpassword_shortpassword = __webpack_require__(53);

// CONCATENATED MODULE: ./src/packages/shortpassword/index.js



shortpassword.install = function (Vue) {
  Vue.component(shortpassword.name, shortpassword);
};

/* harmony default export */ var packages_shortpassword = (shortpassword);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/skeleton.vue?vue&type=template&id=42732df9&
var skeletonvue_type_template_id_42732df9_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"vue-skeleton-loading"},[_c('div',{staticClass:"skeleton-bac-animation"}),_vm._v(" "),_c('div',{staticClass:"skeleton-bac-content"},[_vm._t("default")],2)])}
var skeletonvue_type_template_id_42732df9_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/skeleton/skeleton.vue?vue&type=template&id=42732df9&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/skeleton.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
/* harmony default export */ var skeletonvue_type_script_lang_js_ = ({
  name: 'nut-skeleton',
  data: function data() {
    return {};
  }
});
// CONCATENATED MODULE: ./src/packages/skeleton/skeleton.vue?vue&type=script&lang=js&
 /* harmony default export */ var skeleton_skeletonvue_type_script_lang_js_ = (skeletonvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/skeleton/skeleton.vue





/* normalize component */

var skeleton_component = normalizeComponent(
  skeleton_skeletonvue_type_script_lang_js_,
  skeletonvue_type_template_id_42732df9_render,
  skeletonvue_type_template_id_42732df9_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var skeleton = (skeleton_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/basic/skeleton-circle.vue?vue&type=template&id=2cbcc335&
var skeleton_circlevue_type_template_id_2cbcc335_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"vueSkeletonCircle",staticClass:"vue-skeleton-circle",style:({
    backgroundColor: _vm.backColor,
    width: _vm.diameter,
    height: _vm.diameter,
    'border-radius': '50%',
    margin: _vm.margin
  })})}
var skeleton_circlevue_type_template_id_2cbcc335_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-circle.vue?vue&type=template&id=2cbcc335&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/basic/skeleton-circle.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var skeleton_circlevue_type_script_lang_js_ = ({
  name: 'skeletonCircle',
  data: function data() {
    return {};
  },
  props: {
    backColor: {
      type: String,
      default: '#efefef'
    },
    diameter: {
      type: String,
      default: '50px'
    },
    margin: {
      type: String,
      default: '0 0 0 0'
    }
  }
});
// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-circle.vue?vue&type=script&lang=js&
 /* harmony default export */ var basic_skeleton_circlevue_type_script_lang_js_ = (skeleton_circlevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-circle.vue





/* normalize component */

var skeleton_circle_component = normalizeComponent(
  basic_skeleton_circlevue_type_script_lang_js_,
  skeleton_circlevue_type_template_id_2cbcc335_render,
  skeleton_circlevue_type_template_id_2cbcc335_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var skeleton_circle = (skeleton_circle_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/basic/skeleton-square.vue?vue&type=template&id=0daff141&
var skeleton_squarevue_type_template_id_0daff141_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"vue-skeleton-square-wrap"},_vm._l((_vm.count),function(i){return _c('div',{key:i,staticClass:"vue-skeleton-square",style:({
      backgroundColor: _vm.backColor,
      width: _vm.width,
      height: _vm.height,
      margin: _vm.margin
    })})}),0)}
var skeleton_squarevue_type_template_id_0daff141_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-square.vue?vue&type=template&id=0daff141&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/basic/skeleton-square.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var skeleton_squarevue_type_script_lang_js_ = ({
  name: 'skeletonSquare',
  data: function data() {
    return {};
  },
  props: {
    backColor: {
      type: String,
      default: '#efefef'
    },
    width: {
      type: String,
      default: '100%'
    },
    height: {
      type: String,
      default: '12px'
    },
    margin: {
      type: String,
      default: '0 0 0 0'
    },
    count: {
      type: Number,
      default: 1
    }
  }
});
// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-square.vue?vue&type=script&lang=js&
 /* harmony default export */ var basic_skeleton_squarevue_type_script_lang_js_ = (skeleton_squarevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/skeleton/basic/skeleton-square.vue





/* normalize component */

var skeleton_square_component = normalizeComponent(
  basic_skeleton_squarevue_type_script_lang_js_,
  skeleton_squarevue_type_template_id_0daff141_render,
  skeleton_squarevue_type_template_id_0daff141_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var skeleton_square = (skeleton_square_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/layout/skeleton-row.vue?vue&type=template&id=2deb289d&
var skeleton_rowvue_type_template_id_2deb289d_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"vue-skeleton-row",style:({
    width: _vm.width,
    padding: _vm.padding,
    'justify-content': _vm.center
  })},[_vm._t("default")],2)}
var skeleton_rowvue_type_template_id_2deb289d_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-row.vue?vue&type=template&id=2deb289d&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/layout/skeleton-row.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var skeleton_rowvue_type_script_lang_js_ = ({
  name: 'row',
  data: function data() {
    return {};
  },
  props: {
    width: {
      type: String,
      default: 'auto'
    },
    padding: {
      type: String,
      default: '0 0 0 0'
    },
    center: {
      type: String,
      default: 'flex-start'
    }
  }
});
// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-row.vue?vue&type=script&lang=js&
 /* harmony default export */ var layout_skeleton_rowvue_type_script_lang_js_ = (skeleton_rowvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-row.vue





/* normalize component */

var skeleton_row_component = normalizeComponent(
  layout_skeleton_rowvue_type_script_lang_js_,
  skeleton_rowvue_type_template_id_2deb289d_render,
  skeleton_rowvue_type_template_id_2deb289d_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var skeleton_row = (skeleton_row_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/layout/skeleton-column.vue?vue&type=template&id=6fdc2362&
var skeleton_columnvue_type_template_id_6fdc2362_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"vue-skeleton-column",style:({
    width: _vm.width,
    padding: _vm.padding,
    'align-items': _vm.center
  })},[_vm._t("default")],2)}
var skeleton_columnvue_type_template_id_6fdc2362_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-column.vue?vue&type=template&id=6fdc2362&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/skeleton/layout/skeleton-column.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var skeleton_columnvue_type_script_lang_js_ = ({
  name: 'column',
  data: function data() {
    return {};
  },
  props: {
    width: {
      type: String,
      width: 'auto'
    },
    padding: {
      type: String,
      default: '0 0 0 0'
    },
    center: {
      type: String,
      default: 'flex-start'
    }
  }
});
// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-column.vue?vue&type=script&lang=js&
 /* harmony default export */ var layout_skeleton_columnvue_type_script_lang_js_ = (skeleton_columnvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/skeleton/layout/skeleton-column.vue





/* normalize component */

var skeleton_column_component = normalizeComponent(
  layout_skeleton_columnvue_type_script_lang_js_,
  skeleton_columnvue_type_template_id_6fdc2362_render,
  skeleton_columnvue_type_template_id_6fdc2362_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var skeleton_column = (skeleton_column_component.exports);
// CONCATENATED MODULE: ./src/packages/skeleton/_skeleton.js





skeleton.skeletonCircle = skeleton_circle;
skeleton.skeletonSquare = skeleton_square;
skeleton.skeletonRow = skeleton_row;
skeleton.skeletonColumn = skeleton_column;
/* harmony default export */ var _skeleton = (skeleton);
// EXTERNAL MODULE: ./src/packages/skeleton/skeleton.scss
var skeleton_skeleton = __webpack_require__(54);

// CONCATENATED MODULE: ./src/packages/skeleton/index.js


var skeletonCircle = _skeleton.skeletonCircle,
    skeletonSquare = _skeleton.skeletonSquare,
    skeletonRow = _skeleton.skeletonRow,
    skeletonColumn = _skeleton.skeletonColumn;

_skeleton.install = function (Vue) {
  Vue.component(_skeleton.name, _skeleton);
};

skeletonCircle.install = function (Vue) {
  Vue.component(skeletonCircle.name, skeletonCircle);
};

skeletonSquare.install = function (Vue) {
  Vue.component(skeletonSquare.name, skeletonSquare);
};

skeletonRow.install = function (Vue) {
  Vue.component(skeletonRow.name, skeletonRow);
};

skeletonColumn.install = function (Vue) {
  Vue.component(skeletonColumn.name, skeletonColumn);
};

/* harmony default export */ var packages_skeleton = ({
  skeleton: _skeleton,
  skeletonCircle: skeletonCircle,
  skeletonSquare: skeletonSquare,
  skeletonRow: skeletonRow,
  skeletonColumn: skeletonColumn
});
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/scroller.vue?vue&type=template&id=22b7c230&
var scrollervue_type_template_id_22b7c230_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-scroller"},[(_vm.type === 'vertical')?[_c('nut-vert-scroll',{attrs:{"stretch":_vm.stretch,"is-un-more":_vm.isUnMore,"is-loading":_vm.isLoading,"threshold":_vm.threshold,"pulldown-txt":_vm.pulldownTxt,"load-more-txt":_vm.loadMoreTxt,"unload-more-txt":_vm.unloadMoreTxt,"props-time":_vm.propsTime,"scroll-to":_vm.scrollTo},on:{"loadMore":_vm.loadMore,"pulldown":_vm.pulldown,"scrollToCbk":_vm.scrollToCbk,"scrollChange":_vm.scrollChange}},[_vm._t("list",null,{"slot":"list"})],2)]:(_vm.type === 'horizontal')?[_c('nut-hor-scroll',{attrs:{"stretch":_vm.stretch,"scroll-to":_vm.scrollTo},on:{"jump":_vm.jump,"scrollToCbk":_vm.scrollToCbk}},[_vm._t("list",null,{"slot":"list"}),_vm._v(" "),_vm._t("more",null,{"slot":"more"}),_vm._v(" "),_vm._t("arrow",null,{"slot":"arrow"})],2)]:_vm._e()],2)}
var scrollervue_type_template_id_22b7c230_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/scroller/scroller.vue?vue&type=template&id=22b7c230&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/vertical-scroll.vue?vue&type=template&id=bb0ca356&
var vertical_scrollvue_type_template_id_bb0ca356_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"wrapper",staticClass:"nut-vert-scroll"},[_c('div',{ref:"list",staticClass:"nut-vert-list",style:({ 'min-height': _vm.listMinHeightStyle })},[(_vm.isFirstPull)?_c('div',{staticClass:"nut-vert-pulldown"},[(!_vm.isLoading)?_c('div',{staticClass:"nut-vert-pulldown-txt"},[_vm._v(_vm._s(_vm.pulldownTxt))]):_c('div',{staticClass:"nut-vert-pulldown-status"},[_c('span',{staticClass:"nut-vert-loading"}),_vm._v(" "),_c('span',{staticClass:"nut-vert-loading-txt"},[_vm._v("加载中...")])])]):_vm._e(),_vm._v(" "),_vm._t("list"),_vm._v(" "),_c('div',{staticClass:"nut-vert-loadmore"},[(!_vm.isUnMore && _vm.isShowLoadMore)?[(_vm.isLoading)?_c('div',{staticClass:"nut-vert-load-status"},[_c('span',{staticClass:"nut-vert-loading"}),_vm._v(" "),_c('span',{staticClass:"nut-vert-loading-txt"},[_vm._v("加载中...")])]):_vm._e()]:(_vm.isUnMore)?[_c('div',{staticClass:"nut-vert-unloadmore-txt"},[_vm._v(_vm._s(_vm.unloadMoreTxt))])]:_vm._e()],2)],2)])}
var vertical_scrollvue_type_template_id_bb0ca356_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/scroller/vertical-scroll.vue?vue&type=template&id=bb0ca356&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/vertical-scroll.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var vertical_scrollvue_type_script_lang_js_ = ({
  name: 'nut-vert-scroll',
  props: {
    stretch: {
      type: Number,
      default: 100
    },
    isUnMore: {
      type: Boolean,
      default: false
    },
    isLoading: {
      type: Boolean,
      default: false
    },
    pulldownTxt: {
      type: String,
      default: '下拉刷新'
    },
    loadMoreTxt: {
      type: String,
      default: '上拉加载'
    },
    unloadMoreTxt: {
      type: String,
      default: '没有更多了'
    },
    threshold: {
      type: Number,
      default: 100
    },
    propsTime: {
      type: Number,
      default: 0
    },
    scrollTo: {
      type: Number,
      default: 1
    }
  },
  watch: {
    isLoading: function isLoading(status) {
      var _this = this;

      if (!status && this.realMove === 0) {
        clearTimeout(this.timer);
        this.timer = setTimeout(function () {
          _this.setTransform(_this.realMove, 'end', null);
        }, this.propsTime);
      }
    },
    isUnMore: function isUnMore() {
      this.isShow();
    },
    scrollTo: function scrollTo(val) {
      if (typeof val === 'number' && !isNaN(val) && val <= 0) {
        this.setTransform(val, null, 500);
        this.$emit('scrollToCbk');
      }
    }
  },
  data: function data() {
    return {
      touchParams: {
        startY: 0,
        endY: 0,
        startTime: 0,
        endTime: 0
      },
      translateY: 0,
      scrollDistance: 0,
      timer: null,
      timerEmit: null,
      realMove: 0,
      isShowLoadMore: false,
      listMinHeightStyle: 'auto',
      isFirstPull: true
    };
  },
  methods: {
    isShow: function isShow() {
      var wrapH = this.$refs.wrapper.offsetHeight;
      var listH = this.$refs.list.offsetHeight;

      if (wrapH < listH) {
        this.isShowLoadMore = true;
        this.listMinHeightStyle = 'auto';
      } else {
        this.isShowLoadMore = false;
        this.isFirstPull = true;
        this.listMinHeightStyle = "".concat(wrapH, "px");
      }
    },
    setTransform: function setTransform() {
      var translateY = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;
      var type = arguments.length > 1 ? arguments[1] : undefined;
      var time = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 500;

      if (type === 'end') {
        this.$refs.list.style.webkitTransition = "transform ".concat(time, "ms cubic-bezier(0.19, 1, 0.22, 1)");
      } else {
        this.$refs.list.style.webkitTransition = '';
      }

      this.$refs.list.style.webkitTransform = "translate3d(0, ".concat(translateY, "px, 0)");
      this.scrollDistance = translateY;
      this.$emit('scrollChange', translateY);
    },
    setMove: function setMove(move, type, time) {
      var _this2 = this;

      var updateMove = move + this.translateY;
      var h = this.$refs.wrapper.offsetHeight;
      var maxMove = -this.$refs.list.offsetHeight + h;

      if (type === 'end') {
        if (updateMove > 0) {
          this.realMove = 0;

          if ((!this.isShowLoadMore || this.isFirstPull) && !this.isLoading && updateMove > 20) {
            updateMove = 50;
            clearTimeout(this.timerEmit);
            this.timerEmit = setTimeout(function () {
              _this2.$emit('pulldown');
            }, time / 2);
          } else {
            this.isFirstPull = true;
            updateMove = 0;
          }
        } else if (updateMove < 0 && updateMove < maxMove + this.threshold) {
          if (updateMove < maxMove) {
            updateMove = maxMove;
          }

          this.realMove = maxMove;

          if (!this.isLoading && !this.isUnMore) {
            //clearTimeout(this.timerEmit);
            //this.timerEmit = setTimeout(() => {
            this.$emit('loadMore'); // }, time / 2);
          }
        } // if (updateMove == 50 && !this.isLoading) {
        //     clearTimeout(this.timer);
        //     this.timer = setTimeout(() => {
        //         this.setTransform(this.realMove, 'end', null);
        //     }, 3000);
        // }


        this.setTransform(updateMove, type, time);
      } else {
        if (updateMove > 0 && updateMove > this.stretch) {
          updateMove = this.stretch;
        } else if (updateMove < maxMove - this.stretch) {
          updateMove = maxMove - this.stretch;
        }

        this.setTransform(updateMove, null, null);
      }
    },
    touchStart: function touchStart(event) {
      // event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.startY = changedTouches.pageY;
      this.touchParams.startTime = event.timestamp || Date.now();
      this.translateY = this.scrollDistance;
    },
    touchMove: function touchMove(event) {
      event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;

      if (move < 0 && this.isShowLoadMore && this.isFirstPull) {
        this.isFirstPull = false;
      }

      this.setMove(move);
    },
    touchEnd: function touchEnd(event) {
      // event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastY = changedTouches.pageY;
      this.touchParams.lastTime = event.timestamp || Date.now();
      var move = this.touchParams.lastY - this.touchParams.startY;
      var moveTime = this.touchParams.lastTime - this.touchParams.startTime;
      var h = this.$refs.wrapper.offsetHeight;
      var maxMove = -this.$refs.list.offsetHeight + h;

      if (moveTime <= 300) {
        move = move * 2;

        if (move < 0 && move < maxMove) {
          move = maxMove;
        }

        moveTime = moveTime + 500;
        this.setMove(move, 'end', moveTime);
      } else {
        this.setMove(move, 'end');
      }
    }
  },
  mounted: function mounted() {
    var _this3 = this;

    this.$nextTick(function () {
      _this3.isShow(); // 监听


      _this3.$el.addEventListener('touchstart', _this3.touchStart);

      _this3.$el.addEventListener('touchmove', _this3.touchMove);

      _this3.$el.addEventListener('touchend', _this3.touchEnd);
    });
  },
  beforeDestroy: function beforeDestroy() {
    // 移除监听
    this.$el.removeEventListener('touchstart', this.touchStart);
    this.$el.removeEventListener('touchmove', this.touchMove);
    this.$el.removeEventListener('touchend', this.touchEnd);
    clearTimeout(this.timer);
    clearTimeout(this.timerEmit);
  }
});
// CONCATENATED MODULE: ./src/packages/scroller/vertical-scroll.vue?vue&type=script&lang=js&
 /* harmony default export */ var scroller_vertical_scrollvue_type_script_lang_js_ = (vertical_scrollvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/scroller/vertical-scroll.vue





/* normalize component */

var vertical_scroll_component = normalizeComponent(
  scroller_vertical_scrollvue_type_script_lang_js_,
  vertical_scrollvue_type_template_id_bb0ca356_render,
  vertical_scrollvue_type_template_id_bb0ca356_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var vertical_scroll = (vertical_scroll_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/horizontal-scroll.vue?vue&type=template&id=04a6c994&
var horizontal_scrollvue_type_template_id_04a6c994_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"wrapper",staticClass:"nut-hor-scroll"},[_c('div',{ref:"list",staticClass:"nut-hor-list"},[_vm._t("list"),_vm._v(" "),(_vm.$slots.more && _vm.isShowLoadMore)?_c('div',{staticClass:"nut-hor-control"},[_vm._t("more")],2):_vm._e(),_vm._v(" "),(_vm.$slots.arrow)?_vm._t("arrow"):_vm._e()],2)])}
var horizontal_scrollvue_type_template_id_04a6c994_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/scroller/horizontal-scroll.vue?vue&type=template&id=04a6c994&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/horizontal-scroll.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var horizontal_scrollvue_type_script_lang_js_ = ({
  name: 'nut-hor-scroll',
  props: {
    stretch: {
      type: Number,
      default: 40
    },
    scrollTo: {
      type: Number,
      default: 1
    },
    listWidth: {
      type: Number,
      default: 0
    }
  },
  watch: {
    scrollTo: function scrollTo(val) {
      if (typeof val === 'number' && !isNaN(val) && val <= 0) {
        this.setTransform(val, null, 500);
        this.$emit('scrollToCbk');
      }
    }
  },
  data: function data() {
    return {
      touchParams: {
        startX: 0,
        endX: 0,
        startY: 0,
        endY: 0,
        startTime: 0,
        endTime: 0
      },
      transformX: 0,
      scrollDistance: 0,
      timer: null,
      isShowLoadMore: false,
      isFirstShow: false
    };
  },
  methods: {
    isShow: function isShow() {
      var wrapH = this.listWidth ? this.listWidth : window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
      var listH = this.$refs.list.offsetWidth;

      if (wrapH <= listH) {
        this.isShowLoadMore = true;
      } else {
        this.isShowLoadMore = false;
      }
    },
    setTransform: function setTransform() {
      var translateX = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;
      var type = arguments.length > 1 ? arguments[1] : undefined;
      var time = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 500;
      var unit = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 'px';
      this.scrollDistance = translateX;
      translateX = translateX + unit;

      if (type === 'end') {
        this.$refs.list.style.webkitTransition = "transform ".concat(time, "ms cubic-bezier(0.19, 1, 0.22, 1)");
      } else {
        this.$refs.list.style.webkitTransition = '';
      }

      this.$refs.list.style.webkitTransform = "translate3d(".concat(translateX, ", 0, 0)");
    },
    setMove: function setMove(move, type, time) {
      var updateMove = move + this.transformX;
      var w = this.listWidth ? this.listWidth : window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
      var offsetWidth = this.$refs.list.offsetWidth;

      if (type === 'end') {
        if (updateMove > 0) {
          updateMove = 0;
        } else if (updateMove < -offsetWidth + w) {
          if (-offsetWidth + w <= 0) {
            updateMove = -offsetWidth + w;
          } else {
            updateMove = 0;
          }
        }

        this.setTransform(updateMove, type, time);
      } else {
        var maxMove = -offsetWidth + w;

        if (updateMove > 0 && updateMove > this.stretch) {
          updateMove = this.stretch;
        } else if (updateMove < maxMove - this.stretch) {
          if (maxMove <= 0) {
            updateMove = maxMove - this.stretch;
          } else {
            updateMove = updateMove < -this.stretch ? -this.stretch : updateMove;
          }
        }

        this.setTransform(updateMove, null, null);
      }
    },
    touchStart: function touchStart(event) {
      // event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.startX = changedTouches.pageX;
      this.touchParams.startY = changedTouches.pageY;
      this.touchParams.startTime = event.timestamp || Date.now();
      this.transformX = this.scrollDistance;
    },
    touchEvent: function touchEvent(changedTouches, callback) {
      this.touchParams.lastX = changedTouches.pageX;
      this.touchParams.lastY = changedTouches.pageY;
      var moveY = this.touchParams.lastY - this.touchParams.startY;
      var move = this.touchParams.lastX - this.touchParams.startX;

      if (!(Math.abs(move) > 20 && Math.abs(move) > Math.abs(moveY))) {
        return false;
      } else {
        var w = this.listWidth ? this.listWidth : window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
        var maxMove = -this.$refs.list.offsetWidth + w;
        callback && callback(move, maxMove, moveY);
      }
    },
    touchMove: function touchMove(event) {
      var _this = this;

      //event.preventDefault();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastTime = event.timestamp || Date.now();
      var moveTime = this.touchParams.lastTime - this.touchParams.startTime;
      this.touchEvent(changedTouches, function (move, maxMove, moveY) {
        event.preventDefault();

        if (event.cancelable) {
          event.preventDefault();
        }

        if (move > 0 && _this.isFirstShow) {
          _this.isFirstShow = false;
        }

        _this.setMove(move);
      });
    },
    touchEnd: function touchEnd(event) {
      var _this2 = this;

      event.stopPropagation();
      var changedTouches = event.changedTouches[0];
      this.touchParams.lastTime = event.timestamp || Date.now();
      var moveTime = this.touchParams.lastTime - this.touchParams.startTime;
      this.touchEvent(changedTouches, function (move, maxMove) {
        //if (moveTime <= 300) {
        if (Math.abs(move) > 100) {
          move = move * 1.5;
        } // 释放跳转之类


        if (move < 0 && move + _this2.transformX < maxMove - 20 && _this2.isFirstShow) {
          _this2.$emit('jump');
        }

        if (!_this2.isFirstShow && move < 0 && move + _this2.transformX < maxMove && _this2.$slots.more) {
          _this2.isFirstShow = true; //move = maxMove - this.transformX;
        }

        if (moveTime <= 300) {
          moveTime = moveTime + 500;

          _this2.setMove(move, 'end', moveTime);
        } else {
          _this2.setMove(move, 'end');
        }
      });
    }
  },
  mounted: function mounted() {
    var _this3 = this;

    this.$nextTick(function () {
      _this3.isShow(); // 监听


      _this3.$el.addEventListener('touchstart', _this3.touchStart);

      _this3.$el.addEventListener('touchmove', _this3.touchMove);

      _this3.$el.addEventListener('touchend', _this3.touchEnd);
    });
  },
  beforeDestroy: function beforeDestroy() {
    // 移除监听
    this.$el.removeEventListener('touchstart', this.touchStart);
    this.$el.removeEventListener('touchmove', this.touchMove);
    this.$el.removeEventListener('touchend', this.touchEnd);
    clearTimeout(this.timer);
  }
});
// CONCATENATED MODULE: ./src/packages/scroller/horizontal-scroll.vue?vue&type=script&lang=js&
 /* harmony default export */ var scroller_horizontal_scrollvue_type_script_lang_js_ = (horizontal_scrollvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/scroller/horizontal-scroll.vue





/* normalize component */

var horizontal_scroll_component = normalizeComponent(
  scroller_horizontal_scrollvue_type_script_lang_js_,
  horizontal_scrollvue_type_template_id_04a6c994_render,
  horizontal_scrollvue_type_template_id_04a6c994_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var horizontal_scroll = (horizontal_scroll_component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/scroller/scroller.vue?vue&type=script&lang=js&


var scrollervue_type_script_lang_js_components;

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var scrollervue_type_script_lang_js_ = ({
  name: 'nut-scroller',
  props: {
    type: {
      type: String,
      default: 'horizontal'
    },
    stretch: {
      type: Number,
      default: 100
    },
    isUnMore: {
      type: Boolean,
      default: false
    },
    isLoading: {
      type: Boolean,
      default: false
    },
    threshold: {
      type: Number,
      default: 100
    },
    pulldownTxt: {
      type: String,
      default: '下拉刷新'
    },
    loadMoreTxt: {
      type: String,
      default: '上拉加载'
    },
    unloadMoreTxt: {
      type: String,
      default: '没有更多了'
    },
    propsTime: {
      type: Number,
      default: 0
    },
    scrollTo: {
      type: Number,
      default: 1
    }
  },
  data: function data() {
    return {};
  },
  components: (scrollervue_type_script_lang_js_components = {}, defineProperty_default()(scrollervue_type_script_lang_js_components, vertical_scroll.name, vertical_scroll), defineProperty_default()(scrollervue_type_script_lang_js_components, horizontal_scroll.name, horizontal_scroll), scrollervue_type_script_lang_js_components),
  methods: {
    loadMore: function loadMore() {
      this.$emit('loadMore');
    },
    jump: function jump() {
      this.$emit('jump');
    },
    pulldown: function pulldown() {
      this.$emit('pulldown');
    },
    scrollToCbk: function scrollToCbk() {
      this.$emit('scrollToCbk');
    },
    scrollChange: function scrollChange(event) {
      this.$emit('scrollChange', event);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/scroller/scroller.vue?vue&type=script&lang=js&
 /* harmony default export */ var scroller_scrollervue_type_script_lang_js_ = (scrollervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/scroller/scroller.vue





/* normalize component */

var scroller_component = normalizeComponent(
  scroller_scrollervue_type_script_lang_js_,
  scrollervue_type_template_id_22b7c230_render,
  scrollervue_type_template_id_22b7c230_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var scroller = (scroller_component.exports);
// EXTERNAL MODULE: ./src/packages/scroller/scroller.scss
var scroller_scroller = __webpack_require__(55);

// CONCATENATED MODULE: ./src/packages/scroller/index.js



scroller.install = function (Vue) {
  Vue.component(scroller.name, scroller);
};

/* harmony default export */ var packages_scroller = (scroller);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/backtop/backtop.vue?vue&type=template&id=5ea5b2b8&
var backtopvue_type_template_id_5ea5b2b8_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-backtop', { show: _vm.backTop }],style:(_vm.styles),on:{"click":function($event){$event.stopPropagation();return _vm.click($event)}}},[_vm._t("default",[_c('div',{staticClass:"nut-backtop-main"})])],2)}
var backtopvue_type_template_id_5ea5b2b8_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/backtop/backtop.vue?vue&type=template&id=5ea5b2b8&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/backtop/backtop.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
/* harmony default export */ var backtopvue_type_script_lang_js_ = ({
  name: 'nut-backtop',
  props: {
    distance: {
      type: Number,
      default: 200
    },
    bottom: {
      type: Number,
      default: 20
    },
    right: {
      type: Number,
      default: 10
    },
    duration: {
      type: Number,
      default: 1000
    },
    isAnimation: {
      type: Boolean,
      default: true
    },
    elId: {
      type: String,
      default: ''
    },
    zIndex: {
      type: Number,
      default: 1111
    }
  },
  data: function data() {
    return {
      backTop: false,
      scrollEl: window
    };
  },
  mounted: function mounted() {
    this.init();
  },
  activated: function activated() {
    if (this.keepAlive) {
      this.keepAlive = false;
      this.init();
    }
  },
  deactivated: function deactivated() {
    this.keepAlive = true;
    this.removeEventListener();
  },
  destroyed: function destroyed() {
    this.removeEventListener();
  },
  computed: {
    styles: function styles() {
      return {
        bottom: "".concat(this.bottom, "px"),
        right: "".concat(this.right, "px"),
        'z-index': this.zIndex
      };
    }
  },
  methods: {
    addEventListener: function addEventListener() {
      this.scrollEl.addEventListener('scroll', this.scrollListener, false);
      this.scrollEl.addEventListener('resize', this.scrollListener, false);
    },
    removeEventListener: function removeEventListener() {
      this.scrollEl.removeEventListener('scroll', this.scrollListener, false);
      this.scrollEl.removeEventListener('resize', this.scrollListener, false);
    },
    requestAniFrame: function requestAniFrame() {
      return window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame || function (callback) {
        window.setTimeout(callback, 1000 / 60);
      };
    },
    initCancelAniFrame: function initCancelAniFrame() {
      var vendors = ['webkit', 'moz'];

      for (var x = 0; x < vendors.length && !window.requestAnimationFrame; ++x) {
        window.cancelAnimationFrame = window[vendors[x] + 'CancelAnimationFrame'] || window[vendors[x] + 'CancelRequestAnimationFrame'];
      }
    },
    init: function init() {
      if (this.elId && document.getElementById(this.elId)) {
        this.scrollEl = document.getElementById(this.elId);
      }

      this.addEventListener();
      this.initCancelAniFrame();
    },
    scrollListener: function scrollListener() {
      this.scrollTop = this.scrollEl.pageYOffset !== undefined ? this.scrollEl.pageYOffset : this.scrollEl.scrollTop;
      this.backTop = this.scrollTop >= this.distance;
    },
    click: function click() {
      this.startTime = +new Date();
      this.isAnimation && this.duration > 0 ? this.scrollAnimation() : this.scroll();
      this.$emit('click');
    },
    scrollAnimation: function scrollAnimation() {
      var self = this;
      var cid = self.requestAniFrame()(function fn() {
        var t = self.duration - Math.max(0, self.startTime - +new Date() + self.duration);
        var y = t * -self.scrollTop / self.duration + self.scrollTop;
        self.scroll(y);
        cid = self.requestAniFrame()(fn);

        if (t == self.duration || y == 0) {
          window.cancelAnimationFrame(cid);
        }
      });
    },
    scroll: function scroll() {
      var y = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;

      if (this.scrollEl === window) {
        window.scrollTo(0, y);
      } else {
        this.scrollEl.scrollTop = y;
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/backtop/backtop.vue?vue&type=script&lang=js&
 /* harmony default export */ var backtop_backtopvue_type_script_lang_js_ = (backtopvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/backtop/backtop.vue





/* normalize component */

var backtop_component = normalizeComponent(
  backtop_backtopvue_type_script_lang_js_,
  backtopvue_type_template_id_5ea5b2b8_render,
  backtopvue_type_template_id_5ea5b2b8_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var backtop = (backtop_component.exports);
// EXTERNAL MODULE: ./src/packages/backtop/backtop.scss
var backtop_backtop = __webpack_require__(56);

// CONCATENATED MODULE: ./src/packages/backtop/index.js



backtop.install = function (Vue) {
  Vue.component(backtop.name, backtop);
};

/* harmony default export */ var packages_backtop = (backtop);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/countdown/countdown.vue?vue&type=template&id=0a9796b4&
var countdownvue_type_template_id_0a9796b4_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('span',{staticClass:"nut-cd-timer"},[(_vm.showPlainText)?[_c('span',{staticClass:"nut-cd-block"},[_vm._v(_vm._s(_vm.plainText))])]:[(_vm.resttime.d >= 0 && _vm.showDays)?[_c('span',{staticClass:"nut-cd-block"},[_vm._v(_vm._s(_vm.resttime.d))]),_vm._v(" "),_c('span',{staticClass:"nut-cd-dot"},[_vm._v("天")])]:_vm._e(),_vm._v(" "),_c('span',{staticClass:"nut-cd-block"},[_vm._v(_vm._s(_vm.resttime.h))]),_c('span',{staticClass:"nut-cd-dot"},[_vm._v(":")]),_c('span',{staticClass:"nut-cd-block"},[_vm._v(_vm._s(_vm.resttime.m))]),_c('span',{staticClass:"nut-cd-dot"},[_vm._v(":")]),_c('span',{staticClass:"nut-cd-block"},[_vm._v(_vm._s(_vm.resttime.s))])]],2)}
var countdownvue_type_template_id_0a9796b4_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/countdown/countdown.vue?vue&type=template&id=0a9796b4&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/countdown/countdown.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
function fill2(v) {
  v += '';

  while (v.length < 2) {
    v = '0' + v;
  }

  return v;
}

function restTime(t) {
  var ts = t;
  var rest = {
    d: '-',
    h: '--',
    m: '--',
    s: '--'
  };

  if (ts === 0) {
    rest = {
      d: '0',
      h: '00',
      m: '00',
      s: '00'
    };
  }

  if (ts) {
    var ds = 24 * 60 * 60 * 1000;
    var hs = 60 * 60 * 1000;
    var ms = 60 * 1000;
    var d = ts >= ds ? parseInt(ts / ds) : 0;
    var h = ts - d * ds >= hs ? parseInt((ts - d * ds) / hs) : 0;
    var m = ts - d * ds - h * hs >= ms ? parseInt((ts - d * ds - h * hs) / ms) : 0;
    var s = Math.round((ts - d * ds - h * hs - m * ms) / 1000);
    if (d >= 0) rest.d = d + '';
    if (h >= 0) rest.h = fill2(h);
    if (m >= 0) rest.m = fill2(m);
    if (s >= 0) rest.s = fill2(s);
  }

  return rest;
}

var countdownTimer = {
  name: 'nut-countdown',
  data: function data() {
    return {
      restTime: 0,
      p: 0,
      _curr: 0
    };
  },
  props: {
    paused: {
      default: false,
      type: Boolean
    },
    showDays: {
      default: false,
      type: Boolean
    },
    showPlainText: {
      default: false,
      type: Boolean
    },
    startTime: {
      // 可以是服务器当前时间
      type: [Number, String],
      validator: function validator(v) {
        var dateStr = new Date(v).toString().toLowerCase();
        return dateStr !== 'invalid date';
      }
    },
    endTime: {
      type: [Number, String],
      validator: function validator(v) {
        var dateStr = new Date(v).toString().toLowerCase();
        return dateStr !== 'invalid date';
      }
    }
  },
  computed: {
    resttime: function resttime() {
      var rest = restTime(this.restTime);
      var d = rest.d,
          h = rest.h,
          m = rest.m,
          s = rest.s;

      if (!this.showDays && d > 0) {
        rest.h = fill2(Number(rest.h) + d * 24);
        rest.d = 0;
      }

      return rest;
    },
    plainText: function plainText() {
      var _this$resttime = this.resttime,
          d = _this$resttime.d,
          h = _this$resttime.h,
          m = _this$resttime.m,
          s = _this$resttime.s;
      return "".concat(d > 0 && this.showDays ? d + '天' + h : h, "\u5C0F\u65F6").concat(m, "\u5206").concat(s, "\u79D2");
    }
  },
  watch: {
    paused: function paused(v, ov) {
      if (!ov) {
        this._curr = this.getTimeStamp();
        this.$emit('on-paused', this.restTime);
      } else {
        this.p += this.getTimeStamp() - this._curr;
        this.$emit('on-restart', this.restTime);
      }
    },
    endTime: function endTime() {
      this.initTimer();
    },
    startTime: function startTime() {
      this.initTimer();
    }
  },
  methods: {
    getTimeStamp: function getTimeStamp(timeStr) {
      if (!timeStr) return Date.now();
      var t = timeStr;
      t = t > 0 ? +t : t.toString().replace(/\-/g, '/');
      return new Date(t).getTime();
    },
    initTimer: function initTimer() {
      var _this = this;

      var delay = 1000;
      var curr = Date.now();
      var start = this.getTimeStamp(this.startTime || curr);
      var end = this.getTimeStamp(this.endTime || curr);
      var diffTime = curr - start;
      this.restTime = end - (start + diffTime);
      this.timer = setInterval(function () {
        if (!_this.paused) {
          var _restTime = end - (Date.now() - _this.p + diffTime);

          _this.restTime = _restTime;

          if (_restTime < delay) {
            _this.restTime = 0;

            _this.$emit('on-end');

            clearInterval(_this.timer);
          }
        } else {// 暂停
        }
      }, delay);
    }
  },
  created: function created() {
    this.initTimer();
  },
  destroyed: function destroyed() {
    this.timer && clearInterval(this.timer);
  }
};
countdownTimer.restTime = restTime; // export fill2 for test


/* harmony default export */ var countdownvue_type_script_lang_js_ = (countdownTimer);
// CONCATENATED MODULE: ./src/packages/countdown/countdown.vue?vue&type=script&lang=js&
 /* harmony default export */ var countdown_countdownvue_type_script_lang_js_ = (countdownvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/countdown/countdown.vue





/* normalize component */

var countdown_component = normalizeComponent(
  countdown_countdownvue_type_script_lang_js_,
  countdownvue_type_template_id_0a9796b4_render,
  countdownvue_type_template_id_0a9796b4_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var countdown = (countdown_component.exports);
// EXTERNAL MODULE: ./src/packages/countdown/countdown.scss
var countdown_countdown = __webpack_require__(57);

// CONCATENATED MODULE: ./src/packages/countdown/index.js



countdown.install = function (Vue) {
  Vue.component(countdown.name, countdown);
};

/* harmony default export */ var packages_countdown = (countdown);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/infiniteloading/infiniteloading.vue?vue&type=template&id=5a73bfbf&
var infiniteloadingvue_type_template_id_5a73bfbf_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"scroller",staticClass:"nut-infiniteloading",on:{"touchstart":function($event){return _vm.touchStartHandle($event)},"touchmove":function($event){return _vm.touchMoveHandle($event)}}},[_vm._t("default"),_vm._v(" "),_c('div',{staticClass:"load-more"},[_c('div',{staticClass:"bottom-tips"},[(_vm.isLoading)?[_c('i',{staticClass:"loading-hint"}),_c('span',{staticClass:"loading-txt"},[_vm._v("加载中...")])]:(!_vm.hasMore)?_c('span',{staticClass:"tips-txt"},[_vm._v(_vm._s(_vm.unloadMoreTxt))]):_vm._e()],2)])],2)}
var infiniteloadingvue_type_template_id_5a73bfbf_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/infiniteloading/infiniteloading.vue?vue&type=template&id=5a73bfbf&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/infiniteloading/infiniteloading.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var infiniteloadingvue_type_script_lang_js_ = ({
  name: 'nut-infiniteloading',
  props: {
    hasMore: {
      type: Boolean,
      default: true
    },
    isLoading: {
      type: Boolean,
      default: false
    },
    threshold: {
      type: Number,
      default: 200
    },
    useWindow: {
      type: Boolean,
      default: true
    },
    useCapture: {
      type: Boolean,
      default: false
    },
    isShowMod: {
      type: Boolean,
      default: false
    },
    unloadMoreTxt: {
      type: String,
      default: '哎呀，这里是底部了啦'
    },
    scrollChange: {
      type: Function
    }
  },
  data: function data() {
    return {
      startX: 0,
      startY: 0,
      diffX: 0,
      diffY: 0,
      beforeScrollTop: 0
    };
  },
  mounted: function mounted() {
    var parentElement = this.getParentElement(this.$el);
    var scrollEl = window;

    if (this.useWindow === false) {
      scrollEl = parentElement;
    }

    this.scrollEl = scrollEl;
    this.scrollListener();
  },
  methods: {
    touchStartHandle: function touchStartHandle(e) {
      try {
        this.startX = Number(e.changedTouches[0].pageX);
        this.startY = Number(e.changedTouches[0].pageY);
      } catch (e) {
        console.log(e.message);
      }
    },
    touchMoveHandle: function touchMoveHandle(e) {
      var endX = Number(e.changedTouches[0].pageX);
      var endY = Number(e.changedTouches[0].pageY);
      this.diffX = endX - this.startX;
      this.diffY = endY - this.startY;
    },
    getParentElement: function getParentElement(el) {
      return el && el.parentNode;
    },
    scrollListener: function scrollListener() {
      this.scrollEl.addEventListener('scroll', this.handleScroll, this.useCapture);
      window.addEventListener('resize', this.handleScroll, this.useCapture);
    },
    requestAniFrame: function requestAniFrame() {
      return window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame || function (callback) {
        window.setTimeout(callback, 1000 / 60);
      };
    },
    handleScroll: function handleScroll() {
      var _this = this;

      this.requestAniFrame()(function () {
        if (!_this.isScrollAtBottom() || !_this.hasMore || _this.isLoading || !_this.isShowMod) {
          return false;
        } else {
          _this.$emit('loadmore');
        }
      });
    },
    calculateTopPosition: function calculateTopPosition(el) {
      if (!el) {
        return 0;
      }

      return el.offsetTop + this.calculateTopPosition(el.offsetParent);
    },
    getWindowScrollTop: function getWindowScrollTop() {
      return window.pageYOffset !== undefined ? window.pageYOffset : (document.documentElement || document.body.parentNode || document.body).scrollTop;
    },
    isScrollAtBottom: function isScrollAtBottom() {
      var offsetDistance;
      var resScrollTop = 0;
      var windowScrollTop = this.getWindowScrollTop();

      if (this.useWindow) {
        offsetDistance = this.calculateTopPosition(this.$refs.scroller) + this.$refs.scroller.offsetHeight - windowScrollTop - window.innerHeight;
      } else {
        var _this$scrollEl = this.scrollEl,
            scrollHeight = _this$scrollEl.scrollHeight,
            clientHeight = _this$scrollEl.clientHeight,
            scrollTop = _this$scrollEl.scrollTop;
        offsetDistance = scrollHeight - clientHeight - scrollTop;
        resScrollTop = scrollTop;
      }

      this.$emit('scrollChange', this.useWindow ? windowScrollTop : resScrollTop); // 保证是往下滑动的

      var beforeScrollTop = this.beforeScrollTop;
      this.beforeScrollTop = windowScrollTop;
      return offsetDistance <= this.threshold && windowScrollTop >= this.beforeScrollTop;
    }
  },
  activated: function activated() {
    if (this.keepAlive) {
      this.keepAlive = false;
      this.scrollListener();
    }
  },
  deactivated: function deactivated() {
    this.keepAlive = true;
    this.scrollEl.removeEventListener('scroll', this.handleScroll, this.useCapture);
    window.removeEventListener('resize', this.handleScroll, this.useCapture);
  },
  destroyed: function destroyed() {
    this.scrollEl.removeEventListener('scroll', this.handleScroll, this.useCapture);
    window.removeEventListener('resize', this.handleScroll, this.useCapture);
  }
});
// CONCATENATED MODULE: ./src/packages/infiniteloading/infiniteloading.vue?vue&type=script&lang=js&
 /* harmony default export */ var infiniteloading_infiniteloadingvue_type_script_lang_js_ = (infiniteloadingvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/infiniteloading/infiniteloading.vue





/* normalize component */

var infiniteloading_component = normalizeComponent(
  infiniteloading_infiniteloadingvue_type_script_lang_js_,
  infiniteloadingvue_type_template_id_5a73bfbf_render,
  infiniteloadingvue_type_template_id_5a73bfbf_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var infiniteloading = (infiniteloading_component.exports);
// EXTERNAL MODULE: ./src/packages/infiniteloading/infiniteloading.scss
var infiniteloading_infiniteloading = __webpack_require__(58);

// CONCATENATED MODULE: ./src/packages/infiniteloading/index.js



infiniteloading.install = function (Vue) {
  Vue.component(infiniteloading.name, infiniteloading);
};

/* harmony default export */ var packages_infiniteloading = (infiniteloading);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/uploader/uploader.vue?vue&type=template&id=0e9431c9&
var uploadervue_type_template_id_0e9431c9_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-uploader"},[_vm._t("default"),_vm._v(" "),_c('input',{staticClass:"uploader",attrs:{"type":"file","name":_vm.name,"multiple":_vm.multiple,"disabled":_vm.disabled,"accept":_vm.acceptType},on:{"change":function($event){return _vm.upload($event)}}})],2)}
var uploadervue_type_template_id_0e9431c9_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/uploader/uploader.vue?vue&type=template&id=0e9431c9&

// EXTERNAL MODULE: ./node_modules/@babel/runtime/regenerator/index.js
var regenerator = __webpack_require__(15);
var regenerator_default = /*#__PURE__*/__webpack_require__.n(regenerator);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/asyncToGenerator.js
var asyncToGenerator = __webpack_require__(85);
var asyncToGenerator_default = /*#__PURE__*/__webpack_require__.n(asyncToGenerator);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/classCallCheck.js
var classCallCheck = __webpack_require__(86);
var classCallCheck_default = /*#__PURE__*/__webpack_require__.n(classCallCheck);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/createClass.js
var createClass = __webpack_require__(87);
var createClass_default = /*#__PURE__*/__webpack_require__.n(createClass);

// CONCATENATED MODULE: ./src/utils/uploader.js




var uploader_IdaUploader = /*#__PURE__*/function () {
  function IdaUploader(settings) {
    classCallCheck_default()(this, IdaUploader);

    this.options = {
      url: '',
      formData: null,
      headers: {},
      //自定义headers
      withCredentials: false,
      //支持发送 cookie 凭证信息
      isPreview: true,
      //是否开启本地预览
      previewData: null,
      maxSize: 0,
      //允许上传的文件最大字节,0为不限制
      acceptType: [],
      //允许上传的文件类型,如'image/jpeg'
      showMsgFn: null,
      onStart: null,
      onProgress: null,
      onPreview: null,
      onSuccess: null,
      onFailure: null,
      xhrStatus: 200,
      //默认上传成功是200
      readyState: 4,
      xmlError: null,
      typeError: null,
      limitError: null
    };

    extends_default()(this.options, settings);

    this[this.options.isPreview ? 'preview' : 'uploader']();
  }

  createClass_default()(IdaUploader, [{
    key: "triggerFunc",
    value: function triggerFunc(func) {
      if (typeof func === 'function') {
        return func.bind(this);
      } else {
        console.warn(func + 'is not a function!');
        return function () {};
      }
    }
  }, {
    key: "showMsg",
    value: function showMsg(msg) {
      if (typeof this.options.showMsgFn == 'function') {
        this.options.showMsgFn(msg);
      } else {
        console.log(msg);
      }
    }
  }, {
    key: "check",
    value: function check(file) {
      if (Array.isArray(file)) {
        for (var key in file) {
          if (this.options.maxSize && file[key].size > this.options.maxSize) {
            this.showMsg(this.options.limitError);
            return false;
          }

          if (this.options.acceptType.length && this.options.acceptType.indexOf(file[key].type) === -1) {
            this.showMsg(this.options.typeError);
            return false;
          }
        }
      } else {
        if (this.options.maxSize && file.size > this.options.maxSize) {
          this.showMsg(this.options.limitError);
          return false;
        }

        if (this.options.acceptType.length && this.options.acceptType.indexOf(file.type) === -1) {
          this.showMsg(this.options.typeError);
          return false;
        }
      }

      return true;
    }
  }, {
    key: "preview",
    value: function preview() {
      var _this = this;

      var file = Array.from(this.options.previewData);
      if (!this.check(file)) return;
      var promArray = [];
      file.map(function (item) {
        var temp = new Promise(function (resolve, reject) {
          var reader = new FileReader();
          reader.readAsDataURL(item);

          reader.onload = function (e) {
            _this.uploader();

            resolve(e);
          };
        });
        promArray.push(temp);
      });
      Promise.all(promArray).then(function (res) {
        console.log(res);
        var out = [];

        if (res) {
          res.map(function (item) {
            out.push(item.target.result);
          });
        }

        _this.triggerFunc.call(_this.options, _this.options.onPreview)(out);
      });
    }
  }, {
    key: "uploader",
    value: function uploader() {
      var _this2 = this;

      var xhr = new XMLHttpRequest();
      var options = this.options;
      var formData = options.formData;

      if (xhr.upload) {
        xhr.upload.addEventListener('progress', function (e) {
          _this2.triggerFunc.call(options, options.onProgress)(formData, e.loaded, e.total);
        }, false);

        xhr.onreadystatechange = function (e) {
          if (xhr.readyState === 4) {
            if (xhr.status === options.xhrState) {
              _this2.triggerFunc.call(options, options.onSuccess)(formData, xhr.responseText);
            } else {
              _this2.triggerFunc.call(options, options.onFailure)(formData, xhr.responseText);
            }
          }
        };

        xhr.withCredentials = options.withCredentials;
        xhr.open('POST', options.url, true); // headers

        for (var key in options.headers) {
          xhr.setRequestHeader(key, options.headers[key]);
        }

        this.triggerFunc.call(options, options.onStart)();
        xhr.send(formData);

        if (options.clearInput) {
          options.$el.value = '';
        }
      } else {
        this.showMsg(this.xmlError);
      }
    }
  }]);

  return IdaUploader;
}();

/* harmony default export */ var uploader = (uploader_IdaUploader);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/uploader/uploader.vue?vue&type=script&lang=js&




//
//
//
//
//
//


/* harmony default export */ var uploadervue_type_script_lang_js_ = ({
  name: 'nut-uploader',
  mixins: [mixins_locale],
  props: {
    name: {
      type: String,
      default: 'file'
    },
    url: {
      type: String,
      default: ''
    },
    multiple: {
      type: Boolean,
      default: false
    },
    disabled: {
      type: Boolean,
      default: false
    },
    isPreview: {
      type: Boolean,
      default: false
    },
    maxSize: {
      type: Number,
      default: 5242880
    },
    acceptType: {
      type: Array,
      default: function _default() {
        return ['image/jpeg', 'image/png', 'image/gif', 'image/bmp'];
      }
    },
    selfData: {
      type: Object,
      default: function _default() {
        return {};
      }
    },
    attach: {
      type: Object,
      default: function _default() {
        return {};
      }
    },
    headers: {
      type: Object,
      default: function _default() {
        return {};
      }
    },
    beforeUpload: {
      type: Function
    },
    xhrState: {
      type: Number,
      default: 200
    },
    clearInput: {
      type: Boolean,
      default: true
    },
    xmlError: {
      type: String,
      default: ''
    },
    typeError: {
      type: String,
      default: '不支持上传该类型文件'
    },
    limitError: {
      type: String,
      default: '对不起，您的浏览器不支持本组件'
    },
    withCredentials: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {};
  },
  methods: {
    createUploaderOpts: function createUploaderOpts() {
      var _this = this;

      return {
        $el: {},
        url: this.url,
        //图片上传地址
        formData: null,
        headers: {},
        //自定义headers
        isPreview: this.isPreview,
        //是否开启本地预览
        previewData: null,
        maxSize: this.maxSize,
        //允许上传的文件最大字节
        acceptType: this.acceptType,
        //允许上传的文件类型
        xhrState: this.xhrState,
        clearInput: this.clearInput,
        withCredentials: this.withCredentials,
        //支持发送 cookie 凭证信息
        xmlError: this.xmlError || this.nutTranslate('lang.uploader.xmlError'),
        typeError: this.typeError || this.nutTranslate('lang.uploader.typeError'),
        limitError: this.limitError || this.nutTranslate('lang.uploader.limitError'),
        onStart: function onStart() {
          _this.$emit('start');
        },
        onProgress: function onProgress(file, loaded, total) {
          _this.$emit('progress', file, loaded, total);
        },
        onPreview: function onPreview(previewFile) {
          _this.$emit('preview', previewFile);
        },
        onSuccess: function onSuccess(file, responseTxt) {
          _this.$emit('success', file, responseTxt);
        },
        onFailure: function onFailure(file, responseTxt) {
          _this.$emit('failure', file, responseTxt);
        }
      };
    },
    uploadData: function uploadData($event) {
      var _this2 = this;

      var selfData = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
      var tar = $event.target;

      if (!this.url) {
        this.$emit('showMsg', '请先配置上传url');
        this.$emit('afterChange', tar, $event);
        return;
      }

      var formData = new FormData();
      var opt = this.createUploaderOpts();
      opt.$el = tar;

      if (this.isPreview) {
        opt.previewData = tar.files;
      }

      var len = this.multiple ? tar.files.length : 1;
      formData.append(tar.name, tar.files[0]);

      for (var _i = 0, _Object$keys = Object.keys(this.attach); _i < _Object$keys.length; _i++) {
        var key = _Object$keys[_i];
        formData.append(key, this.attach[key]);
      }

      var finialyOutData = extends_default()(this.selfData, selfData);

      if (finialyOutData) {
        for (var _key in finialyOutData) {
          formData.append(_key, finialyOutData[_key]);
        }
      }

      opt.formData = formData;
      opt.headers = this.headers || {};

      opt.showMsgFn = function (msg) {
        _this2.$emit('showMsg', msg);
      };

      new uploader(opt);
      this.$emit('afterChange', tar, $event);
    },
    upload: function upload($event) {
      var _this3 = this;

      return asyncToGenerator_default()( /*#__PURE__*/regenerator_default.a.mark(function _callee() {
        var promise, resData;
        return regenerator_default.a.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                if (!(typeof _this3.beforeUpload === 'function')) {
                  _context.next = 8;
                  break;
                }

                promise = new Promise(function (reslove, reject) {
                  reslove(_this3.beforeUpload($event));
                });
                _context.next = 4;
                return promise;

              case 4:
                resData = _context.sent;

                if (typeof_default()(resData) === 'object' && typeof_default()(resData.event) === 'object') {
                  _this3.uploadData(resData.event, resData.data);
                } else {
                  console.warn('resData： 必须包含 event字段且为input $event 的事件对象');
                }

                _context.next = 9;
                break;

              case 8:
                _this3.uploadData($event);

              case 9:
              case "end":
                return _context.stop();
            }
          }
        }, _callee);
      }))();
    }
  }
});
// CONCATENATED MODULE: ./src/packages/uploader/uploader.vue?vue&type=script&lang=js&
 /* harmony default export */ var uploader_uploadervue_type_script_lang_js_ = (uploadervue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/uploader/uploader.vue





/* normalize component */

var uploader_component = normalizeComponent(
  uploader_uploadervue_type_script_lang_js_,
  uploadervue_type_template_id_0e9431c9_render,
  uploadervue_type_template_id_0e9431c9_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var uploader_uploader = (uploader_component.exports);
// EXTERNAL MODULE: ./src/packages/uploader/uploader.scss
var packages_uploader_uploader = __webpack_require__(59);

// CONCATENATED MODULE: ./src/packages/uploader/index.js



uploader_uploader.install = function (Vue) {
  Vue.component(uploader_uploader.name, uploader_uploader);
};

/* harmony default export */ var packages_uploader = (uploader_uploader);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/textinput/textinput.vue?vue&type=template&id=d525ac80&
var textinputvue_type_template_id_d525ac80_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('form',{class:['nut-textinput', { 'nut-textinput-disabled': _vm.disabled }],on:{"submit":function($event){$event.preventDefault();}}},[(_vm.label)?_c('span',{staticClass:"nut-textinput-label"},[_vm._v(_vm._s(_vm.label))]):_vm._e(),_vm._v(" "),_c('input',_vm._g(_vm._b({ref:"nutUiInput",style:({ borderWidth: _vm.hasBorder ? '' : 0, outline: _vm.outline ? '' : 'none', 'padding-right': _vm.clearBtn ? '' : '10px' }),attrs:{"type":_vm.type,"placeholder":_vm.placeholder,"disabled":_vm.disabled},domProps:{"value":_vm.value}},'input',_vm.$attrs,false),_vm.inputListeners)),_vm._v(" "),(_vm.clearBtn)?_c('span',{directives:[{name:"show",rawName:"v-show",value:(_vm.clearBtnShow),expression:"clearBtnShow"}],staticClass:"nut-textinput-clear",on:{"click":_vm.clear}},[(!_vm.clearBtnPersonnal)?_c('svg',{attrs:{"version":"1","xmlns":"http://www.w3.org/2000/svg","viewBox":"0 0 16 16"}},[_c('path',{attrs:{"d":"M8 0C3.6 0 0 3.6 0 8s3.6 8 8 8 8-3.6 8-8-3.6-8-8-8zm2.8 9.7c.3.3.3.8 0 1.1s-.8.3-1.1 0L8 9.1l-1.7 1.7c-.3.3-.8.3-1.1 0-.3-.3-.3-.8 0-1.1L6.9 8 5.2 6.3c-.3-.3-.3-.8 0-1.1.3-.3.8-.3 1.1 0L8 6.9l1.7-1.7c.3-.3.8-.3 1.1 0 .3.3.3.8 0 1.1L9.1 8l1.7 1.7z"}})]):_vm._t("clearBtn")],2):_vm._e()])}
var textinputvue_type_template_id_d525ac80_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/textinput/textinput.vue?vue&type=template&id=d525ac80&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/textinput/textinput.vue?vue&type=script&lang=js&



var _name$props$computed$;

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var textinputvue_type_script_lang_js_ = (_name$props$computed$ = {
  name: 'nut-textinput',
  props: {
    value: {
      type: [String, Number],
      default: ''
    },
    type: {
      type: String,
      default: 'text'
    },
    label: {
      type: String,
      default: ''
    },
    placeholder: {
      type: String,
      default: ''
    },
    disabled: {
      type: Boolean,
      default: false
    },
    hasBorder: {
      type: Boolean,
      default: true
    },
    outline: {
      type: Boolean,
      default: false
    },
    clearBtn: {
      type: Boolean,
      default: true
    },
    clearBtnPersonnal: {
      type: Boolean,
      default: false
    }
  },
  computed: {},
  data: function data() {
    return {
      clearBtnShow: false
    };
  }
}, defineProperty_default()(_name$props$computed$, "computed", {
  inputListeners: function inputListeners() {
    var vm = this;
    return extends_default()({}, this.$listeners, {
      input: function input(event) {
        vm.clearBtnShow = !!event.target.value;
        vm.$emit('input', event.target.value);
      }
    });
  }
}), defineProperty_default()(_name$props$computed$, "methods", {
  clear: function clear() {
    this.$emit('input', '');
    this.clearBtnShow = false;
  },
  focus: function focus() {
    this.$nextTick(function () {
      this.$refs.nutUiInput.focus();
    });
  },
  blur: function blur() {
    this.$refs.nutUiInput.blur();
  }
}), defineProperty_default()(_name$props$computed$, "mounted", function mounted() {
  this.clearBtnShow = !!this.value;
}), _name$props$computed$);
// CONCATENATED MODULE: ./src/packages/textinput/textinput.vue?vue&type=script&lang=js&
 /* harmony default export */ var textinput_textinputvue_type_script_lang_js_ = (textinputvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/textinput/textinput.vue





/* normalize component */

var textinput_component = normalizeComponent(
  textinput_textinputvue_type_script_lang_js_,
  textinputvue_type_template_id_d525ac80_render,
  textinputvue_type_template_id_d525ac80_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var textinput = (textinput_component.exports);
// EXTERNAL MODULE: ./src/packages/textinput/textinput.scss
var textinput_textinput = __webpack_require__(60);

// CONCATENATED MODULE: ./src/packages/textinput/index.js



textinput.install = function (Vue) {
  Vue.component(textinput.name, textinput);
};

/* harmony default export */ var packages_textinput = (textinput);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/avatar/avatar.vue?vue&type=template&id=26710d56&
var avatarvue_type_template_id_26710d56_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-avatar', 'avatar-' + _vm.size, 'avatar-' + _vm.shape],style:(_vm.styles),on:{"click":_vm.activeAvatar}},[_c('i',{staticClass:"icon",style:(_vm.iconStyles)}),_vm._v(" "),(_vm.isShowText)?_c('span',{staticClass:"text"},[_vm._t("default")],2):_vm._e()])}
var avatarvue_type_template_id_26710d56_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/avatar/avatar.vue?vue&type=template&id=26710d56&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/avatar/avatar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
/* harmony default export */ var avatarvue_type_script_lang_js_ = ({
  name: 'nut-avatar',
  props: {
    size: {
      type: String,
      default: 'normal'
    },
    shape: {
      type: String,
      default: 'round'
    },
    bgColor: {
      type: String,
      default: '#eee'
    },
    bgIcon: {
      type: String,
      default: 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACQAAAAgCAMAAABNTyq8AAAASFBMVEUAAAAXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEcXIEdRCe4GAAAAF3RSTlMACSW88uTcQKeYWB7YOTB/xXdlkHFLzVTLks0AAAD+SURBVDjLjZILjoMwDAXzD5Q/LZ3733STbpYskoM6EkhBw7MdWV2JfYDQR9XGWArWtJzoOHGxkZOd56T11GdLzlrBz+rD7GEViwHJKRYgFexTrXp6Qi9IAaZ6miAIEqDrSQOC5L6Rxtp3YpbLdbDU0wKdID3A67Oah4cgpe916r78IUSdBRdKkNgV66H1sSJ3NGzW8x832s1clQ6RbqjO4Wjgzs5eJOxu9GVYs1sSrzrVGMXtGf+mHBxYrUS0BTf8Dj4mp2GNn8sYqHskMAGD2sCqGyxs+bXfSXsO8WDuJAO+bK1IXdH83FKkYHJsoIl6l6tf2s5bxVCSfMsJ8QdwfR4F9ZQcyQAAAABJRU5ErkJggg=='
    },
    bgImage: {
      type: String,
      default: ''
    }
  },
  computed: {
    styles: function styles() {
      return {
        backgroundImage: this.bgImage ? "url(".concat(this.bgImage, ")") : null,
        backgroundColor: "".concat(this.bgColor)
      };
    },
    iconStyles: function iconStyles() {
      return this.bgIcon ? {
        backgroundImage: "url(".concat(this.bgIcon, ")")
      } : null;
    },
    isShowText: function isShowText() {
      return this.$slots.default;
    }
  },
  data: function data() {
    return {};
  },
  methods: {
    activeAvatar: function activeAvatar() {
      this.$emit('active-avatar', event);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/avatar/avatar.vue?vue&type=script&lang=js&
 /* harmony default export */ var avatar_avatarvue_type_script_lang_js_ = (avatarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/avatar/avatar.vue





/* normalize component */

var avatar_component = normalizeComponent(
  avatar_avatarvue_type_script_lang_js_,
  avatarvue_type_template_id_26710d56_render,
  avatarvue_type_template_id_26710d56_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var avatar = (avatar_component.exports);
// EXTERNAL MODULE: ./src/packages/avatar/avatar.scss
var avatar_avatar = __webpack_require__(61);

// CONCATENATED MODULE: ./src/packages/avatar/index.js



avatar.install = function (Vue) {
  Vue.component(avatar.name, avatar);
};

/* harmony default export */ var packages_avatar = (avatar);
// CONCATENATED MODULE: ./node_modules/vue-lazyload/vue-lazyload.esm.js
/*!
 * Vue-Lazyload.js v1.3.3
 * (c) 2019 Awe <hilongjw@gmail.com>
 * Released under the MIT License.
 */
var _typeof = typeof Symbol === "function" && typeof Symbol.iterator === "symbol" ? function (obj) {
  return typeof obj;
} : function (obj) {
  return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
};











var vue_lazyload_esm_classCallCheck = function (instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
};

var vue_lazyload_esm_createClass = function () {
  function defineProperties(target, props) {
    for (var i = 0; i < props.length; i++) {
      var descriptor = props[i];
      descriptor.enumerable = descriptor.enumerable || false;
      descriptor.configurable = true;
      if ("value" in descriptor) descriptor.writable = true;
      Object.defineProperty(target, descriptor.key, descriptor);
    }
  }

  return function (Constructor, protoProps, staticProps) {
    if (protoProps) defineProperties(Constructor.prototype, protoProps);
    if (staticProps) defineProperties(Constructor, staticProps);
    return Constructor;
  };
}();

/*!
 * is-primitive <https://github.com/jonschlinkert/is-primitive>
 *
 * Copyright (c) 2014-2015, Jon Schlinkert.
 * Licensed under the MIT License.
 */

// see http://jsperf.com/testing-value-is-primitive/7

var isPrimitive = function isPrimitive(value) {
  return value == null || typeof value !== 'function' && (typeof value === 'undefined' ? 'undefined' : _typeof(value)) !== 'object';
};

/*!
 * assign-symbols <https://github.com/jonschlinkert/assign-symbols>
 *
 * Copyright (c) 2015, Jon Schlinkert.
 * Licensed under the MIT License.
 */

var assignSymbols = function assignSymbols(receiver, objects) {
  if (receiver === null || typeof receiver === 'undefined') {
    throw new TypeError('expected first argument to be an object.');
  }

  if (typeof objects === 'undefined' || typeof Symbol === 'undefined') {
    return receiver;
  }

  if (typeof Object.getOwnPropertySymbols !== 'function') {
    return receiver;
  }

  var isEnumerable = Object.prototype.propertyIsEnumerable;
  var target = Object(receiver);
  var len = arguments.length,
      i = 0;

  while (++i < len) {
    var provider = Object(arguments[i]);
    var names = Object.getOwnPropertySymbols(provider);

    for (var j = 0; j < names.length; j++) {
      var key = names[j];

      if (isEnumerable.call(provider, key)) {
        target[key] = provider[key];
      }
    }
  }
  return target;
};

var vue_lazyload_esm_toString = Object.prototype.toString;

/**
 * Get the native `typeof` a value.
 *
 * @param  {*} `val`
 * @return {*} Native javascript type
 */

var kindOf = function kindOf(val) {
  var type = typeof val === 'undefined' ? 'undefined' : _typeof(val);

  // primitivies
  if (type === 'undefined') {
    return 'undefined';
  }
  if (val === null) {
    return 'null';
  }
  if (val === true || val === false || val instanceof Boolean) {
    return 'boolean';
  }
  if (type === 'string' || val instanceof String) {
    return 'string';
  }
  if (type === 'number' || val instanceof Number) {
    return 'number';
  }

  // functions
  if (type === 'function' || val instanceof Function) {
    if (typeof val.constructor.name !== 'undefined' && val.constructor.name.slice(0, 9) === 'Generator') {
      return 'generatorfunction';
    }
    return 'function';
  }

  // array
  if (typeof Array.isArray !== 'undefined' && Array.isArray(val)) {
    return 'array';
  }

  // check for instances of RegExp and Date before calling `toString`
  if (val instanceof RegExp) {
    return 'regexp';
  }
  if (val instanceof Date) {
    return 'date';
  }

  // other objects
  type = vue_lazyload_esm_toString.call(val);

  if (type === '[object RegExp]') {
    return 'regexp';
  }
  if (type === '[object Date]') {
    return 'date';
  }
  if (type === '[object Arguments]') {
    return 'arguments';
  }
  if (type === '[object Error]') {
    return 'error';
  }
  if (type === '[object Promise]') {
    return 'promise';
  }

  // buffer
  if (isBuffer(val)) {
    return 'buffer';
  }

  // es6: Map, WeakMap, Set, WeakSet
  if (type === '[object Set]') {
    return 'set';
  }
  if (type === '[object WeakSet]') {
    return 'weakset';
  }
  if (type === '[object Map]') {
    return 'map';
  }
  if (type === '[object WeakMap]') {
    return 'weakmap';
  }
  if (type === '[object Symbol]') {
    return 'symbol';
  }

  if (type === '[object Map Iterator]') {
    return 'mapiterator';
  }
  if (type === '[object Set Iterator]') {
    return 'setiterator';
  }
  if (type === '[object String Iterator]') {
    return 'stringiterator';
  }
  if (type === '[object Array Iterator]') {
    return 'arrayiterator';
  }

  // typed arrays
  if (type === '[object Int8Array]') {
    return 'int8array';
  }
  if (type === '[object Uint8Array]') {
    return 'uint8array';
  }
  if (type === '[object Uint8ClampedArray]') {
    return 'uint8clampedarray';
  }
  if (type === '[object Int16Array]') {
    return 'int16array';
  }
  if (type === '[object Uint16Array]') {
    return 'uint16array';
  }
  if (type === '[object Int32Array]') {
    return 'int32array';
  }
  if (type === '[object Uint32Array]') {
    return 'uint32array';
  }
  if (type === '[object Float32Array]') {
    return 'float32array';
  }
  if (type === '[object Float64Array]') {
    return 'float64array';
  }

  // must be a plain object
  return 'object';
};

/**
 * If you need to support Safari 5-7 (8-10 yr-old browser),
 * take a look at https://github.com/feross/is-buffer
 */

function isBuffer(val) {
  return val.constructor && typeof val.constructor.isBuffer === 'function' && val.constructor.isBuffer(val);
}

function vue_lazyload_esm_assign(target /*, objects*/) {
  target = target || {};
  var len = arguments.length,
      i = 0;
  if (len === 1) {
    return target;
  }
  while (++i < len) {
    var val = arguments[i];
    if (isPrimitive(target)) {
      target = val;
    }
    if (isObject$1(val)) {
      extend(target, val);
    }
  }
  return target;
}

/**
 * Shallow extend
 */

function extend(target, obj) {
  assignSymbols(target, obj);

  for (var key in obj) {
    if (key !== '__proto__' && hasOwn(obj, key)) {
      var val = obj[key];
      if (isObject$1(val)) {
        if (kindOf(target[key]) === 'undefined' && kindOf(val) === 'function') {
          target[key] = val;
        }
        target[key] = vue_lazyload_esm_assign(target[key] || {}, val);
      } else {
        target[key] = val;
      }
    }
  }
  return target;
}

/**
 * Returns true if the object is a plain object or a function.
 */

function isObject$1(obj) {
  return kindOf(obj) === 'object' || kindOf(obj) === 'function';
}

/**
 * Returns true if the given `key` is an own property of `obj`.
 */

function hasOwn(obj, key) {
  return Object.prototype.hasOwnProperty.call(obj, key);
}

/**
 * Expose `assign`
 */

var assignDeep = vue_lazyload_esm_assign;

var inBrowser = typeof window !== 'undefined';
var hasIntersectionObserver = checkIntersectionObserver();

function checkIntersectionObserver() {
  if (inBrowser && 'IntersectionObserver' in window && 'IntersectionObserverEntry' in window && 'intersectionRatio' in window.IntersectionObserverEntry.prototype) {
    // Minimal polyfill for Edge 15's lack of `isIntersecting`
    // See: https://github.com/w3c/IntersectionObserver/issues/211
    if (!('isIntersecting' in window.IntersectionObserverEntry.prototype)) {
      Object.defineProperty(window.IntersectionObserverEntry.prototype, 'isIntersecting', {
        get: function get$$1() {
          return this.intersectionRatio > 0;
        }
      });
    }
    return true;
  }
  return false;
}

var modeType = {
  event: 'event',
  observer: 'observer'

  // CustomEvent polyfill
};var CustomEvent = function () {
  if (!inBrowser) return;
  if (typeof window.CustomEvent === 'function') return window.CustomEvent;
  function CustomEvent(event, params) {
    params = params || { bubbles: false, cancelable: false, detail: undefined };
    var evt = document.createEvent('CustomEvent');
    evt.initCustomEvent(event, params.bubbles, params.cancelable, params.detail);
    return evt;
  }
  CustomEvent.prototype = window.Event.prototype;
  return CustomEvent;
}();

function remove(arr, item) {
  if (!arr.length) return;
  var index = arr.indexOf(item);
  if (index > -1) return arr.splice(index, 1);
}

function some(arr, fn) {
  var has = false;
  for (var i = 0, len = arr.length; i < len; i++) {
    if (fn(arr[i])) {
      has = true;
      break;
    }
  }
  return has;
}

function getBestSelectionFromSrcset(el, scale) {
  if (el.tagName !== 'IMG' || !el.getAttribute('data-srcset')) return;

  var options = el.getAttribute('data-srcset');
  var result = [];
  var container = el.parentNode;
  var containerWidth = container.offsetWidth * scale;

  var spaceIndex = void 0;
  var tmpSrc = void 0;
  var tmpWidth = void 0;

  options = options.trim().split(',');

  options.map(function (item) {
    item = item.trim();
    spaceIndex = item.lastIndexOf(' ');
    if (spaceIndex === -1) {
      tmpSrc = item;
      tmpWidth = 999998;
    } else {
      tmpSrc = item.substr(0, spaceIndex);
      tmpWidth = parseInt(item.substr(spaceIndex + 1, item.length - spaceIndex - 2), 10);
    }
    result.push([tmpWidth, tmpSrc]);
  });

  result.sort(function (a, b) {
    if (a[0] < b[0]) {
      return 1;
    }
    if (a[0] > b[0]) {
      return -1;
    }
    if (a[0] === b[0]) {
      if (b[1].indexOf('.webp', b[1].length - 5) !== -1) {
        return 1;
      }
      if (a[1].indexOf('.webp', a[1].length - 5) !== -1) {
        return -1;
      }
    }
    return 0;
  });
  var bestSelectedSrc = '';
  var tmpOption = void 0;

  for (var i = 0; i < result.length; i++) {
    tmpOption = result[i];
    bestSelectedSrc = tmpOption[1];
    var next = result[i + 1];
    if (next && next[0] < containerWidth) {
      bestSelectedSrc = tmpOption[1];
      break;
    } else if (!next) {
      bestSelectedSrc = tmpOption[1];
      break;
    }
  }

  return bestSelectedSrc;
}

function find(arr, fn) {
  var item = void 0;
  for (var i = 0, len = arr.length; i < len; i++) {
    if (fn(arr[i])) {
      item = arr[i];
      break;
    }
  }
  return item;
}

var getDPR = function getDPR() {
  var scale = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 1;
  return inBrowser ? window.devicePixelRatio || scale : scale;
};

function supportWebp() {
  if (!inBrowser) return false;

  var support = true;
  var d = document;

  try {
    var el = d.createElement('object');
    el.type = 'image/webp';
    el.style.visibility = 'hidden';
    el.innerHTML = '!';
    d.body.appendChild(el);
    support = !el.offsetWidth;
    d.body.removeChild(el);
  } catch (err) {
    support = false;
  }

  return support;
}

function throttle(action, delay) {
  var timeout = null;
  var lastRun = 0;
  return function () {
    if (timeout) {
      return;
    }
    var elapsed = Date.now() - lastRun;
    var context = this;
    var args = arguments;
    var runCallback = function runCallback() {
      lastRun = Date.now();
      timeout = false;
      action.apply(context, args);
    };
    if (elapsed >= delay) {
      runCallback();
    } else {
      timeout = setTimeout(runCallback, delay);
    }
  };
}

function testSupportsPassive() {
  if (!inBrowser) return;
  var support = false;
  try {
    var opts = Object.defineProperty({}, 'passive', {
      get: function get$$1() {
        support = true;
      }
    });
    window.addEventListener('test', null, opts);
  } catch (e) {}
  return support;
}

var supportsPassive = testSupportsPassive();

var _ = {
  on: function on(el, type, func) {
    var capture = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : false;

    if (supportsPassive) {
      el.addEventListener(type, func, {
        capture: capture,
        passive: true
      });
    } else {
      el.addEventListener(type, func, capture);
    }
  },
  off: function off(el, type, func) {
    var capture = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : false;

    el.removeEventListener(type, func, capture);
  }
};

var loadImageAsync = function loadImageAsync(item, resolve, reject) {
  var image = new Image();
  if (!item || !item.src) {
    var err = new Error('image src is required');
    return reject(err);
  }

  image.src = item.src;

  image.onload = function () {
    resolve({
      naturalHeight: image.naturalHeight,
      naturalWidth: image.naturalWidth,
      src: image.src
    });
  };

  image.onerror = function (e) {
    reject(e);
  };
};

var vue_lazyload_esm_style = function style(el, prop) {
  return typeof getComputedStyle !== 'undefined' ? getComputedStyle(el, null).getPropertyValue(prop) : el.style[prop];
};

var overflow = function overflow(el) {
  return vue_lazyload_esm_style(el, 'overflow') + vue_lazyload_esm_style(el, 'overflow-y') + vue_lazyload_esm_style(el, 'overflow-x');
};

var scrollParent = function scrollParent(el) {
  if (!inBrowser) return;
  if (!(el instanceof HTMLElement)) {
    return window;
  }

  var parent = el;

  while (parent) {
    if (parent === document.body || parent === document.documentElement) {
      break;
    }

    if (!parent.parentNode) {
      break;
    }

    if (/(scroll|auto)/.test(overflow(parent))) {
      return parent;
    }

    parent = parent.parentNode;
  }

  return window;
};

function vue_lazyload_esm_isObject(obj) {
  return obj !== null && (typeof obj === 'undefined' ? 'undefined' : _typeof(obj)) === 'object';
}

function ObjectKeys(obj) {
  if (!(obj instanceof Object)) return [];
  if (Object.keys) {
    return Object.keys(obj);
  } else {
    var keys = [];
    for (var key in obj) {
      if (obj.hasOwnProperty(key)) {
        keys.push(key);
      }
    }
    return keys;
  }
}

function ArrayFrom(arrLike) {
  var len = arrLike.length;
  var list = [];
  for (var i = 0; i < len; i++) {
    list.push(arrLike[i]);
  }
  return list;
}

function noop() {}

var ImageCache = function () {
  function ImageCache(_ref) {
    var max = _ref.max;
    vue_lazyload_esm_classCallCheck(this, ImageCache);

    this.options = {
      max: max || 100
    };
    this._caches = [];
  }

  vue_lazyload_esm_createClass(ImageCache, [{
    key: 'has',
    value: function has(key) {
      return this._caches.indexOf(key) > -1;
    }
  }, {
    key: 'add',
    value: function add(key) {
      if (this.has(key)) return;
      this._caches.push(key);
      if (this._caches.length > this.options.max) {
        this.free();
      }
    }
  }, {
    key: 'free',
    value: function free() {
      this._caches.shift();
    }
  }]);
  return ImageCache;
}();

// el: {
//     state,
//     src,
//     error,
//     loading
// }

var ReactiveListener = function () {
  function ReactiveListener(_ref) {
    var el = _ref.el,
        src = _ref.src,
        error = _ref.error,
        loading = _ref.loading,
        bindType = _ref.bindType,
        $parent = _ref.$parent,
        options = _ref.options,
        elRenderer = _ref.elRenderer,
        imageCache = _ref.imageCache;
    vue_lazyload_esm_classCallCheck(this, ReactiveListener);

    this.el = el;
    this.src = src;
    this.error = error;
    this.loading = loading;
    this.bindType = bindType;
    this.attempt = 0;

    this.naturalHeight = 0;
    this.naturalWidth = 0;

    this.options = options;

    this.rect = null;

    this.$parent = $parent;
    this.elRenderer = elRenderer;
    this._imageCache = imageCache;
    this.performanceData = {
      init: Date.now(),
      loadStart: 0,
      loadEnd: 0
    };

    this.filter();
    this.initState();
    this.render('loading', false);
  }

  /*
   * init listener state
   * @return
   */


  vue_lazyload_esm_createClass(ReactiveListener, [{
    key: 'initState',
    value: function initState() {
      if ('dataset' in this.el) {
        this.el.dataset.src = this.src;
      } else {
        this.el.setAttribute('data-src', this.src);
      }

      this.state = {
        loading: false,
        error: false,
        loaded: false,
        rendered: false
      };
    }

    /*
     * record performance
     * @return
     */

  }, {
    key: 'record',
    value: function record(event) {
      this.performanceData[event] = Date.now();
    }

    /*
     * update image listener data
     * @param  {String} image uri
     * @param  {String} loading image uri
     * @param  {String} error image uri
     * @return
     */

  }, {
    key: 'update',
    value: function update(_ref2) {
      var src = _ref2.src,
          loading = _ref2.loading,
          error = _ref2.error;

      var oldSrc = this.src;
      this.src = src;
      this.loading = loading;
      this.error = error;
      this.filter();
      if (oldSrc !== this.src) {
        this.attempt = 0;
        this.initState();
      }
    }

    /*
     * get el node rect
     * @return
     */

  }, {
    key: 'getRect',
    value: function getRect() {
      this.rect = this.el.getBoundingClientRect();
    }

    /*
     *  check el is in view
     * @return {Boolean} el is in view
     */

  }, {
    key: 'checkInView',
    value: function checkInView() {
      this.getRect();
      return this.rect.top < window.innerHeight * this.options.preLoad && this.rect.bottom > this.options.preLoadTop && this.rect.left < window.innerWidth * this.options.preLoad && this.rect.right > 0;
    }

    /*
     * listener filter
     */

  }, {
    key: 'filter',
    value: function filter() {
      var _this = this;

      ObjectKeys(this.options.filter).map(function (key) {
        _this.options.filter[key](_this, _this.options);
      });
    }

    /*
     * render loading first
     * @params cb:Function
     * @return
     */

  }, {
    key: 'renderLoading',
    value: function renderLoading(cb) {
      var _this2 = this;

      this.state.loading = true;
      loadImageAsync({
        src: this.loading
      }, function (data) {
        _this2.render('loading', false);
        _this2.state.loading = false;
        cb();
      }, function () {
        // handler `loading image` load failed
        cb();
        _this2.state.loading = false;
        if (!_this2.options.silent) console.warn('VueLazyload log: load failed with loading image(' + _this2.loading + ')');
      });
    }

    /*
     * try load image and  render it
     * @return
     */

  }, {
    key: 'load',
    value: function load() {
      var _this3 = this;

      var onFinish = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : noop;

      if (this.attempt > this.options.attempt - 1 && this.state.error) {
        if (!this.options.silent) console.log('VueLazyload log: ' + this.src + ' tried too more than ' + this.options.attempt + ' times');
        onFinish();
        return;
      }
      if (this.state.rendered && this.state.loaded) return;
      if (this._imageCache.has(this.src)) {
        this.state.loaded = true;
        this.render('loaded', true);
        this.state.rendered = true;
        return onFinish();
      }

      this.renderLoading(function () {
        _this3.attempt++;

        _this3.options.adapter['beforeLoad'] && _this3.options.adapter['beforeLoad'](_this3, _this3.options);
        _this3.record('loadStart');

        loadImageAsync({
          src: _this3.src
        }, function (data) {
          _this3.naturalHeight = data.naturalHeight;
          _this3.naturalWidth = data.naturalWidth;
          _this3.state.loaded = true;
          _this3.state.error = false;
          _this3.record('loadEnd');
          _this3.render('loaded', false);
          _this3.state.rendered = true;
          _this3._imageCache.add(_this3.src);
          onFinish();
        }, function (err) {
          !_this3.options.silent && console.error(err);
          _this3.state.error = true;
          _this3.state.loaded = false;
          _this3.render('error', false);
        });
      });
    }

    /*
     * render image
     * @param  {String} state to render // ['loading', 'src', 'error']
     * @param  {String} is form cache
     * @return
     */

  }, {
    key: 'render',
    value: function render(state, cache) {
      this.elRenderer(this, state, cache);
    }

    /*
     * output performance data
     * @return {Object} performance data
     */

  }, {
    key: 'performance',
    value: function performance() {
      var state = 'loading';
      var time = 0;

      if (this.state.loaded) {
        state = 'loaded';
        time = (this.performanceData.loadEnd - this.performanceData.loadStart) / 1000;
      }

      if (this.state.error) state = 'error';

      return {
        src: this.src,
        state: state,
        time: time
      };
    }

    /*
     * $destroy
     * @return
     */

  }, {
    key: '$destroy',
    value: function $destroy() {
      this.el = null;
      this.src = null;
      this.error = null;
      this.loading = null;
      this.bindType = null;
      this.attempt = 0;
    }
  }]);
  return ReactiveListener;
}();

var DEFAULT_URL = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7';
var DEFAULT_EVENTS = ['scroll', 'wheel', 'mousewheel', 'resize', 'animationend', 'transitionend', 'touchmove'];
var DEFAULT_OBSERVER_OPTIONS = {
  rootMargin: '0px',
  threshold: 0
};

var Lazy = function (Vue) {
  return function () {
    function Lazy(_ref) {
      var preLoad = _ref.preLoad,
          error = _ref.error,
          throttleWait = _ref.throttleWait,
          preLoadTop = _ref.preLoadTop,
          dispatchEvent = _ref.dispatchEvent,
          loading = _ref.loading,
          attempt = _ref.attempt,
          _ref$silent = _ref.silent,
          silent = _ref$silent === undefined ? true : _ref$silent,
          scale = _ref.scale,
          listenEvents = _ref.listenEvents,
          hasbind = _ref.hasbind,
          filter = _ref.filter,
          adapter = _ref.adapter,
          observer = _ref.observer,
          observerOptions = _ref.observerOptions;
      vue_lazyload_esm_classCallCheck(this, Lazy);

      this.version = '1.3.3';
      this.mode = modeType.event;
      this.ListenerQueue = [];
      this.TargetIndex = 0;
      this.TargetQueue = [];
      this.options = {
        silent: silent,
        dispatchEvent: !!dispatchEvent,
        throttleWait: throttleWait || 200,
        preLoad: preLoad || 1.3,
        preLoadTop: preLoadTop || 0,
        error: error || DEFAULT_URL,
        loading: loading || DEFAULT_URL,
        attempt: attempt || 3,
        scale: scale || getDPR(scale),
        ListenEvents: listenEvents || DEFAULT_EVENTS,
        hasbind: false,
        supportWebp: supportWebp(),
        filter: filter || {},
        adapter: adapter || {},
        observer: !!observer,
        observerOptions: observerOptions || DEFAULT_OBSERVER_OPTIONS
      };
      this._initEvent();
      this._imageCache = new ImageCache({ max: 200 });
      this.lazyLoadHandler = throttle(this._lazyLoadHandler.bind(this), this.options.throttleWait);

      this.setMode(this.options.observer ? modeType.observer : modeType.event);
    }

    /**
     * update config
     * @param  {Object} config params
     * @return
     */


    vue_lazyload_esm_createClass(Lazy, [{
      key: 'config',
      value: function config() {
        var options = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : {};

        assignDeep(this.options, options);
      }

      /**
       * output listener's load performance
       * @return {Array}
       */

    }, {
      key: 'performance',
      value: function performance() {
        var list = [];

        this.ListenerQueue.map(function (item) {
          list.push(item.performance());
        });

        return list;
      }

      /*
       * add lazy component to queue
       * @param  {Vue} vm lazy component instance
       * @return
       */

    }, {
      key: 'addLazyBox',
      value: function addLazyBox(vm) {
        this.ListenerQueue.push(vm);
        if (inBrowser) {
          this._addListenerTarget(window);
          this._observer && this._observer.observe(vm.el);
          if (vm.$el && vm.$el.parentNode) {
            this._addListenerTarget(vm.$el.parentNode);
          }
        }
      }

      /*
       * add image listener to queue
       * @param  {DOM} el
       * @param  {object} binding vue directive binding
       * @param  {vnode} vnode vue directive vnode
       * @return
       */

    }, {
      key: 'add',
      value: function add(el, binding, vnode) {
        var _this = this;

        if (some(this.ListenerQueue, function (item) {
          return item.el === el;
        })) {
          this.update(el, binding);
          return Vue.nextTick(this.lazyLoadHandler);
        }

        var _valueFormatter2 = this._valueFormatter(binding.value),
            src = _valueFormatter2.src,
            loading = _valueFormatter2.loading,
            error = _valueFormatter2.error;

        Vue.nextTick(function () {
          src = getBestSelectionFromSrcset(el, _this.options.scale) || src;
          _this._observer && _this._observer.observe(el);

          var container = Object.keys(binding.modifiers)[0];
          var $parent = void 0;

          if (container) {
            $parent = vnode.context.$refs[container];
            // if there is container passed in, try ref first, then fallback to getElementById to support the original usage
            $parent = $parent ? $parent.$el || $parent : document.getElementById(container);
          }

          if (!$parent) {
            $parent = scrollParent(el);
          }

          var newListener = new ReactiveListener({
            bindType: binding.arg,
            $parent: $parent,
            el: el,
            loading: loading,
            error: error,
            src: src,
            elRenderer: _this._elRenderer.bind(_this),
            options: _this.options,
            imageCache: _this._imageCache
          });

          _this.ListenerQueue.push(newListener);

          if (inBrowser) {
            _this._addListenerTarget(window);
            _this._addListenerTarget($parent);
          }

          _this.lazyLoadHandler();
          Vue.nextTick(function () {
            return _this.lazyLoadHandler();
          });
        });
      }

      /**
      * update image src
      * @param  {DOM} el
      * @param  {object} vue directive binding
      * @return
      */

    }, {
      key: 'update',
      value: function update(el, binding, vnode) {
        var _this2 = this;

        var _valueFormatter3 = this._valueFormatter(binding.value),
            src = _valueFormatter3.src,
            loading = _valueFormatter3.loading,
            error = _valueFormatter3.error;

        src = getBestSelectionFromSrcset(el, this.options.scale) || src;

        var exist = find(this.ListenerQueue, function (item) {
          return item.el === el;
        });
        if (!exist) {
          this.add(el, binding, vnode);
        } else {
          exist.update({
            src: src,
            loading: loading,
            error: error
          });
        }
        if (this._observer) {
          this._observer.unobserve(el);
          this._observer.observe(el);
        }
        this.lazyLoadHandler();
        Vue.nextTick(function () {
          return _this2.lazyLoadHandler();
        });
      }

      /**
      * remove listener form list
      * @param  {DOM} el
      * @return
      */

    }, {
      key: 'remove',
      value: function remove$$1(el) {
        if (!el) return;
        this._observer && this._observer.unobserve(el);
        var existItem = find(this.ListenerQueue, function (item) {
          return item.el === el;
        });
        if (existItem) {
          this._removeListenerTarget(existItem.$parent);
          this._removeListenerTarget(window);
          remove(this.ListenerQueue, existItem);
          existItem.$destroy();
        }
      }

      /*
       * remove lazy components form list
       * @param  {Vue} vm Vue instance
       * @return
       */

    }, {
      key: 'removeComponent',
      value: function removeComponent(vm) {
        if (!vm) return;
        remove(this.ListenerQueue, vm);
        this._observer && this._observer.unobserve(vm.el);
        if (vm.$parent && vm.$el.parentNode) {
          this._removeListenerTarget(vm.$el.parentNode);
        }
        this._removeListenerTarget(window);
      }
    }, {
      key: 'setMode',
      value: function setMode(mode) {
        var _this3 = this;

        if (!hasIntersectionObserver && mode === modeType.observer) {
          mode = modeType.event;
        }

        this.mode = mode; // event or observer

        if (mode === modeType.event) {
          if (this._observer) {
            this.ListenerQueue.forEach(function (listener) {
              _this3._observer.unobserve(listener.el);
            });
            this._observer = null;
          }

          this.TargetQueue.forEach(function (target) {
            _this3._initListen(target.el, true);
          });
        } else {
          this.TargetQueue.forEach(function (target) {
            _this3._initListen(target.el, false);
          });
          this._initIntersectionObserver();
        }
      }

      /*
      *** Private functions ***
      */

      /*
       * add listener target
       * @param  {DOM} el listener target
       * @return
       */

    }, {
      key: '_addListenerTarget',
      value: function _addListenerTarget(el) {
        if (!el) return;
        var target = find(this.TargetQueue, function (target) {
          return target.el === el;
        });
        if (!target) {
          target = {
            el: el,
            id: ++this.TargetIndex,
            childrenCount: 1,
            listened: true
          };
          this.mode === modeType.event && this._initListen(target.el, true);
          this.TargetQueue.push(target);
        } else {
          target.childrenCount++;
        }
        return this.TargetIndex;
      }

      /*
       * remove listener target or reduce target childrenCount
       * @param  {DOM} el or window
       * @return
       */

    }, {
      key: '_removeListenerTarget',
      value: function _removeListenerTarget(el) {
        var _this4 = this;

        this.TargetQueue.forEach(function (target, index) {
          if (target.el === el) {
            target.childrenCount--;
            if (!target.childrenCount) {
              _this4._initListen(target.el, false);
              _this4.TargetQueue.splice(index, 1);
              target = null;
            }
          }
        });
      }

      /*
       * add or remove eventlistener
       * @param  {DOM} el DOM or Window
       * @param  {boolean} start flag
       * @return
       */

    }, {
      key: '_initListen',
      value: function _initListen(el, start) {
        var _this5 = this;

        this.options.ListenEvents.forEach(function (evt) {
          return _[start ? 'on' : 'off'](el, evt, _this5.lazyLoadHandler);
        });
      }
    }, {
      key: '_initEvent',
      value: function _initEvent() {
        var _this6 = this;

        this.Event = {
          listeners: {
            loading: [],
            loaded: [],
            error: []
          }
        };

        this.$on = function (event, func) {
          if (!_this6.Event.listeners[event]) _this6.Event.listeners[event] = [];
          _this6.Event.listeners[event].push(func);
        };

        this.$once = function (event, func) {
          var vm = _this6;
          function on() {
            vm.$off(event, on);
            func.apply(vm, arguments);
          }
          _this6.$on(event, on);
        };

        this.$off = function (event, func) {
          if (!func) {
            if (!_this6.Event.listeners[event]) return;
            _this6.Event.listeners[event].length = 0;
            return;
          }
          remove(_this6.Event.listeners[event], func);
        };

        this.$emit = function (event, context, inCache) {
          if (!_this6.Event.listeners[event]) return;
          _this6.Event.listeners[event].forEach(function (func) {
            return func(context, inCache);
          });
        };
      }

      /**
       * find nodes which in viewport and trigger load
       * @return
       */

    }, {
      key: '_lazyLoadHandler',
      value: function _lazyLoadHandler() {
        var _this7 = this;

        var freeList = [];
        this.ListenerQueue.forEach(function (listener, index) {
          if (!listener.el || !listener.el.parentNode) {
            freeList.push(listener);
          }
          var catIn = listener.checkInView();
          if (!catIn) return;
          listener.load();
        });
        freeList.forEach(function (item) {
          remove(_this7.ListenerQueue, item);
          item.$destroy();
        });
      }
      /**
      * init IntersectionObserver
      * set mode to observer
      * @return
      */

    }, {
      key: '_initIntersectionObserver',
      value: function _initIntersectionObserver() {
        var _this8 = this;

        if (!hasIntersectionObserver) return;
        this._observer = new IntersectionObserver(this._observerHandler.bind(this), this.options.observerOptions);
        if (this.ListenerQueue.length) {
          this.ListenerQueue.forEach(function (listener) {
            _this8._observer.observe(listener.el);
          });
        }
      }

      /**
      * init IntersectionObserver
      * @return
      */

    }, {
      key: '_observerHandler',
      value: function _observerHandler(entries, observer) {
        var _this9 = this;

        entries.forEach(function (entry) {
          if (entry.isIntersecting) {
            _this9.ListenerQueue.forEach(function (listener) {
              if (listener.el === entry.target) {
                if (listener.state.loaded) return _this9._observer.unobserve(listener.el);
                listener.load();
              }
            });
          }
        });
      }

      /**
      * set element attribute with image'url and state
      * @param  {object} lazyload listener object
      * @param  {string} state will be rendered
      * @param  {bool} inCache  is rendered from cache
      * @return
      */

    }, {
      key: '_elRenderer',
      value: function _elRenderer(listener, state, cache) {
        if (!listener.el) return;
        var el = listener.el,
            bindType = listener.bindType;


        var src = void 0;
        switch (state) {
          case 'loading':
            src = listener.loading;
            break;
          case 'error':
            src = listener.error;
            break;
          default:
            src = listener.src;
            break;
        }

        if (bindType) {
          el.style[bindType] = 'url("' + src + '")';
        } else if (el.getAttribute('src') !== src) {
          el.setAttribute('src', src);
        }

        el.setAttribute('lazy', state);

        this.$emit(state, listener, cache);
        this.options.adapter[state] && this.options.adapter[state](listener, this.options);

        if (this.options.dispatchEvent) {
          var event = new CustomEvent(state, {
            detail: listener
          });
          el.dispatchEvent(event);
        }
      }

      /**
      * generate loading loaded error image url
      * @param {string} image's src
      * @return {object} image's loading, loaded, error url
      */

    }, {
      key: '_valueFormatter',
      value: function _valueFormatter(value) {
        var src = value;
        var loading = this.options.loading;
        var error = this.options.error;

        // value is object
        if (vue_lazyload_esm_isObject(value)) {
          if (!value.src && !this.options.silent) console.error('Vue Lazyload warning: miss src with ' + value);
          src = value.src;
          loading = value.loading || this.options.loading;
          error = value.error || this.options.error;
        }
        return {
          src: src,
          loading: loading,
          error: error
        };
      }
    }]);
    return Lazy;
  }();
};

var LazyComponent = (function (lazy) {
  return {
    props: {
      tag: {
        type: String,
        default: 'div'
      }
    },
    render: function render(h) {
      if (this.show === false) {
        return h(this.tag);
      }
      return h(this.tag, null, this.$slots.default);
    },
    data: function data() {
      return {
        el: null,
        state: {
          loaded: false
        },
        rect: {},
        show: false
      };
    },
    mounted: function mounted() {
      this.el = this.$el;
      lazy.addLazyBox(this);
      lazy.lazyLoadHandler();
    },
    beforeDestroy: function beforeDestroy() {
      lazy.removeComponent(this);
    },

    methods: {
      getRect: function getRect() {
        this.rect = this.$el.getBoundingClientRect();
      },
      checkInView: function checkInView() {
        this.getRect();
        return inBrowser && this.rect.top < window.innerHeight * lazy.options.preLoad && this.rect.bottom > 0 && this.rect.left < window.innerWidth * lazy.options.preLoad && this.rect.right > 0;
      },
      load: function load() {
        this.show = true;
        this.state.loaded = true;
        this.$emit('show', this);
      },
      destroy: function destroy() {
        return this.$destroy;
      }
    }
  };
});

var LazyContainerMananger = function () {
  function LazyContainerMananger(_ref) {
    var lazy = _ref.lazy;
    vue_lazyload_esm_classCallCheck(this, LazyContainerMananger);

    this.lazy = lazy;
    lazy.lazyContainerMananger = this;
    this._queue = [];
  }

  vue_lazyload_esm_createClass(LazyContainerMananger, [{
    key: 'bind',
    value: function bind(el, binding, vnode) {
      var container = new LazyContainer$1({ el: el, binding: binding, vnode: vnode, lazy: this.lazy });
      this._queue.push(container);
    }
  }, {
    key: 'update',
    value: function update(el, binding, vnode) {
      var container = find(this._queue, function (item) {
        return item.el === el;
      });
      if (!container) return;
      container.update({ el: el, binding: binding, vnode: vnode });
    }
  }, {
    key: 'unbind',
    value: function unbind(el, binding, vnode) {
      var container = find(this._queue, function (item) {
        return item.el === el;
      });
      if (!container) return;
      container.clear();
      remove(this._queue, container);
    }
  }]);
  return LazyContainerMananger;
}();

var vue_lazyload_esm_defaultOptions = {
  selector: 'img'
};

var LazyContainer$1 = function () {
  function LazyContainer(_ref2) {
    var el = _ref2.el,
        binding = _ref2.binding,
        vnode = _ref2.vnode,
        lazy = _ref2.lazy;
    vue_lazyload_esm_classCallCheck(this, LazyContainer);

    this.el = null;
    this.vnode = vnode;
    this.binding = binding;
    this.options = {};
    this.lazy = lazy;

    this._queue = [];
    this.update({ el: el, binding: binding });
  }

  vue_lazyload_esm_createClass(LazyContainer, [{
    key: 'update',
    value: function update(_ref3) {
      var _this = this;

      var el = _ref3.el,
          binding = _ref3.binding;

      this.el = el;
      this.options = assignDeep({}, vue_lazyload_esm_defaultOptions, binding.value);

      var imgs = this.getImgs();
      imgs.forEach(function (el) {
        _this.lazy.add(el, assignDeep({}, _this.binding, {
          value: {
            src: 'dataset' in el ? el.dataset.src : el.getAttribute('data-src'),
            error: ('dataset' in el ? el.dataset.error : el.getAttribute('data-error')) || _this.options.error,
            loading: ('dataset' in el ? el.dataset.loading : el.getAttribute('data-loading')) || _this.options.loading
          }
        }), _this.vnode);
      });
    }
  }, {
    key: 'getImgs',
    value: function getImgs() {
      return ArrayFrom(this.el.querySelectorAll(this.options.selector));
    }
  }, {
    key: 'clear',
    value: function clear() {
      var _this2 = this;

      var imgs = this.getImgs();
      imgs.forEach(function (el) {
        return _this2.lazy.remove(el);
      });

      this.vnode = null;
      this.binding = null;
      this.lazy = null;
    }
  }]);
  return LazyContainer;
}();

var LazyImage = (function (lazyManager) {
  return {
    props: {
      src: [String, Object],
      tag: {
        type: String,
        default: 'img'
      }
    },
    render: function render(h) {
      return h(this.tag, {
        attrs: {
          src: this.renderSrc
        }
      }, this.$slots.default);
    },
    data: function data() {
      return {
        el: null,
        options: {
          src: '',
          error: '',
          loading: '',
          attempt: lazyManager.options.attempt
        },
        state: {
          loaded: false,
          error: false,
          attempt: 0
        },
        rect: {},
        renderSrc: ''
      };
    },

    watch: {
      src: function src() {
        this.init();
        lazyManager.addLazyBox(this);
        lazyManager.lazyLoadHandler();
      }
    },
    created: function created() {
      this.init();
      this.renderSrc = this.options.loading;
    },
    mounted: function mounted() {
      this.el = this.$el;
      lazyManager.addLazyBox(this);
      lazyManager.lazyLoadHandler();
    },
    beforeDestroy: function beforeDestroy() {
      lazyManager.removeComponent(this);
    },

    methods: {
      init: function init() {
        var _lazyManager$_valueFo = lazyManager._valueFormatter(this.src),
            src = _lazyManager$_valueFo.src,
            loading = _lazyManager$_valueFo.loading,
            error = _lazyManager$_valueFo.error;

        this.state.loaded = false;
        this.options.src = src;
        this.options.error = error;
        this.options.loading = loading;
        this.renderSrc = this.options.loading;
      },
      getRect: function getRect() {
        this.rect = this.$el.getBoundingClientRect();
      },
      checkInView: function checkInView() {
        this.getRect();
        return inBrowser && this.rect.top < window.innerHeight * lazyManager.options.preLoad && this.rect.bottom > 0 && this.rect.left < window.innerWidth * lazyManager.options.preLoad && this.rect.right > 0;
      },
      load: function load() {
        var _this = this;

        var onFinish = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : noop;

        if (this.state.attempt > this.options.attempt - 1 && this.state.error) {
          if (!lazyManager.options.silent) console.log('VueLazyload log: ' + this.options.src + ' tried too more than ' + this.options.attempt + ' times');
          onFinish();
          return;
        }
        var src = this.options.src;
        loadImageAsync({ src: src }, function (_ref) {
          var src = _ref.src;

          _this.renderSrc = src;
          _this.state.loaded = true;
        }, function (e) {
          _this.state.attempt++;
          _this.renderSrc = _this.options.error;
          _this.state.error = true;
        });
      }
    }
  };
});

var vue_lazyload_esm_index = {
  /*
  * install function
  * @param  {Vue} Vue
  * @param  {object} options  lazyload options
  */
  install: function install(Vue) {
    var options = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};

    var LazyClass = Lazy(Vue);
    var lazy = new LazyClass(options);
    var lazyContainer = new LazyContainerMananger({ lazy: lazy });

    var isVue2 = Vue.version.split('.')[0] === '2';

    Vue.prototype.$Lazyload = lazy;

    if (options.lazyComponent) {
      Vue.component('lazy-component', LazyComponent(lazy));
    }

    if (options.lazyImage) {
      Vue.component('lazy-image', LazyImage(lazy));
    }

    if (isVue2) {
      Vue.directive('lazy', {
        bind: lazy.add.bind(lazy),
        update: lazy.update.bind(lazy),
        componentUpdated: lazy.lazyLoadHandler.bind(lazy),
        unbind: lazy.remove.bind(lazy)
      });
      Vue.directive('lazy-container', {
        bind: lazyContainer.bind.bind(lazyContainer),
        componentUpdated: lazyContainer.update.bind(lazyContainer),
        unbind: lazyContainer.unbind.bind(lazyContainer)
      });
    } else {
      Vue.directive('lazy', {
        bind: lazy.lazyLoadHandler.bind(lazy),
        update: function update(newValue, oldValue) {
          assignDeep(this.vm.$refs, this.vm.$els);
          lazy.add(this.el, {
            modifiers: this.modifiers || {},
            arg: this.arg,
            value: newValue,
            oldValue: oldValue
          }, {
            context: this.vm
          });
        },
        unbind: function unbind() {
          lazy.remove(this.el);
        }
      });

      Vue.directive('lazy-container', {
        update: function update(newValue, oldValue) {
          lazyContainer.update(this.el, {
            modifiers: this.modifiers || {},
            arg: this.arg,
            value: newValue,
            oldValue: oldValue
          }, {
            context: this.vm
          });
        },
        unbind: function unbind() {
          lazyContainer.unbind(this.el);
        }
      });
    }
  }
};

/* harmony default export */ var vue_lazyload_esm = (vue_lazyload_esm_index);

// EXTERNAL MODULE: ./src/packages/lazyload/lazyload.scss
var lazyload = __webpack_require__(120);

// CONCATENATED MODULE: ./src/packages/lazyload/index.js

vue_lazyload_esm.name = 'vue-lazyload';

/* harmony default export */ var packages_lazyload = (vue_lazyload_esm);
// EXTERNAL MODULE: ./src/packages/textbox/textbox.scss
var textbox = __webpack_require__(62);

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/textbox/textbox.vue?vue&type=template&id=90a8327c&
var textboxvue_type_template_id_90a8327c_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-textbox"},[_c('div',{staticClass:"txt-area",class:{ error: _vm.errorState, 'num-none': _vm.limitShow == false, disabled: _vm.disabled },style:({ background: _vm.textBgColor })},[_c('textarea',{directives:[{name:"model",rawName:"v-model",value:(_vm.currentValue),expression:"currentValue"}],style:({ height: _vm.txtAreaHeight + 'px' }),attrs:{"placeholder":_vm.placeText,"disabled":_vm.disabled,"maxlength":_vm.iptMaxlength},domProps:{"value":(_vm.currentValue)},on:{"input":[function($event){if($event.target.composing){ return; }_vm.currentValue=$event.target.value},_vm.txtIptLength]}}),_vm._v(" "),_c('span',{directives:[{name:"show",rawName:"v-show",value:(_vm.limitShow),expression:"limitShow"}]},[_vm._v(_vm._s(_vm.txtNum)+"/"+_vm._s(_vm.maxNum))])])])}
var textboxvue_type_template_id_90a8327c_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/textbox/textbox.vue?vue&type=template&id=90a8327c&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/textbox/textbox.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var textboxvue_type_script_lang_js_ = ({
  name: 'nut-textbox',
  props: {
    value: {
      type: [String, Number],
      default: ''
    },
    disabled: {
      type: Boolean,
      default: false
    },
    maxNum: {
      type: [String, Number],
      default: 50
    },
    placeText: {
      type: String,
      default: '请您在此输入'
    },
    txtAreaH: {
      type: [String, Number],
      default: '50'
    },
    switchMax: {
      type: Boolean,
      default: false
    },
    textBgColor: {
      type: String,
      default: '#fff'
    },
    limitShow: {
      type: Boolean,
      default: true
    }
  },
  data: function data() {
    return {
      errorState: false,
      txtNum: 0
    };
  },
  mounted: function mounted() {},
  computed: {
    currentValue: {
      get: function get() {
        this.txtNum = this.value.length;

        if (this.txtNum > this.maxNum) {
          this.txtNum = this.maxNum;
          return this.value.substr(0, this.maxNum);
        } else {
          return this.value;
        }
      },
      set: function set(val) {}
    },
    txtAreaHeight: function txtAreaHeight() {
      var txtAreaH;
      txtAreaH = this.txtAreaH;
      return txtAreaH;
    },
    iptMaxlength: function iptMaxlength() {
      var maxlength;

      if (this.switchMax) {
        maxlength = this.maxNum;
      }

      return maxlength;
    }
  },
  methods: {
    txtIptLength: function txtIptLength(event) {
      var data = event.target.value;
      var txtLength = data.length;
      this.txtNum = txtLength;

      if (txtLength > this.maxNum) {
        this.errorState = true;
        this.$emit('errorFunc');
      } else {
        this.errorState = false;
      }

      this.$emit('inputFunc', data);
      this.$emit('input', data);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/textbox/textbox.vue?vue&type=script&lang=js&
 /* harmony default export */ var textbox_textboxvue_type_script_lang_js_ = (textboxvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/textbox/textbox.vue





/* normalize component */

var textbox_component = normalizeComponent(
  textbox_textboxvue_type_script_lang_js_,
  textboxvue_type_template_id_90a8327c_render,
  textboxvue_type_template_id_90a8327c_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var textbox_textbox = (textbox_component.exports);
// CONCATENATED MODULE: ./src/packages/textbox/index.js



textbox_textbox.install = function (Vue) {
  Vue.component(textbox_textbox.name, textbox_textbox);
};

/* harmony default export */ var packages_textbox = (textbox_textbox);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/elevator/elevator.vue?vue&type=template&id=4aa87c5d&
var elevatorvue_type_template_id_4aa87c5d_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return (_vm.dataArray.length > 0)?_c('div',{staticClass:"nut-elevator",style:({ height: _vm.wrapHeight + 'px' })},[_c('div',{staticClass:"nut-main",style:({ height: _vm.wrapHeight + 'px' })},[_c('ul',{staticClass:"nut-elevator-ul",attrs:{"id":"nut-elevator-ul"}},_vm._l((_vm.dataArray),function(item){return _c('li',{key:item.title,staticClass:"nut-list-title"},[_c('h3',{staticClass:"nut-list-h",attrs:{"id":item.title}},[_vm._v(_vm._s(item.title))]),_vm._v(" "),_c('ul',{staticClass:"nut-people-list"},_vm._l((item.list),function(list,idx){return _c('li',{key:idx,staticClass:"nut-list-name",attrs:{"id":list.id ? list.id : 'list' + item.title + idx},on:{"click":function($event){return _vm.clickList(list, item)}}},[_vm._v(_vm._s(list.name))])}),0)])}),0),_vm._v(" "),_c('ul',{staticClass:"nut-elevator-nav",attrs:{"id":"nut-elevator-nav"},on:{"touchmove":function($event){return _vm.onPointerMove($event)},"touchstart":function($event){return _vm.onPointerMove($event)},"touchend":function($event){return _vm.onPointerEnd($event)}}},_vm._l((_vm.dataArray),function(item,index){return _c('li',{key:index,staticClass:"nut-nav-list",style:({ height: _vm.navListHeight + 'px', lineHeight: _vm.navListHeight + 'px' }),attrs:{"id":'nav' + index},on:{"click":function($event){return _vm.clickNav(item.title, index)}}},[_vm._v(_vm._s(item.title))])}),0),_vm._v(" "),(_vm.showIndicator)?[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.currBox),expression:"currBox"}],staticClass:"nut-big-box"},[_vm._v("\n        "+_vm._s(_vm.currTitle)+"\n      ")])]:_vm._e()],2)]):_vm._e()}
var elevatorvue_type_template_id_4aa87c5d_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/elevator/elevator.vue?vue&type=template&id=4aa87c5d&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/elevator/elevator.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var elevatorvue_type_script_lang_js_ = ({
  name: 'nut-elevator',
  props: {
    otherHeight: {
      type: Number,
      default: '60'
    },
    dataArray: {
      type: Array,
      required: true
    },
    navHeight: {
      type: Number,
      default: '40'
    },
    hiddenTime: {
      type: Number,
      default: '10'
    },
    showIndicator: {
      type: Boolean,
      default: true
    },
    initIndex: {
      type: Number,
      default: '0'
    }
  },
  computed: {
    navListHeight: function navListHeight() {
      return this.navHeight;
    }
  },
  data: function data() {
    return {
      wrapHeight: '40',
      currTitle: '',
      currBox: false
    };
  },
  watch: {
    dataArray: function dataArray(val) {
      var _this = this;

      if (val.length > 0) {
        this.$nextTick(function () {
          _this.initPage();
        });
      }
    }
  },
  mounted: function mounted() {
    if (this.dataArray.length > 0) {
      this.initPage();
    }
  },
  methods: {
    initPage: function initPage() {
      var innerHeight = document.documentElement.clientHeight;
      this.wrapHeight = innerHeight - this.otherHeight;
      var initIndex = this.dataArray[this.initIndex].title;
      document.getElementById(initIndex).scrollIntoView();
    },
    getStyle: function getStyle(element, attr) {
      if (element.currentStyle) {
        return element.currentStyle[attr];
      } else {
        return getComputedStyle(element, false)[attr];
      }
    },
    getFontSize: function getFontSize() {
      var htmlDom = document.getElementsByTagName('html')[0];
      var bili = this.getStyle(htmlDom, 'fontSize');
      return bili.substring(0, bili.length - 2);
    },
    clickNav: function clickNav(title, index) {
      var _this2 = this;

      this.currBox = true;
      this.currTitle = title;
      setTimeout(function () {
        _this2.currBox = false;
      }, this.hiddenTime);
      this.moveFun(title, index);
    },
    clickList: function clickList(list, item) {
      this.$emit('clickList', list, item);
    },
    moveFun: function moveFun(title, index) {
      var titleBox = document.getElementById(title);
      titleBox.scrollIntoView();
    },
    onPointerEnd: function onPointerEnd(e) {
      var _this3 = this;

      var dataArrayLength = this.dataArray.length;
      var navHeight = document.getElementById('nut-elevator-nav').clientHeight;
      var navTop = document.getElementById('nut-elevator-nav').offsetTop;
      var navOffsetTop = navTop - navHeight / 2; //nav距离顶部的距离

      var eTop = e.type.indexOf('touch') !== -1 ? e.changedTouches[0].clientY : e.clientY;
      var navIndex = parseInt((eTop - navOffsetTop) / this.navHeight);
      setTimeout(function () {
        _this3.currBox = false;
      }, this.hiddenTime);

      if (navIndex < dataArrayLength && navIndex >= 0) {
        this.$emit('clickNav', this.dataArray[navIndex].title, navIndex);
      }
    },
    onPointerMove: function onPointerMove(e) {
      e.preventDefault();
      var dataArrayLength = this.dataArray.length;
      var navHeight = document.getElementById('nut-elevator-nav').clientHeight;
      var navTop = document.getElementById('nut-elevator-nav').offsetTop;
      var navOffsetTop = navTop - navHeight / 2; //nav距离顶部的距离

      var eTop = e.type.indexOf('touch') !== -1 ? e.touches[0].clientY : e.clientY;
      var navIndex = parseInt((eTop - navOffsetTop) / this.navHeight);

      if (navIndex < dataArrayLength && navIndex >= 0) {
        this.moveFun(this.dataArray[navIndex].title, navIndex);
        this.currBox = true;
        this.currTitle = this.dataArray[navIndex].title;
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/elevator/elevator.vue?vue&type=script&lang=js&
 /* harmony default export */ var elevator_elevatorvue_type_script_lang_js_ = (elevatorvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/elevator/elevator.vue





/* normalize component */

var elevator_component = normalizeComponent(
  elevator_elevatorvue_type_script_lang_js_,
  elevatorvue_type_template_id_4aa87c5d_render,
  elevatorvue_type_template_id_4aa87c5d_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var elevator = (elevator_component.exports);
// EXTERNAL MODULE: ./src/packages/elevator/elevator.scss
var elevator_elevator = __webpack_require__(63);

// CONCATENATED MODULE: ./src/packages/elevator/index.js



elevator.install = function (Vue) {
  Vue.component(elevator.name, elevator);
};

/* harmony default export */ var packages_elevator = (elevator);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/popup/popup.vue?vue&type=template&id=76b6cf75&
var popupvue_type_template_id_76b6cf75_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('transition',{attrs:{"name":_vm.transitionName},on:{"after-enter":function($event){return _vm.$emit('opened')},"after-leave":function($event){return _vm.$emit('closed')}}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.value),expression:"value"}],ref:"popupBox",staticClass:"popup-box",class:[("popup-" + _vm.position), { round: _vm.round }],style:({ animationDuration: _vm.transitionDuration }),on:{"click":function($event){return _vm.$emit('click', this)}}},[(_vm.showSlot)?_vm._t("default"):_vm._e(),_vm._v(" "),(_vm.closeable)?_c('icon',{staticClass:"nutui-popup__close-icon",class:'nutui-popup__close-icon--' + _vm.closeIconPosition,attrs:{"type":_vm.closeIcon,"size":"12px"},nativeOn:{"click":function($event){return _vm.$emit('input', false)}}}):_vm._e()],2)])}
var popupvue_type_template_id_76b6cf75_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/popup/popup.vue?vue&type=template&id=76b6cf75&

// CONCATENATED MODULE: ./src/mixins/touch.js

var MIN_DISTANCE = 10;

function getDirection(x, y) {
  if (x > y && x > MIN_DISTANCE) {
    return 'horizontal';
  }

  if (y > x && y > MIN_DISTANCE) {
    return 'vertical';
  }

  return '';
}

var TouchMixin = external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.extend({
  data: function data() {
    return {
      direction: ''
    };
  },
  methods: {
    touchStart: function touchStart(event) {
      this.resetTouchStatus();
      this.startX = event.touches[0].clientX;
      this.startY = event.touches[0].clientY;
    },
    touchMove: function touchMove(event) {
      var touch = event.touches[0];
      this.deltaX = touch.clientX - this.startX;
      this.deltaY = touch.clientY - this.startY;
      this.offsetX = Math.abs(this.deltaX);
      this.offsetY = Math.abs(this.deltaY);
      this.direction = this.direction || getDirection(this.offsetX, this.offsetY);
    },
    resetTouchStatus: function resetTouchStatus() {
      this.direction = '';
      this.deltaX = 0;
      this.deltaY = 0;
      this.offsetX = 0;
      this.offsetY = 0;
    }
  }
});
/* harmony default export */ var touch = (TouchMixin);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/popup/overlay/overlay.vue?vue&type=template&id=6ac1460a&
var overlayvue_type_template_id_6ac1460a_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('transition',{attrs:{"name":"popup-fade"}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.value),expression:"value"}],staticClass:"popup-bg nut-mask",class:_vm.overlayClass,style:(Object.assign({}, {animationDuration: (_vm.duration + "s")}, _vm.overlayStyle, {zIndex: _vm.zIndex})),on:{"touchmove":function($event){$event.stopPropagation();return _vm.touchmove($event)}}})])}
var overlayvue_type_template_id_6ac1460a_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/popup/overlay/overlay.vue?vue&type=template&id=6ac1460a&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/popup/overlay/overlay.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
var overlayProps = {
  value: {
    type: Boolean,
    default: false
  },
  overlay: {
    type: Boolean,
    default: true
  },
  lockScroll: {
    type: Boolean,
    default: true
  },
  duration: {
    type: Number,
    default: 0.3
  },
  closeOnClickOverlay: {
    type: Boolean,
    default: true
  },
  overlayClass: {
    type: String,
    default: ''
  },
  overlayStyle: {
    type: Object,
    default: function _default() {}
  },
  zIndex: {
    type: Number
  }
};

/* harmony default export */ var overlayvue_type_script_lang_js_ = ({
  name: 'nut-popup-overlay',
  props: overlayProps,
  methods: {
    touchmove: function touchmove(e) {
      if (this.lockScroll) {
        e.preventDefault();
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/popup/overlay/overlay.vue?vue&type=script&lang=js&
 /* harmony default export */ var overlay_overlayvue_type_script_lang_js_ = (overlayvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/popup/overlay/overlay.vue





/* normalize component */

var overlay_component = normalizeComponent(
  overlay_overlayvue_type_script_lang_js_,
  overlayvue_type_template_id_6ac1460a_render,
  overlayvue_type_template_id_6ac1460a_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var overlay = (overlay_component.exports);
// CONCATENATED MODULE: ./src/packages/popup/overlay/overlay-manager.js



function overlay_manager_ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function overlay_manager_objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { overlay_manager_ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { overlay_manager_ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }



var modalStack = [];
var _zIndex = 2000;
var overlay_manager_overlay;
var overlayManager = {
  lockCount: 0,

  get topStack() {
    return modalStack[modalStack.length - 1];
  },

  getZIndex: function getZIndex(id) {
    if (!id) return ++_zIndex;
    var overlay = modalStack.find(function (res) {
      return res.config.id === id;
    });

    if (overlay) {
      return overlay.config.zIndex;
    } else {
      return ++_zIndex;
    }
  },
  updateOverlay: function updateOverlay() {
    var clickHandle = overlayManager.clickHandle,
        topStack = overlayManager.topStack;

    if (!overlay_manager_overlay) {
      overlay_manager_overlay = mount(overlay, {
        nativeOn: {
          click: clickHandle
        }
      });
    }

    if (topStack) {
      var vm = topStack.vm,
          config = topStack.config;
      var el = vm.$el;
      el && el.parentNode && el.parentNode.nodeType !== 11 ? el.parentNode.appendChild(overlay_manager_overlay.$el) : document.body.appendChild(overlay_manager_overlay.$el);

      extends_default()(overlay_manager_overlay, config, {
        value: true
      });
    } else {
      overlay_manager_overlay.value = false;
    }
  },
  //打开遮罩层
  openModal: function openModal(vm, config) {
    var zIndex = config.zIndex,
        duration = config.duration,
        overlayClass = config.overlayClass,
        overlayStyle = config.overlayStyle,
        id = config.id;
    modalStack.push({
      vm: vm,
      config: {
        id: id,
        zIndex: zIndex,
        duration: duration,
        overlayClass: overlayClass,
        overlayStyle: overlayStyle
      }
    });
    overlayManager.updateOverlay();
  },
  clickHandle: function clickHandle() {
    var topStack = overlayManager.topStack; //防止多次点击

    if (modalStack.length && topStack.vm.closeOnClickOverlay) {
      topStack.vm.$emit('click-overlay');
      topStack.vm.close();
    }
  },
  closeOverlay: function closeOverlay(vm) {
    if (modalStack.length) {
      if (overlayManager.topStack.vm === vm) {
        modalStack.pop();
        overlayManager.updateOverlay();
      } else {
        modalStack = modalStack.filter(function (item) {
          return item.vm !== vm;
        });
      }
    }
  }
};
var overlay_manager_overlayProps = {
  value: {
    type: Boolean,
    default: false
  },
  overlay: {
    type: Boolean,
    default: true
  },
  lockScroll: {
    type: Boolean,
    default: true
  },
  duration: {
    type: Number,
    default: 0.3
  },
  closeOnClickOverlay: {
    type: Boolean,
    default: true
  },
  overlayClass: {
    type: String,
    default: ''
  },
  overlayStyle: {
    type: Object,
    default: function _default() {
      return null;
    }
  },
  zIndex: {
    type: Number
  }
};

function mount(Component, data) {
  var instance = new external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a({
    props: Component.props,
    render: function render(h) {
      return h(Component, overlay_manager_objectSpread({
        props: this.$props
      }, data));
    }
  }).$mount();
  return instance;
}

function getProps() {
  var _this = this;

  if (!this) return {};
  var obj = {};
  Object.keys(overlay_manager_overlayProps).forEach(function (res) {
    obj[res] = _this[res];
  });
  return obj;
}


// CONCATENATED MODULE: ./src/utils/event.js
var passiveSupported = false;

try {
  var event_options = Object.defineProperty({}, 'passive', {
    get: function get() {
      passiveSupported = true;
    }
  });
  window.addEventListener('test', null, event_options);
} catch (err) {}

function on(target, event, handler) {
  var passive = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : false;
  target.addEventListener(event, handler, passiveSupported ? {
    capture: false,
    passive: passive
  } : false);
}
function off(target, event, handler) {
  target.removeEventListener(event, handler);
}
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/popup/popup.vue?vue&type=script&lang=js&


function popupvue_type_script_lang_js_ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function popupvue_type_script_lang_js_objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { popupvue_type_script_lang_js_ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { popupvue_type_script_lang_js_ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//







var overflowScrollReg = /scroll|auto/i;
var popupProps = {
  id: {
    type: String | Number,
    default: ''
  },
  position: {
    type: String,
    default: 'center'
  },
  transition: String,
  closeable: {
    type: Boolean,
    default: false
  },
  closeIconPosition: {
    type: String,
    default: 'top-right'
  },
  closeIcon: {
    type: String,
    default: 'cross'
  },
  closeOnClickOverlay: {
    type: Boolean,
    default: true
  },
  destroyOnClose: {
    type: Boolean,
    default: false
  },
  getContainer: String,
  round: {
    type: Boolean,
    default: false
  }
};
/* harmony default export */ var popupvue_type_script_lang_js_ = ({
  name: 'nut-popup',
  mixins: [touch],
  components: {
    icon: icon
  },
  props: popupvue_type_script_lang_js_objectSpread(popupvue_type_script_lang_js_objectSpread({}, overlayProps), popupProps),
  created: function created() {
    this.transition ? this.transitionName = this.transition : this.transitionName = "popup-slide-".concat(this.position);
  },
  mounted: function mounted() {
    if (this.value) {
      this.open();
    }
  },
  beforeDestroy: function beforeDestroy() {
    if (this.value) {
      this.close();
    }
  },
  activated: function activated() {
    if (this.keepAlive) {
      this.$emit('input', true);
      this.keepAlive = false;
    }
  },
  deactivated: function deactivated() {
    if (this.value) {
      this.close();
      this.keepAlive = true;
    }
  },
  watch: {
    value: function value(val) {
      var type = val ? 'open' : 'close';
      this[type]();
    },
    position: function position(val) {
      val === 'center' ? this.transitionName = 'popup-fade' : this.transitionName = "popup-slide-".concat(this.position);
    },
    getContainer: 'portal',
    overlay: 'renderOverlay'
  },
  data: function data() {
    return {
      showSlot: true,
      transitionName: 'popup-fade-center',
      overlayInstant: null
    };
  },
  computed: {
    transitionDuration: function transitionDuration() {
      return this.duration ? this.duration + 's' : 'initial';
    }
  },
  methods: {
    open: function open() {
      if (this.opened) {
        return;
      }

      if (this.destroyOnClose) {
        this.showSlot = true;
      }

      this.opened = true;
      this.$emit('open');
      var duration = this.duration,
          overlayClass = this.overlayClass,
          overlayStyle = this.overlayStyle,
          lockScroll = this.lockScroll,
          closeOnClickOverlay = this.closeOnClickOverlay;
      var config = {
        id: this.id,
        zIndex: this.zIndex ? this.zIndex : overlayManager.getZIndex(this.id),
        duration: duration,
        overlayClass: overlayClass,
        overlayStyle: overlayStyle,
        lockScroll: lockScroll,
        closeOnClickOverlay: closeOnClickOverlay
      };
      this.renderOverlay(config);

      if (this.lockScroll) {
        on(document, 'touchstart', this.touchStart);
        on(document, 'touchmove', this.onTouchMove);

        if (!overlayManager.lockCount) {
          document.body.classList.add('nut-overflow-hidden');
        }

        overlayManager.lockCount++;
      }

      this.$el.style.zIndex = this.zIndex ? this.zIndex + 1 : overlayManager.getZIndex();
    },
    renderOverlay: function renderOverlay(config) {
      if (!this.value) {
        return;
      }

      if (this.overlay) {
        overlayManager.openModal(this, config);
      } else {
        overlayManager.closeOverlay(this);
      }
    },
    onTouchMove: function onTouchMove(event) {
      this.touchMove(event);
      var el = this.getScroller(event.target);

      var _ref = el ? el : this.$el,
          scrollHeight = _ref.scrollHeight,
          offsetHeight = _ref.offsetHeight,
          scrollTop = _ref.scrollTop;

      if (this.deltaY > 0 && scrollTop === 0 || this.deltaY < 0 && scrollTop + offsetHeight >= scrollHeight) {
        if (event.cancelable) {
          event.preventDefault();
        }
      }
    },
    getScroller: function getScroller(el) {
      var node = el;

      while (node && node.tagName !== 'HTML' && node.nodeType === 1) {
        var _window$getComputedSt = window.getComputedStyle(node),
            overflowY = _window$getComputedSt.overflowY;

        if (overflowScrollReg.test(overflowY)) {
          return node;
        }

        node = node.parentNode;
      }
    },
    close: function close() {
      var _this = this;

      if (!this.opened) {
        return;
      }

      this.$emit('close');
      this.opened = false;

      if (this.lockScroll) {
        overlayManager.lockCount--;
        off(document, 'touchstart', this.touchStart);
        off(document, 'touchmove', this.onTouchMove);

        if (!overlayManager.lockCount) {
          document.body.classList.remove('nut-overflow-hidden');
        }
      }

      if (this.destroyOnClose) {
        setTimeout(function () {
          _this.showSlot = false;
        }, this.duration * 1000);
      }

      overlayManager.closeOverlay(this);
      this.$emit('input', false);
    },
    getElement: function getElement(selector) {
      return document.querySelector(selector);
    },
    portal: function portal() {
      var getContainer = this.getContainer;
      var el = this.$el;
      var container;

      if (getContainer) {
        container = this.getElement(getContainer);
      } else if (this.$parent) {
        container = this.$parent.$el;
      }

      if (container && container !== el.parentNode) {
        container.appendChild(el);
      }
    }
  }
});

// CONCATENATED MODULE: ./src/packages/popup/popup.vue?vue&type=script&lang=js&
 /* harmony default export */ var popup_popupvue_type_script_lang_js_ = (popupvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/popup/popup.vue





/* normalize component */

var popup_component = normalizeComponent(
  popup_popupvue_type_script_lang_js_,
  popupvue_type_template_id_76b6cf75_render,
  popupvue_type_template_id_76b6cf75_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var popup = (popup_component.exports);
// EXTERNAL MODULE: ./src/packages/popup/popup.scss
var popup_popup = __webpack_require__(14);

// CONCATENATED MODULE: ./src/packages/popup/index.js





popup.install = function (Vue) {
  Vue.component(popup.name, popup);
};

/* harmony default export */ var packages_popup = (popup);

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/leftslip/leftslip.vue?vue&type=template&id=3149241d&
var leftslipvue_type_template_id_3149241d_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-leftslip"},[_c('div',{ref:"slipItem",staticClass:"nut-leftslip-item",class:{ 'leftslip-open': _vm.isOpen }},[_c('div',{staticClass:"nut-leftslip-item-main",on:{"touchstart":function($event){return _vm.touchStart($event)},"touchmove":function($event){return _vm.touchMove($event)},"touchend":function($event){return _vm.touchEnd($event)}}},[_vm._t("slip-main")],2),_vm._v(" "),_c('div',{ref:"right",staticClass:"nut-leftslip-item-btn"},[_vm._t("slipbtns")],2)])])}
var leftslipvue_type_template_id_3149241d_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/leftslip/leftslip.vue?vue&type=template&id=3149241d&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/leftslip/leftslip.vue?vue&type=script&lang=js&
function _createForOfIteratorHelper(o, allowArrayLike) { var it; if (typeof Symbol === "undefined" || o[Symbol.iterator] == null) { if (Array.isArray(o) || (it = _unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") { if (it) o = it; var i = 0; var F = function F() {}; return { s: F, n: function n() { if (i >= o.length) return { done: true }; return { done: false, value: o[i++] }; }, e: function e(_e) { throw _e; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var normalCompletion = true, didErr = false, err; return { s: function s() { it = o[Symbol.iterator](); }, n: function n() { var step = it.next(); normalCompletion = step.done; return step; }, e: function e(_e2) { didErr = true; err = _e2; }, f: function f() { try { if (!normalCompletion && it.return != null) it.return(); } finally { if (didErr) throw err; } } }; }

function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }

function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) { arr2[i] = arr[i]; } return arr2; }

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var leftslipvue_type_script_lang_js_ = ({
  name: 'nut-leftslip',
  props: {
    isClickBack: {
      type: Boolean,
      default: true
    },
    rightWidth: {
      type: [Number, String],
      default: '0.8'
    },
    disabled: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      startX: 0,
      startY: 0,
      moveX: 0,
      moveY: 0,
      buttonWidth: 0,
      pageWidth: null,
      startPos: 0,
      startLeft: 0,
      startRightW: 0,
      isOpen: false,
      scrollTop: 0,
      oldScrollTop: 0,
      lock: false
    };
  },
  watch: {// scrollTop(newValue, oldValue) {
    //     setTimeout(() => {
    //         if (newValue == window.scrollY) { //延时执行后当newValue等于window.scrollY，代表滚动结束
    //             console.log('滚动结束');
    //             this.oldScrollTop = newValue; //每次滚动结束后都要给oldScrollTop赋值
    //             this.lock = false
    //         };
    //     }, 20); //必须使用延时器，否则每次newValue和window.scrollY都相等，无法判断，20ms刚好大于watch的侦听周期，故延时20ms
    //     if (this.oldScrollTop == oldValue) { //每次滚动开始时oldScrollTop与oldValue相等
    //         console.log('滚动开始');
    //         this.lock = true;
    //     }
    // }
  },
  mounted: function mounted() {
    var _this = this;

    this.$nextTick(function () {
      var _iterator = _createForOfIteratorHelper(_this.$slots.slipbtns),
          _step;

      try {
        for (_iterator.s(); !(_step = _iterator.n()).done;) {
          var slot = _step.value;
          _this.buttonWidth = _this.buttonWidth + slot.elm.offsetWidth;
        }
      } catch (err) {
        _iterator.e(err);
      } finally {
        _iterator.f();
      }
    });
    this.pageWidth = document.documentElement.clientWidth;
    this.sliderEle = this.$refs.slipItem; // this.handleScroll();
    // document.addEventListener('touchstart', this.touchStart, false);
  },
  beforeDestroy: function beforeDestroy() {
    // 移除监听
    window.removeEventListener('scroll', this.handleScroll());
  },
  methods: {
    handleRestet: function handleRestet() {
      var slip = document.getElementsByClassName('leftslip-open');

      if (slip) {
        this.restSlide();
      }
    },
    handleScroll: function handleScroll() {
      var _this2 = this;

      window.addEventListener('scroll', function () {
        _this2.scrollTop = window.scrollY;
      });
    },
    touchStart: function touchStart(e) {
      if (this.disabled) return false;
      var parentElement = e.currentTarget.parentElement;
      var slip = [];
      slip = document.getElementsByClassName('leftslip-open');

      if (slip) {
        if (parentElement.dataset.type == 1) return;
        this.restSlide();
      }

      if (e.touches.length == 1) {
        this.startX = e.touches[0].pageX;
        this.startY = e.touches[0].pageY;
      }

      var transform = this.sliderEle.style.transform;
      this.startLeft = Number(transform ? transform.split('(')[1].split('px')[0] : 0);
      this.startRightW = this.startLeft < 0 ? Number(this.$refs.right.style.width.split('px')[0]) : 0;
    },
    touchMove: function touchMove(e) {
      if (this.disabled) return false;
      var parentElement = e.currentTarget.parentElement;
      var disX = e.touches[0].pageX - this.startX; // >0 右滑，<0 左滑

      var disY = e.touches[0].pageY - this.startY;

      if (e.touches.length == 1) {
        if (Math.abs(disY) < 5) {
          // console.log(disX, disY)
          if (disX > 0 || disX > 0 && this.startLeft >= 0) {
            //禁止右滑
            return false;
          } else {
            this.doSlide(-this.buttonWidth, true); // 最大滑动距离为右侧宽度
          }
        }
      }
    },
    touchEnd: function touchEnd(e) {
      if (this.disabled) return false;
      var parentElement = e.currentTarget.parentElement;
      var disX = e.changedTouches[0].pageX - this.startX; // >0 右滑，<0 左滑

      var distance; // console.log(1, disX, this.isClickBack)

      if (!this.isClickBack && disX === 0) {
        // 点击时不收起右侧
        // console.log(2, disX, this.isClickBack)
        return false;
      } else {
        if (-disX > 50) {
          // 向左滑动超过阙值时,右侧滑出固定距离
          distance = this.buttonWidth > this.pageWidth ? this.pageWidth * Number(this.rightWidth) : this.buttonWidth;
          parentElement.className = 'nut-leftslip-item leftslip-open';
          parentElement.dataset.type = 1;
        } else {
          // 向左滑动未超过阙值，或向右滑动时，回原位
          distance = 0;
          parentElement.className = 'nut-leftslip-item';
          parentElement.dataset.type = 0;
        } // console.log(3, disX, this.isClickBack)


        this.doSlide(-distance, true);
      }
    },
    doSlide: function doSlide(distance) {
      var animate = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : false;
      this.sliderEle.style.transform = "translateX(".concat(distance, "px)");
      this.$refs.right.style.width = -distance + 'px';
      this.sliderEle.style.transition = animate ? 'transform .5s' : 'initial';
      this.$refs.right.style.transition = animate ? 'width .5s' : 'initial';
    },
    restSlide: function restSlide() {
      var listItems = document.querySelectorAll('.nut-leftslip-item.leftslip-open'); // 复位

      for (var i = 0; i < listItems.length; i++) {
        listItems[i].style = 'transform:translateX(0px)';
        listItems[i].dataset.type = 0; //是否展开标志位默认0，左滑展开为1，右滑隐藏为0

        listItems[i].className = 'nut-leftslip-item';
        this.isOpen = false;
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/leftslip/leftslip.vue?vue&type=script&lang=js&
 /* harmony default export */ var leftslip_leftslipvue_type_script_lang_js_ = (leftslipvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/leftslip/leftslip.vue





/* normalize component */

var leftslip_component = normalizeComponent(
  leftslip_leftslipvue_type_script_lang_js_,
  leftslipvue_type_template_id_3149241d_render,
  leftslipvue_type_template_id_3149241d_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var leftslip = (leftslip_component.exports);
// EXTERNAL MODULE: ./src/packages/leftslip/leftslip.scss
var leftslip_leftslip = __webpack_require__(64);

// CONCATENATED MODULE: ./src/packages/leftslip/index.js



leftslip.install = function (Vue) {
  Vue.component(leftslip.name, leftslip);
};

/* harmony default export */ var packages_leftslip = (leftslip);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabselect/tabselect.vue?vue&type=template&id=67057514&
var tabselectvue_type_template_id_67057514_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return (_vm.list.length)?_c('div',{staticClass:"nut-tabselect"},[_c('nut-popup',{style:({ height: '457px' }),attrs:{"round":"","closeable":"","position":"bottom","lock-scroll":_vm.isLockBgScroll},model:{value:(_vm.isShow),callback:function ($$v) {_vm.isShow=$$v},expression:"isShow"}},[_c('div',{staticClass:"nut-tabselect-main-title",domProps:{"innerHTML":_vm._s(_vm.mainTitle)}}),_vm._v(" "),_c('nut-tab',{attrs:{"init-data":_vm.list},on:{"tab-switch":_vm.tabSwitchOuter}},_vm._l((_vm.list),function(value,idx){return _c('nut-tab-panel',{key:value.tabTitle,attrs:{"tabTitle":value.tabTitle}},[_c('div',{staticClass:"nut-tabselect-sub-title",domProps:{"innerHTML":_vm._s(_vm.subTitle)}}),_vm._v(" "),_c('nut-tab',{staticClass:"nut-tab-inner",attrs:{"positionNav":"left","init-data":value.children,"defIndex":_vm.defIndex},on:{"tab-switch":_vm.tabSwitchInner}},_vm._l((value.children),function(item,index){return _c('nut-tab-panel',{key:item.tabTitle,attrs:{"tabTitle":item.tabTitle}},[_c('ul',[(item.content)?_vm._l((item.content),function(sitem,sIndex){return _c('li',{key:sitem,staticClass:"nut-tab-panel-list",class:{
                    'nut-tab-panel-list-active': _vm.isActive(idx, index, sIndex)
                  },on:{"click":function($event){return _vm.choose(idx, index, sIndex, item, sitem)}}},[_vm._v("\n                  "+_vm._s(sitem)+"\n                ")])}):(_vm.defaultContent)?_vm._l((_vm.defaultContent),function(sitem,sIndex){return _c('li',{key:sitem,staticClass:"nut-tab-panel-list",class:{
                    'nut-tab-panel-list-active': _vm.isActive(idx, index, sIndex)
                  },on:{"click":function($event){return _vm.choose(idx, index, sIndex, item, sitem)}}},[_vm._v("\n                  "+_vm._s(sitem)+"\n                ")])}):_vm._e()],2)])}),1)],1)}),1),_vm._v(" "),_c('div',{staticClass:"nut-tabselect-btn"},[_c('a',{attrs:{"href":"javascript:;"},on:{"click":_vm.clickHandler}},[_vm._v("确定")])])],1)],1):_vm._e()}
var tabselectvue_type_template_id_67057514_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/tabselect/tabselect.vue?vue&type=template&id=67057514&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/tabselect/tabselect.vue?vue&type=script&lang=js&



var tabselectvue_type_script_lang_js_components;

function tabselectvue_type_script_lang_js_createForOfIteratorHelper(o, allowArrayLike) { var it; if (typeof Symbol === "undefined" || o[Symbol.iterator] == null) { if (Array.isArray(o) || (it = tabselectvue_type_script_lang_js_unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") { if (it) o = it; var i = 0; var F = function F() {}; return { s: F, n: function n() { if (i >= o.length) return { done: true }; return { done: false, value: o[i++] }; }, e: function e(_e) { throw _e; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var normalCompletion = true, didErr = false, err; return { s: function s() { it = o[Symbol.iterator](); }, n: function n() { var step = it.next(); normalCompletion = step.done; return step; }, e: function e(_e2) { didErr = true; err = _e2; }, f: function f() { try { if (!normalCompletion && it.return != null) it.return(); } finally { if (didErr) throw err; } } }; }

function tabselectvue_type_script_lang_js_unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return tabselectvue_type_script_lang_js_arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return tabselectvue_type_script_lang_js_arrayLikeToArray(o, minLen); }

function tabselectvue_type_script_lang_js_arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) { arr2[i] = arr[i]; } return arr2; }

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//




/* harmony default export */ var tabselectvue_type_script_lang_js_ = ({
  name: 'nut-tabselect',
  props: {
    mainTitle: {
      type: String,
      default: ''
    },
    subTitle: {
      type: String,
      default: ''
    },
    isLockBgScroll: {
      type: Boolean,
      default: true
    },
    defaultContent: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    tabList: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    show: {
      type: Boolean,
      default: false
    },
    multiple: {
      type: Boolean,
      default: false
    },
    max: {
      type: Number,
      default: Infinity
    },
    isDefaultSelected: {
      type: Boolean,
      default: false
    }
  },
  data: function data() {
    return {
      isShow: false,
      level0: 0,
      level1: new Set([0]),
      level2: this.isDefaultSelected ? new Set(['0-0']) : new Set(),
      allChoose: this.getText(0, 0, this.isDefaultSelected ? 0 : null),
      list: [],
      defIndex: 0
    };
  },
  components: (tabselectvue_type_script_lang_js_components = {}, defineProperty_default()(tabselectvue_type_script_lang_js_components, tab.name, tab), defineProperty_default()(tabselectvue_type_script_lang_js_components, popup.name, popup), tabselectvue_type_script_lang_js_components),
  watch: {
    show: function show(val) {
      this.isShow = val;
    },
    isShow: function isShow(val) {
      if (!val) {
        this.$emit('close');
      }
    },
    tabList: {
      handler: function handler(val) {
        this.list = val;
        this.level0 = 0;
        this.level1 = new Set([0]);
        this.level2 = this.isDefaultSelected ? new Set(['0-0']) : new Set();
        this.allChoose = this.getText(0, 0, this.isDefaultSelected ? 0 : null);
        this.emit();
      },
      deep: true
    }
  },
  mounted: function mounted() {
    this.list = this.tabList;
    this.allChoose = this.getText(0, 0, this.isDefaultSelected ? 0 : null);
    this.emit();
  },
  methods: {
    emit: function emit() {
      this.$emit('choose', this.list && this.list[this.level0] && this.list[this.level0].tabTitle || '', this.allChoose && toConsumableArray_default()(this.allChoose) || []);
    },
    getText: function getText(idx, index, sIndex) {
      if (sIndex === null) {
        return null;
      }

      var tab = this.list && this.list[idx] && this.list[idx].children[index] || {};
      var subTit = tab.tabTitle;
      var content = tab.content && tab.content[sIndex] || this.defaultContent[sIndex];
      return new Set([{
        subTit: subTit,
        content: content
      }]);
    },
    tabSwitchOuter: function tabSwitchOuter(index, event) {
      this.defIndex = 0;
      this.level0 = index;
      this.level1 = new Set([0]);
      this.level2 = this.isDefaultSelected ? new Set(['0-0']) : new Set();
      this.allChoose = this.getText(index, 0, this.isDefaultSelected ? 0 : null);
      this.emit();
    },
    tabSwitchInner: function tabSwitchInner(index, event) {
      this.defIndex = index;

      if (!this.multiple) {
        this.level1 = new Set([index]);
      } else {
        this.level1.add(index);
      }
    },
    unChoose: function unChoose(index, sIndex) {
      this.level2.delete(index + '-' + sIndex);
      this.level2 = new Set(this.level2);
    },
    choose: function choose(idx, index, sIndex) {
      var _this = this;

      if (this.multiple && this.isActive(idx, index, sIndex)) {
        this.unChoose(index, sIndex);
        this.getText(idx, index, sIndex).forEach(function (o) {
          var _iterator = tabselectvue_type_script_lang_js_createForOfIteratorHelper(_this.allChoose.values()),
              _step;

          try {
            for (_iterator.s(); !(_step = _iterator.n()).done;) {
              var indexdel = _step.value;

              if (JSON.stringify(o) === JSON.stringify(indexdel)) {
                _this.allChoose.delete(indexdel);
              }
            }
          } catch (err) {
            _iterator.e(err);
          } finally {
            _iterator.f();
          }
        });
        this.emit();
        return;
      }

      if (!this.multiple) {
        this.level2 = new Set([index + '-' + sIndex]);
        this.allChoose = this.getText(idx, index, sIndex);
      } else {
        if (this.max !== Infinity && this.max === this.level2.size) {
          return;
        }

        this.level2 = new Set(toConsumableArray_default()(this.level2.add(index + '-' + sIndex)));

        if (this.allChoose) {
          var _this$allChoose;

          (_this$allChoose = this.allChoose).add.apply(_this$allChoose, toConsumableArray_default()(this.getText(idx, index, sIndex)));
        } else {
          this.allChoose = this.getText(idx, index, sIndex);
        }
      }

      this.emit();
    },
    clickHandler: function clickHandler(event) {
      this.$emit('onOkBtn', event);
      this.isShow = false;
    },
    isActive: function isActive(idx, index, sIndex) {
      if (idx === this.level0 && this.level1.has(index) && this.level2.has(index + '-' + sIndex)) {
        return true;
      }

      return false;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/tabselect/tabselect.vue?vue&type=script&lang=js&
 /* harmony default export */ var tabselect_tabselectvue_type_script_lang_js_ = (tabselectvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/tabselect/tabselect.vue





/* normalize component */

var tabselect_component = normalizeComponent(
  tabselect_tabselectvue_type_script_lang_js_,
  tabselectvue_type_template_id_67057514_render,
  tabselectvue_type_template_id_67057514_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var tabselect = (tabselect_component.exports);
// EXTERNAL MODULE: ./src/packages/tabselect/tabselect.scss
var tabselect_tabselect = __webpack_require__(65);

// CONCATENATED MODULE: ./src/packages/tabselect/index.js



tabselect.install = function (Vue) {
  Vue.component(tabselect.name, tabselect);
};

/* harmony default export */ var packages_tabselect = (tabselect);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/luckdraw/luckdraw.vue?vue&type=template&id=c2015698&
var luckdrawvue_type_template_id_c2015698_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"luckdraw",staticClass:"nut-luckdraw",style:({ width: _vm.luckWidth, height: _vm.luckHeight })},[_c('div',{staticClass:"lucktable",style:({ transform: _vm.rotateAngle, transition: _vm.rotateTransition })},[_c('canvas',{ref:"canvas",attrs:{"id":"canvas"}},[_vm._v("\n      浏览器版本过低\n    ")]),_vm._v(" "),_c('div',{staticClass:"prize"},_vm._l((_vm.prizeList),function(item,index){return _c('div',{key:index,staticClass:"item",style:(_vm.getRotateAngle(index))},[_vm._t("item",null,{"item":item})],2)}),0)])])}
var luckdrawvue_type_template_id_c2015698_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/luckdraw/luckdraw.vue?vue&type=template&id=c2015698&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/luckdraw/luckdraw.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var luckdrawvue_type_script_lang_js_ = ({
  name: 'nut-luckdraw',
  mounted: function mounted() {
    this.init();
  },
  props: {
    luckWidth: {
      required: true
    },
    luckHeight: {
      required: true
    },
    prizeList: {
      required: true
    },
    turnsNumber: {
      default: 5
    },
    styleOpt: {
      default: function _default() {
        return {
          // 每一块扇形的背景色,默认值,可通过父组件来改变
          prizeBgColors: ['rgb(255, 231, 149)', 'rgb(255, 247, 223)', 'rgb(255, 231, 149)', 'rgb(255, 247, 223)', 'rgb(255, 231, 149)', 'rgb(255, 247, 223)'],
          // 每一块扇形的外边框颜色,默认值,可通过父组件来改变
          borderColor: '#ff9800'
        };
      }
    },
    turnsTime: {
      // 转动需要持续的时间(秒)
      default: 5
    }
  },
  watch: {
    prizeList: function prizeList(newVal, oldVal) {
      this.init();
    }
  },
  data: function data() {
    return {
      winningPrize: 0,
      // 开始转动的角度
      startRotateDegree: 0,
      // 设置指针默认指向的位置,现在是默认指向2个扇形之间的边线上
      rotateAngle: 0,
      //`rotate(30deg)`
      rotateTransition: ''
    };
  },
  methods: {
    // 根据index计算每一格要旋转的角度的样式
    getRotateAngle: function getRotateAngle(index) {
      var angle = 360 / this.prizeList.length * index + 180 / this.prizeList.length;
      return {
        transform: "rotate(".concat(angle, "deg)")
      };
    },
    // 初始化圆形转盘canvas
    init: function init() {
      var data = this.styleOpt;
      var prizeNum = this.prizeList.length;
      var prizeBgColors = data.prizeBgColors,
          borderColor = data.borderColor; // 开始绘画

      var canvas = this.$refs.canvas;
      var ctx = canvas.getContext('2d');
      var canvasW = this.$refs.canvas.width = this.$refs.luckdraw.clientWidth; // 画板的高度

      var canvasH = this.$refs.canvas.height = this.$refs.luckdraw.clientHeight; // 画板的宽度
      // translate方法重新映射画布上的 (0,0) 位置

      ctx.translate(0, canvasH); // rotate方法旋转当前的绘图，因为文字是和当前扇形中心线垂直的

      ctx.rotate(-90 * Math.PI / 180); // 圆环的外圆的半径,可用来调整圆盘大小来适应外部盒子的大小

      var outRadius = canvasW / 2 - 1; // 圆环的内圆的半径

      var innerRadius = 0;
      var baseAngle = Math.PI * 2 / prizeNum; // 每个奖项所占角度数

      ctx.clearRect(0, 0, canvasW, canvasH); //去掉背景默认色

      ctx.strokeStyle = borderColor; // 设置画图线的颜色

      for (var index = 0; index < prizeNum; index++) {
        var angle = index * baseAngle;

        if (this.prizeList[index]['prizeColor']) {
          ctx.fillStyle = this.prizeList[index]['prizeColor']; //设置每个扇形区域的颜色,根据每条数据中单独设置的优先
        } else {
          ctx.fillStyle = prizeBgColors[index]; //设置每个扇形区域的颜色
        }

        ctx.beginPath(); //开始绘制
        // 标准圆弧：arc(x,y,radius,startAngle,endAngle,anticlockwise)

        ctx.arc(canvasW * 0.5, canvasH * 0.5, outRadius, angle, angle + baseAngle, false);
        ctx.arc(canvasW * 0.5, canvasH * 0.5, innerRadius, angle + baseAngle, angle, true);
        ctx.stroke();
        ctx.fill();
        ctx.save();
      }
    },
    // 转动起来
    rotate: function rotate(index) {
      var _this = this;

      var turnsTime = this.turnsTime;
      var rotateAngle = this.startRotateDegree + this.turnsNumber * 360 + 360 - (180 / this.prizeList.length + 360 / this.prizeList.length * index) - this.startRotateDegree % 360;
      this.startRotateDegree = rotateAngle;
      this.rotateAngle = "rotate(".concat(rotateAngle, "deg)");
      this.rotateTransition = "transform ".concat(turnsTime, "s cubic-bezier(0.250, 0.460, 0.455, 0.995)");
      setTimeout(function () {
        _this.$emit('end-turns');
      }, turnsTime * 1000 + 500);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/luckdraw/luckdraw.vue?vue&type=script&lang=js&
 /* harmony default export */ var luckdraw_luckdrawvue_type_script_lang_js_ = (luckdrawvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/luckdraw/luckdraw.vue





/* normalize component */

var luckdraw_component = normalizeComponent(
  luckdraw_luckdrawvue_type_script_lang_js_,
  luckdrawvue_type_template_id_c2015698_render,
  luckdrawvue_type_template_id_c2015698_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var luckdraw = (luckdraw_component.exports);
// EXTERNAL MODULE: ./src/packages/luckdraw/luckdraw.scss
var luckdraw_luckdraw = __webpack_require__(66);

// CONCATENATED MODULE: ./src/packages/luckdraw/index.js



luckdraw.install = function (Vue) {
  Vue.component(luckdraw.name, luckdraw);
};

/* harmony default export */ var packages_luckdraw = (luckdraw);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/video/video.vue?vue&type=template&id=62e2def6&
var videovue_type_template_id_62e2def6_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{ref:"videocon",staticClass:"nut-video"},[_c('video',{ref:"video",staticClass:"nut-videoplayer",attrs:{"autoplay":_vm.options.autoplay,"loop":_vm.options.loop,"poster":_vm.options.poster,"controls":_vm.options.controls,"preload":_vm.options.preload},domProps:{"muted":_vm.options.muted},on:{"error":_vm.handleError}},_vm._l((_vm.sources),function(source){return _c('source',{key:source.src,attrs:{"src":source.src,"type":source.type}})}),0),_vm._v(" "),(_vm.showToolbox && !_vm.isDisabled)?_c('div',{ref:"touchMask",staticClass:"playing-mask",on:{"click":_vm.play}}):_vm._e(),_vm._v(" "),(_vm.showToolbox && !_vm.isDisabled)?_c('div',{directives:[{name:"show",rawName:"v-show",value:(!_vm.state.playing),expression:"!state.playing"}],ref:"palyBtn",staticClass:"nut-video-play-btn",on:{"click":_vm.play}}):_vm._e(),_vm._v(" "),_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.showToolbox && !_vm.isDisabled),expression:"showToolbox && !isDisabled"}],staticClass:"nut-video-controller",class:{ 'show-control': !_vm.state.playing, 'hide-control': _vm.state.playing }},[_c('div',{staticClass:"control-play-btn",on:{"click":_vm.play}}),_vm._v(" "),_c('div',{staticClass:"current-time"},[_vm._v(_vm._s(_vm.videoSet.displayTime))]),_vm._v(" "),_c('div',{staticClass:"progress-container"},[_c('div',{ref:"progressBar",staticClass:"progress"},[_c('div',{staticClass:"buffered",style:({ width: ((_vm.videoSet.loaded) + "%") })}),_vm._v(" "),_c('div',{staticClass:"video-ball",style:({ transform: ("translate3d(" + (_vm.videoSet.progress.current) + "px, -50%, 0)") }),on:{"touchmove":function($event){$event.stopPropagation();$event.preventDefault();return _vm.touchSlidMove($event)},"touchstart":function($event){$event.stopPropagation();return _vm.touchSlidSrart($event)},"touchend":function($event){$event.stopPropagation();return _vm.touchSlidEnd($event)}}},[_c('div',{staticClass:"move-handle"})]),_vm._v(" "),_c('div',{ref:"playedBar",staticClass:"played"})])]),_vm._v(" "),_c('div',{staticClass:"duration-time"},[_vm._v(_vm._s(_vm.videoSet.totalTime))]),_vm._v(" "),_c('div',{staticClass:"volume",class:{ muted: _vm.state.isMuted },on:{"click":_vm.handleMuted}}),_vm._v(" "),_c('div',{staticClass:"fullscreen-icon",on:{"click":_vm.fullScreen}})]),_vm._v(" "),_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.state.isError),expression:"state.isError"}],staticClass:"nut-video-error"},[_c('p',{staticClass:"lose"},[_vm._v("视频加载失败")]),_vm._v(" "),_c('p',{staticClass:"retry",on:{"click":_vm.retry}},[_vm._v("点击重试")])])])}
var videovue_type_template_id_62e2def6_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/video/video.vue?vue&type=template&id=62e2def6&

// CONCATENATED MODULE: ./src/utils/throttle.js
/**
 * @desc 函数节流
 * @param func 函数
 * @param wait 延迟执行毫秒数
 * @param type 1 表时间戳版，2 表定时器版
 */
var throttle_throttle = function throttle(func, wait, type) {
  if (type === 1) {
    var previous = 0;
  } else if (type === 2) {
    var timeout;
  }

  return function () {
    var context = this;
    var args = arguments;

    if (type === 1) {
      var now = Date.now();

      if (now - previous > wait) {
        func.apply(context, args);
        previous = now;
      }
    } else if (type === 2) {
      if (!timeout) {
        timeout = setTimeout(function () {
          timeout = null;
          func.apply(context, args);
        }, wait);
      }
    }
  };
};
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/video/video.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/* harmony default export */ var videovue_type_script_lang_js_ = ({
  name: 'nut-video',
  props: {
    sources: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    options: {
      type: Object,
      default: function _default() {
        return {
          autoplay: false,
          //是否自动播放
          volume: 0.5,
          poster: '',
          loop: false,
          controls: true,
          muted: false,
          //是否静音
          disabled: false,
          //禁止操作
          playsinline: false,
          //行内展示
          touchPlay: false,
          preload: ''
        };
      },
      required: true
    },
    model: {
      type: String,
      default: ''
    }
  },
  data: function data() {
    return {
      videoElm: null,
      initial: true,
      //控制封面的显示
      showToolbox: false,
      //控制控制器和标题的显示
      // 视频容器元素
      player: {
        $player: null,
        pos: null
      },
      // progress进度条元素
      progressBar: {
        progressElm: null,
        // 进度条DOM对象
        pos: null
      },
      // video控制显示设置
      videoSet: {
        loaded: 0,
        // 缓存长度
        displayTime: '00:00',
        // 进度时间
        totalTime: '00:00',
        // 总时间
        progress: {
          width: 0,
          // 进度条长度
          current: 0 // 进度条当前位置

        }
      },
      state: {
        controlShow: true,
        vol: 0.5,
        //音量
        currentTime: 0,
        //当前时间
        fullScreen: false,
        playing: false,
        //是否正在播放
        isLoading: false,
        isEnd: false,
        isError: false,
        isMuted: false
      },
      showTouchMask: false
    };
  },
  computed: {
    isDisabled: function isDisabled() {
      return this.options.disabled;
    }
  },
  watch: {
    sources: {
      handler: function handler(newValue, oldValue) {
        var _this = this;

        if (newValue && oldValue && newValue != oldValue) {
          this.$nextTick(function () {
            _this.videoElm.load();
          });
        }
      },
      immediate: true
    },
    options: {
      handler: function handler(val) {
        this.state.isMuted = val.muted ? val.muted : false;
      },
      immediate: true
    } // model: {
    //     handler(val) {
    //         if (val) {
    //             if (val == 'custom') {
    //                 this.state.controlShow = false;
    //                 this.showToolbox = this.options.controls ? true : false
    //             }
    //         } else {
    //             this.showToolbox = false;
    //             this.state.controlShow = this.options.controls ? true : false
    //         }
    //     },
    //     immediate: true
    // }

  },
  mounted: function mounted() {
    this.init();
  },
  methods: {
    init: function init() {
      var _this2 = this;

      this.videoElm = this.$el.getElementsByTagName('video')[0];

      if (this.options.autoplay) {
        this.videoElm.play();
      }

      if (this.options.touchPlay) {
        this.showTouchMask = true;
      }

      if (this.options.playsinline) {
        this.videoElm.setAttribute('playsinline', this.options.playsinline);
        this.videoElm.setAttribute('webkit-playsinline', this.options.playsinline);
        this.videoElm.setAttribute('x5-playsinline', this.options.playsinline);
        this.videoElm.setAttribute('x5-video-player-type', 'h5');
        this.videoElm.setAttribute('x5-video-player-fullscreen', false);
      }

      this.volumeHandle();

      if (this.showToolbox) {
        this.customerInit();
      } else {
        this.videoElm.addEventListener('play', function () {
          _this2.state.playing = true;

          _this2.$emit('play', _this2.videoElm);
        });
        this.videoElm.addEventListener('pause', function () {
          _this2.state.playing = false;

          _this2.$emit('pause', _this2.videoElm);
        });
        this.videoElm.addEventListener('ended', this.playEnded);
        this.videoElm.addEventListener('timeupdate', throttle_throttle(this.getPlayTime, 100, 1));
      }
    },
    customerInit: function customerInit() {
      var $player = this.$el;
      var $progress = this.$el.getElementsByClassName('progress')[0]; // 播放器位置

      this.player.$player = $player;
      this.progressBar.progressElm = $progress; // this.player.pos = $player.getBoundingClientRect();

      this.progressBar.pos = $progress.getBoundingClientRect();
      this.videoSet.progress.width = Math.round($progress.getBoundingClientRect().width);
    },
    play: function play() {
      var _this3 = this;

      if (this.options.autoplay && this.options.disabled) {
        this.state.playing = true; // this.state.controlShow = false

        return false;
      }

      this.state.playing = !this.state.playing;

      if (this.videoElm) {
        // 播放状态
        if (this.state.playing) {
          try {
            this.videoElm.play(); // 监听缓存进度

            this.videoElm.addEventListener('progress', function (e) {
              _this3.getLoadTime();
            }); // 监听播放进度

            this.videoElm.addEventListener('timeupdate', throttle_throttle(this.getPlayTime, 100, 1)); // 监听结束

            this.videoElm.addEventListener('ended', this.playEnded);
            this.$emit('play', this.videoElm);
          } catch (e) {
            // 捕获url异常出现的错误
            this.handleError();
          }
        } // 停止状态
        else {
            this.videoElm.pause();
            this.$emit('pause', this.videoElm);
          }
      }
    },
    // 音量控制
    volumeHandle: function volumeHandle() {
      this.state.vol = this.options.volume;
    },
    // 静音控制
    handleMuted: function handleMuted() {
      this.state.isMuted = !this.state.isMuted;
      this.videoElm.muted = this.state.isMuted;
    },
    playEnded: function playEnded() {
      this.state.playing = false;
      this.state.isEnd = true;
      this.state.controlBtnShow = true;
      this.videoSet.displayTime = '00:00';
      this.videoSet.progress.current = 0;
      this.videoElm.currentTime = 0;
      this.$emit('playend', this.videoElm);
    },
    // 数据加载出错
    handleError: function handleError() {
      // console.log('error')
      this.state.isError = true;
    },
    fullScreen: function fullScreen() {
      if (!this.state.fullScreen) {
        this.state.fullScreen = true;
        this.videoElm.webkitRequestFullScreen();
      } else {
        this.state.fullScreen = false;
        document.webkitCancelFullScreen();
      } // setTimeout(this.initVideo, 200);

    },
    // 获取播放时间
    getPlayTime: function getPlayTime() {
      var percent = this.videoElm.currentTime / this.videoElm.duration;
      this.videoSet.progress.current = Math.round(this.videoSet.progress.width * percent); // 赋值时长

      this.videoSet.totalTime = this.timeFormat(this.videoElm.duration);
      this.videoSet.displayTime = this.timeFormat(this.videoElm.currentTime);
    },
    timeFormat: function timeFormat(t) {
      var h = Math.floor(t / 3600);

      if (h < 10) {
        h = '0' + h;
      }

      var m = Math.floor(t % 3600 / 60);

      if (m < 10) {
        m = '0' + m;
      }

      var s = Math.round(t % 3600 % 60);

      if (s < 10) {
        s = '0' + s;
      }

      var str = '';

      if (h != 0) {
        str = h + ':' + m + ':' + s;
      } else {
        str = m + ':' + s;
      }

      return str;
    },
    // 获取缓存时间
    getLoadTime: function getLoadTime() {
      if (this.videoSet.loaded) this.videoSet.loaded = this.videoElm.buffered.end(0) / this.videoElm.duration * 100;
    },
    getTime: function getTime() {
      var _this4 = this;

      this.videoElm.addEventListener('durationchange', function (e) {// console.log(e);
      });
      this.videoElm.addEventListener('progress', function (e) {
        _this4.videoSet.loaded = (-1 + _this4.videoElm.buffered.end(0) / _this4.videoElm.duration) * 100;
      });
      this.videoSet.len = this.videoElm.duration;
    },
    // 拖动播放进度
    touchSlidSrart: function touchSlidSrart(e) {},
    touchSlidMove: function touchSlidMove(e) {
      var currentX = e.targetTouches[0].pageX;
      var offsetX = currentX - this.progressBar.pos.left; // 边界检测

      if (offsetX <= 0) {
        offsetX = 0;
      }

      if (offsetX >= this.videoSet.progress.width) {
        offsetX = this.videoSet.progress.width;
      }

      this.videoSet.progress.current = offsetX;
      var percent = this.videoSet.progress.current / this.videoSet.progress.width;
      this.videoElm.duration && this.setPlayTime(percent, this.videoElm.duration);
    },
    touchSlidEnd: function touchSlidEnd(e) {
      var currentX = e.changedTouches[0].pageX;
      var offsetX = currentX - this.progressBar.pos.left;
      this.videoSet.progress.current = offsetX; // 这里的offsetX都是正数

      var percent = offsetX / this.videoSet.progress.width;
      this.videoElm.duration && this.setPlayTime(percent, this.videoElm.duration);
    },
    // 设置手动播放时间
    setPlayTime: function setPlayTime(percent, totalTime) {
      this.videoElm.currentTime = Math.floor(percent * totalTime);
    },
    // 点击重新加载
    retry: function retry() {
      // console.log('error');
      this.state.isError = false;
      this.init();
    }
  },
  beforeDestroy: function beforeDestroy() {}
});
// CONCATENATED MODULE: ./src/packages/video/video.vue?vue&type=script&lang=js&
 /* harmony default export */ var video_videovue_type_script_lang_js_ = (videovue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/video/video.vue





/* normalize component */

var video_component = normalizeComponent(
  video_videovue_type_script_lang_js_,
  videovue_type_template_id_62e2def6_render,
  videovue_type_template_id_62e2def6_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var video = (video_component.exports);
// EXTERNAL MODULE: ./src/packages/video/video.scss
var video_video = __webpack_require__(67);

// CONCATENATED MODULE: ./src/packages/video/index.js



video.install = function (Vue) {
  Vue.component(video.name, video);
};

/* harmony default export */ var packages_video = (video);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/signature/signature.vue?vue&type=template&id=2c8bb468&
var signaturevue_type_template_id_2c8bb468_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-signature",class:_vm.customClass},[_c('div',{ref:"wrap",staticClass:"nut-signature-inner"},[(_vm.isCanvasSupported)?_c('canvas',{ref:"canvas",attrs:{"height":_vm.canvasHeight,"width":_vm.canvasWidth}}):_c('p',{staticClass:"nut-signature-unsopport"},[_vm._v(_vm._s(_vm.unSupportTpl))])]),_vm._v(" "),_vm._t("default"),_vm._v(" "),_c('nut-button',{attrs:{"type":"red","shape":"circle","small":""},on:{"click":function($event){return _vm.clear()}}},[_vm._v("重签")]),_vm._v(" "),_c('nut-button',{attrs:{"shape":"circle","small":""},on:{"click":function($event){return _vm.confirm()}}},[_vm._v("确认")])],2)}
var signaturevue_type_template_id_2c8bb468_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/signature/signature.vue?vue&type=template&id=2c8bb468&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/signature/signature.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var signaturevue_type_script_lang_js_ = ({
  name: 'nut-signature',
  props: {
    customClass: {
      type: String,
      default: ''
    },
    lineWidth: {
      type: Number,
      default: 2
    },
    strokeStyle: {
      type: String,
      default: '#000'
    },
    type: {
      type: String,
      default: 'png'
    },
    unSupportTpl: {
      type: String,
      default: '对不起，当前浏览器不支持Canvas，无法使用本控件！'
    }
  },
  data: function data() {
    return {
      canvasHeight: 0,
      canvasWidth: 0,
      ctx: null,
      isSupportTouch: 'ontouchstart' in window,
      events: 'ontouchstart' in window ? ['touchstart', 'touchmove', 'touchend', 'touchleave'] : ['mousedown', 'mousemove', 'mouseup', 'mouseleave']
    };
  },
  components: {
    'nut-button': button_button
  },
  computed: {
    isCanvasSupported: function isCanvasSupported() {
      var elem = document.createElement('canvas');
      return !!(elem.getContext && elem.getContext('2d'));
    }
  },
  methods: {
    addEvent: function addEvent() {
      this.startEventHandler = this.startEventHandler.bind(this), this.$refs.canvas.addEventListener(this.events[0], this.startEventHandler, false);
    },
    startEventHandler: function startEventHandler(event) {
      event.preventDefault();
      this.ctx.beginPath();
      this.ctx.lineWidth = this.lineWidth;
      this.ctx.strokeStyle = this.strokeStyle;
      this.moveEventHandler = this.moveEventHandler.bind(this), this.leaveEventHandler = this.leaveEventHandler.bind(this), this.endEventHandler = this.endEventHandler.bind(this);
      this.$refs.canvas.addEventListener(this.events[1], this.moveEventHandler, false);
      this.$refs.canvas.addEventListener(this.events[2], this.endEventHandler, false);
      this.$refs.canvas.addEventListener(this.events[3], this.leaveEventHandler, false);
    },
    moveEventHandler: function moveEventHandler(event) {
      event.preventDefault();
      var evt = this.isSupportTouch ? event.touches[0] : event;
      var coverPos = this.$refs.canvas.getBoundingClientRect();
      var mouseX = evt.clientX - coverPos.left;
      var mouseY = evt.clientY - coverPos.top;
      this.ctx.lineTo(mouseX, mouseY);
      this.ctx.stroke();
    },
    endEventHandler: function endEventHandler(event) {
      event.preventDefault();
      this.$refs.canvas.removeEventListener(this.events[1], this.moveEventHandler, false);
      this.$refs.canvas.removeEventListener(this.events[2], this.endEventHandler, false);
    },
    leaveEventHandler: function leaveEventHandler(event) {
      event.preventDefault();
      this.$refs.canvas.removeEventListener(this.events[1], this.moveEventHandler, false);
      this.$refs.canvas.removeEventListener(this.events[2], this.endEventHandler, false);
    },
    clear: function clear(isUnEmit) {
      this.$refs.canvas.addEventListener(this.events[2], this.endEventHandler, false);
      this.ctx.clearRect(0, 0, this.canvasWidth, this.canvasHeight);
      this.ctx.closePath();

      if (!isUnEmit) {
        this.$emit('clear');
      }
    },
    confirm: function confirm() {
      this.onSave(this.$refs.canvas);
    },
    onSave: function onSave(canvas) {
      var dataurl;

      switch (this.type) {
        case 'png':
          dataurl = canvas.toDataURL('image/png');
          break;

        case 'jpg':
          dataurl = canvas.toDataURL('image/jpeg', 0.8);
          break;
      }

      this.clear(true);
      this.$emit('confirm', canvas, dataurl);
    }
  },
  mounted: function mounted() {
    if (this.isCanvasSupported) {
      this.ctx = this.$refs.canvas.getContext('2d');
      this.canvasWidth = this.$refs.wrap.offsetWidth;
      this.canvasHeight = this.$refs.wrap.offsetHeight, this.addEvent();
    }
  }
});
// CONCATENATED MODULE: ./src/packages/signature/signature.vue?vue&type=script&lang=js&
 /* harmony default export */ var signature_signaturevue_type_script_lang_js_ = (signaturevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/signature/signature.vue





/* normalize component */

var signature_component = normalizeComponent(
  signature_signaturevue_type_script_lang_js_,
  signaturevue_type_template_id_2c8bb468_render,
  signaturevue_type_template_id_2c8bb468_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var signature = (signature_component.exports);
// EXTERNAL MODULE: ./src/packages/signature/signature.scss
var signature_signature = __webpack_require__(68);

// CONCATENATED MODULE: ./src/packages/signature/index.js



signature.install = function (Vue) {
  Vue.component(signature.name, signature);
};

/* harmony default export */ var packages_signature = (signature);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/circleprogress/circleprogress.vue?vue&type=template&id=8eb0343e&
var circleprogressvue_type_template_id_8eb0343e_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-circleprogress",style:({ height: _vm.option.size + 'px', width: _vm.option.size + 'px' })},[_c('svg',{attrs:{"height":_vm.option.size,"width":_vm.option.size,"x-mlns":"http://www.w3.org/200/svg"}},[_c('circle',{attrs:{"r":_vm.option.radius,"cx":_vm.option.cx,"cy":_vm.option.cy,"stroke":_vm.option.backColor,"stroke-width":_vm.option.strokeOutWidth,"fill":"none"}}),_vm._v(" "),_c('circle',{staticStyle:{"transition":"stroke-dasharray 0.6s ease 0s, stroke 0.6s ease 0s"},attrs:{"r":_vm.option.radius,"cx":_vm.option.cx,"cy":_vm.option.cy,"stroke":_vm.option.progressColor,"stroke-dasharray":_vm.arcLength,"stroke-width":_vm.strokeInnerWidth,"fill":"none","transform":"rotate(-90)","transform-origin":"center","stroke-linecap":"round"}})]),_vm._v(" "),_c('div',{staticClass:"nut-circleprogress-content"},[(!_vm.isAuto)?[_vm._t("default",[_vm._v(_vm._s(_vm.progress)+"%")])]:[_vm._t("default")]],2)])}
var circleprogressvue_type_template_id_8eb0343e_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/circleprogress/circleprogress.vue?vue&type=template&id=8eb0343e&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/circleprogress/circleprogress.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var circleprogressvue_type_script_lang_js_ = ({
  name: 'nut-circleprogress',
  props: {
    progress: {
      type: [Number, String],
      required: true
    },
    strokeInnerWidth: {
      type: [Number, String],
      default: 10
    },
    isAuto: {
      tyep: Boolean,
      default: false
    },
    progressOption: {
      type: Object,
      default: function _default() {}
    }
  },
  data: function data() {
    return {};
  },
  computed: {
    arcLength: function arcLength() {
      var circleLength = Math.floor(2 * Math.PI * this.option.radius);
      var progressLength = this.progress / 100 * circleLength; // console.log(this.progress,progressLength)

      return "".concat(progressLength, ",").concat(circleLength);
    },
    // :stroke-dashoffset="dashOffset"
    // dashOffset() {
    //   // 偏移初始值为dashArray长度，随着percent增大逐渐减小
    //   return (1 - this.progress) *Math.floor(2 * Math.PI * this.option.radius);
    // },
    option: function option() {
      // 所有进度条的可配置项
      var baseOption = {
        radius: 50,
        strokeOutWidth: 10,
        backColor: '#d9d9d9',
        progressColor: 'red'
      };

      extends_default()(baseOption, this.progressOption); // 圆心位置自动生成


      baseOption.cy = baseOption.cx = baseOption.radius + baseOption.strokeOutWidth;
      baseOption.size = (baseOption.radius + baseOption.strokeOutWidth) * 2;
      return baseOption;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/circleprogress/circleprogress.vue?vue&type=script&lang=js&
 /* harmony default export */ var circleprogress_circleprogressvue_type_script_lang_js_ = (circleprogressvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/circleprogress/circleprogress.vue





/* normalize component */

var circleprogress_component = normalizeComponent(
  circleprogress_circleprogressvue_type_script_lang_js_,
  circleprogressvue_type_template_id_8eb0343e_render,
  circleprogressvue_type_template_id_8eb0343e_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var circleprogress = (circleprogress_component.exports);
// EXTERNAL MODULE: ./src/packages/circleprogress/circleprogress.scss
var circleprogress_circleprogress = __webpack_require__(69);

// CONCATENATED MODULE: ./src/packages/circleprogress/index.js



circleprogress.install = function (Vue) {
  Vue.component(circleprogress.name, circleprogress);
};

/* harmony default export */ var packages_circleprogress = (circleprogress);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/timeline/timeline.vue?vue&type=template&id=7c35a686&
var timelinevue_type_template_id_7c35a686_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-timeline"},[_vm._t("default")],2)}
var timelinevue_type_template_id_7c35a686_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/timeline/timeline.vue?vue&type=template&id=7c35a686&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/timeline/timeline.vue?vue&type=script&lang=js&
//
//
//
//
//
/* harmony default export */ var timelinevue_type_script_lang_js_ = ({
  name: 'nut-timeline',
  props: {},
  data: function data() {
    return {};
  },
  mounted: function mounted() {},
  methods: {}
});
// CONCATENATED MODULE: ./src/packages/timeline/timeline.vue?vue&type=script&lang=js&
 /* harmony default export */ var timeline_timelinevue_type_script_lang_js_ = (timelinevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/timeline/timeline.vue





/* normalize component */

var timeline_component = normalizeComponent(
  timeline_timelinevue_type_script_lang_js_,
  timelinevue_type_template_id_7c35a686_render,
  timelinevue_type_template_id_7c35a686_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var timeline = (timeline_component.exports);
// EXTERNAL MODULE: ./src/packages/timeline/timeline.scss
var timeline_timeline = __webpack_require__(70);

// CONCATENATED MODULE: ./src/packages/timeline/index.js



timeline.install = function (Vue) {
  Vue.component(timeline.name, timeline);
};

/* harmony default export */ var packages_timeline = (timeline);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/timelineitem/timelineitem.vue?vue&type=template&id=28c462e8&
var timelineitemvue_type_template_id_28c462e8_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-timelineitem left-border"},[_c('div',{staticClass:"timelineitem-list-box"},[_c('div',{class:['timelineitem-list']},[_c('div',{staticClass:"timelineitem-left"},[_c('div',{staticClass:"timelineitem-point"},[(!_vm.isCustomPoint)?_c('div',{class:[_vm.pointClass, 'point-icon'],style:(_vm.pointStyle)}):_c('div',{staticClass:"custom-icon"},[_vm._t("dot")],2)]),_vm._v(" "),_c('div',{staticClass:"timelineitem-line"})]),_vm._v(" "),_c('div',{staticClass:"timelineitem-right"},[(_vm.isShowTitle)?_c('div',{staticClass:"timelineitem-title"},[_c('div',{staticClass:"time"},[_vm._t("title")],2)]):_vm._e(),_vm._v(" "),_c('div',{staticClass:"timelineitem-content"},[_vm._t("default")],2)])])])])}
var timelineitemvue_type_template_id_28c462e8_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/timelineitem/timelineitem.vue?vue&type=template&id=28c462e8&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/timelineitem/timelineitem.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var timelineitemvue_type_script_lang_js_ = ({
  name: 'nut-timelineitem',
  props: {
    // 轴点的样式：circle 圆  hollow 空心
    pointType: {
      type: String,
      default: 'circle'
    },
    // 轴点的颜色
    pointColor: {
      type: String,
      default: '#fa2e05'
    }
  },
  data: function data() {
    return {
      isCustomPoint: false //是否自定义轴点

    };
  },
  computed: {
    pointClass: function pointClass() {
      return this.pointType + '-icon';
    },
    pointStyle: function pointStyle() {
      return {
        borderColor: this.pointColor,
        background: this.pointType == 'circle' ? this.pointColor : 'transparent'
      };
    },
    isShowTitle: function isShowTitle() {
      return this.$slots.title ? true : false;
    }
  },
  mounted: function mounted() {
    this.isCustomPoint = this.$slots.dot ? true : false;
  },
  methods: {}
});
// CONCATENATED MODULE: ./src/packages/timelineitem/timelineitem.vue?vue&type=script&lang=js&
 /* harmony default export */ var timelineitem_timelineitemvue_type_script_lang_js_ = (timelineitemvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/timelineitem/timelineitem.vue





/* normalize component */

var timelineitem_component = normalizeComponent(
  timelineitem_timelineitemvue_type_script_lang_js_,
  timelineitemvue_type_template_id_28c462e8_render,
  timelineitemvue_type_template_id_28c462e8_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var timelineitem = (timelineitem_component.exports);
// EXTERNAL MODULE: ./src/packages/timelineitem/timelineitem.scss
var timelineitem_timelineitem = __webpack_require__(71);

// CONCATENATED MODULE: ./src/packages/timelineitem/index.js



timelineitem.install = function (Vue) {
  Vue.component(timelineitem.name, timelineitem);
};

/* harmony default export */ var packages_timelineitem = (timelineitem);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/sidenavbar/sidenavbar.vue?vue&type=template&id=2d390796&
var sidenavbarvue_type_template_id_2d390796_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-sidenavbar"},[_c('div',{staticClass:"sidenavbar-content"},[_c('div',{ref:"list",staticClass:"sidenavbar-list"},[_vm._t("default")],2)])])}
var sidenavbarvue_type_template_id_2d390796_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/sidenavbar/sidenavbar.vue?vue&type=template&id=2d390796&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/sidenavbar/sidenavbar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
/* harmony default export */ var sidenavbarvue_type_script_lang_js_ = ({
  name: 'nut-sidenavbar',
  props: {
    offset: {
      type: [String, Number],
      default: 15
    }
  },
  mounted: function mounted() {
    this.handleSlots();
    this.observer = new MutationObserver(function (mutations) {
      this.count = 1;
      this.handleSlots();
    }.bind(this));
    this.observer.observe(this.$refs.list, {
      attributes: false,
      childList: true,
      characterData: false,
      subtree: false
    });
  },
  data: function data() {
    return {
      count: 1,
      observer: null
    };
  },
  methods: {
    handleSlots: function handleSlots() {
      var slots = this.$slots.default;

      if (slots) {
        slots = slots.filter(function (item) {
          return item.elm.nodeType !== 3;
        }).map(function (item) {
          return item.elm;
        });
        this.setPaddingLeft(slots);
      }
    },
    setPaddingLeft: function setPaddingLeft(nodeList) {
      var level = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 1;

      for (var i = 0; i < nodeList.length; i++) {
        var item = nodeList[i];
        item.children[0].style.paddingLeft = this.offset * level + 'px';

        if (!item.className.includes('nut-sidenavbaritem')) {
          this.setPaddingLeft(Array.from(item.children[1].children), ++this.count);
        }
      }

      this.count--;
    }
  }
});
// CONCATENATED MODULE: ./src/packages/sidenavbar/sidenavbar.vue?vue&type=script&lang=js&
 /* harmony default export */ var sidenavbar_sidenavbarvue_type_script_lang_js_ = (sidenavbarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/sidenavbar/sidenavbar.vue





/* normalize component */

var sidenavbar_component = normalizeComponent(
  sidenavbar_sidenavbarvue_type_script_lang_js_,
  sidenavbarvue_type_template_id_2d390796_render,
  sidenavbarvue_type_template_id_2d390796_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var sidenavbar = (sidenavbar_component.exports);
// EXTERNAL MODULE: ./src/packages/sidenavbar/sidenavbar.scss
var sidenavbar_sidenavbar = __webpack_require__(72);

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/subsidenavbar/subsidenavbar.vue?vue&type=template&id=8d8f4c46&
var subsidenavbarvue_type_template_id_8d8f4c46_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-subsidenavbar sidenavbar-item",attrs:{"ikey":_vm.ikey}},[_c('div',{staticClass:"item-title",on:{"click":function($event){$event.stopPropagation();return _vm.handleClick($event)}}},[_c('a',{staticClass:"sidenavbar-title",attrs:{"href":"javascript:;"}},[_vm._v(_vm._s(_vm.title))]),_vm._v(" "),_c('span',{staticClass:"sidenavbar-icon"},[_c('nut-icon',{class:_vm.direction,attrs:{"type":"down"}})],1)]),_vm._v(" "),_c('div',{staticClass:"sub-sidenavbar-list",class:!_vm.direction ? 'nutFadeIn' : 'nutFadeOut',style:({ height: !_vm.direction ? 'auto' : 0 })},[_vm._t("default")],2)])}
var subsidenavbarvue_type_template_id_8d8f4c46_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/subsidenavbar/subsidenavbar.vue?vue&type=template&id=8d8f4c46&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/subsidenavbar/subsidenavbar.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var subsidenavbarvue_type_script_lang_js_ = ({
  name: 'nut-subsidenavbar',
  props: {
    title: {
      type: String,
      default: ''
    },
    ikey: {
      type: [String, Number],
      default: ''
    },
    open: {
      type: Boolean,
      default: true
    }
  },
  data: function data() {
    return {
      direction: ''
    };
  },
  mounted: function mounted() {
    this.direction = this.open ? '' : 'up';
  },
  methods: {
    handleClick: function handleClick() {
      this.$emit('titleClick');
      this.direction = !this.direction ? 'up' : '';
    }
  }
});
// CONCATENATED MODULE: ./src/packages/subsidenavbar/subsidenavbar.vue?vue&type=script&lang=js&
 /* harmony default export */ var subsidenavbar_subsidenavbarvue_type_script_lang_js_ = (subsidenavbarvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/subsidenavbar/subsidenavbar.vue





/* normalize component */

var subsidenavbar_component = normalizeComponent(
  subsidenavbar_subsidenavbarvue_type_script_lang_js_,
  subsidenavbarvue_type_template_id_8d8f4c46_render,
  subsidenavbarvue_type_template_id_8d8f4c46_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var subsidenavbar = (subsidenavbar_component.exports);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/sidenavbaritem/sidenavbaritem.vue?vue&type=template&id=a0fb824e&
var sidenavbaritemvue_type_template_id_a0fb824e_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-sidenavbaritem",attrs:{"ikey":_vm.ikey},on:{"click":function($event){$event.stopPropagation();return _vm.handleClick($event)}}},[_c('a',{staticClass:"item-title",attrs:{"href":"javascript:;"}},[_vm._v("\n    "+_vm._s(_vm.title)+"\n  ")])])}
var sidenavbaritemvue_type_template_id_a0fb824e_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/sidenavbaritem/sidenavbaritem.vue?vue&type=template&id=a0fb824e&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/sidenavbaritem/sidenavbaritem.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
/* harmony default export */ var sidenavbaritemvue_type_script_lang_js_ = ({
  name: 'nut-sidenavbaritem',
  props: {
    title: {
      type: String,
      default: ''
    },
    ikey: {
      type: String,
      default: ''
    }
  },
  methods: {
    handleClick: function handleClick() {
      this.$emit('click');
    }
  }
});
// CONCATENATED MODULE: ./src/packages/sidenavbaritem/sidenavbaritem.vue?vue&type=script&lang=js&
 /* harmony default export */ var sidenavbaritem_sidenavbaritemvue_type_script_lang_js_ = (sidenavbaritemvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/sidenavbaritem/sidenavbaritem.vue





/* normalize component */

var sidenavbaritem_component = normalizeComponent(
  sidenavbaritem_sidenavbaritemvue_type_script_lang_js_,
  sidenavbaritemvue_type_template_id_a0fb824e_render,
  sidenavbaritemvue_type_template_id_a0fb824e_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var sidenavbaritem = (sidenavbaritem_component.exports);
// CONCATENATED MODULE: ./src/packages/sidenavbar/index.js






sidenavbar.install = function (Vue) {
  Vue.component(sidenavbar.name, sidenavbar);
  Vue.component(subsidenavbar.name, subsidenavbar);
  Vue.component(sidenavbaritem.name, sidenavbaritem);
  Vue.component(icon.name, icon);
};

/* harmony default export */ var packages_sidenavbar = (sidenavbar);
// EXTERNAL MODULE: ./src/packages/subsidenavbar/subsidenavbar.scss
var subsidenavbar_subsidenavbar = __webpack_require__(73);

// CONCATENATED MODULE: ./src/packages/subsidenavbar/index.js



subsidenavbar.install = function (Vue) {
  Vue.component(subsidenavbar.name, subsidenavbar);
};

/* harmony default export */ var packages_subsidenavbar = (subsidenavbar);
// EXTERNAL MODULE: ./src/packages/sidenavbaritem/sidenavbaritem.scss
var sidenavbaritem_sidenavbaritem = __webpack_require__(74);

// CONCATENATED MODULE: ./src/packages/sidenavbaritem/index.js



sidenavbaritem.install = function (Vue) {
  Vue.component(sidenavbaritem.name, sidenavbaritem);
};

/* harmony default export */ var packages_sidenavbaritem = (sidenavbaritem);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/drag/drag.vue?vue&type=template&id=04510862&
var dragvue_type_template_id_04510862_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-drag",on:{"touchstart":function($event){return _vm.touchStart($event)}}},[_vm._t("default")],2)}
var dragvue_type_template_id_04510862_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/drag/drag.vue?vue&type=template&id=04510862&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/drag/drag.vue?vue&type=script&lang=js&
//
//
//
//
//

/**
 * @module drag
 * @description 拖拽组件，用于页面中需要拖拽的元素
 * @vue-prop {Boolean} [attract=false] - 拖拽元素是否需要自动吸边
 * @vue-prop {String} [direction='all'] - 拖拽元素的拖拽方向
 * @vue-prop {Number | String} [zIndex=11] - 拖拽元素的堆叠顺序
 * @vue-prop {Object} [boundary={top: 0,left: 0,right: 0,bottom: 0}] - 拖拽元素的拖拽边界
 * @vue-data {Number} elWidth 拖拽元素的宽度
 * @vue-data {Number} elHeight 拖拽元素的高度
 * @vue-data {Number} screenWidth 屏幕的宽度
 * @vue-data {Number} screenHeight 屏幕的高度
 * @vue-data {Number} startTop 拖拽元素距离顶部的距离
 * @vue-data {Number} startLeft 拖拽元素距离左侧的距离
 * @vue-data {Object} position 鼠标点击的位置，包含距离x轴和y轴的距离
 */

/* harmony default export */ var dragvue_type_script_lang_js_ = ({
  name: 'nut-drag',
  props: {
    attract: {
      type: Boolean,
      default: false
    },
    direction: {
      type: String,
      default: 'all'
    },
    zIndex: {
      type: [Number, String],
      default: 11
    },
    boundary: {
      type: Object,
      default: function _default() {
        return {
          top: 0,
          left: 0,
          right: 0,
          bottom: 0
        };
      }
    }
  },
  data: function data() {
    return {
      elWidth: 0,
      elHeight: 0,
      screenWidth: 0,
      screenHeight: 0,
      startTop: 0,
      startLeft: 0,
      position: {
        x: 0,
        y: 0
      }
    };
  },
  methods: {
    /**
     * 获取拖拽元素的属性和屏幕的宽高，初始化拖拽元素的位置
     */
    getElementInfo: function getElementInfo() {
      var el = this.$el;
      var domElem = document.documentElement;
      this.elWidth = el.offsetWidth;
      this.elHeight = el.offsetHeight;
      this.screenWidth = domElem.clientWidth;
      this.screenHeight = domElem.clientHeight;
      el.style.zIndex = this.zIndex;

      if (this.boundary.left && !el.style.left) {
        el.style.left = this.boundary.left + 'px';
      } else if (this.boundary.right && !el.style.right) {
        el.style.right = this.boundary.right + 'px';
      }

      if (this.boundary.top && !el.style.top) {
        el.style.top = this.boundary.top + 'px';
      } else if (this.boundary.bottom && !el.style.bottom) {
        el.style.bottom = this.boundary.bottom + 'px';
      }
    },
    touchStart: function touchStart(e) {
      var target = e.currentTarget;
      this.startTop = target.offsetTop; // 元素距离顶部的距离

      this.startLeft = target.offsetLeft; // 元素距离左侧的距离

      this.position.x = e.touches[0].clientX; // 鼠标点击的x轴的距离

      this.position.y = e.touches[0].clientY; // 鼠标点击的y轴的距离

      this.$el.addEventListener('touchmove', this.touchMove, false);
      this.$el.addEventListener('touchend', this.touchEnd, false);
    },
    touchMove: function touchMove(e) {
      e.preventDefault();
      var target = e.currentTarget;

      if (e.targetTouches.length == 1) {
        var touch = e.targetTouches[0];
        this.nx = touch.clientX - this.position.x;
        this.ny = touch.clientY - this.position.y;
        this.xPum = this.startLeft + this.nx;
        this.yPum = this.startTop + this.ny;
        var rightLocation = this.screenWidth - this.elWidth - this.boundary.right; // 限制左右拖拽边界

        if (Math.abs(this.xPum) > rightLocation) {
          this.xPum = rightLocation;
        } else if (this.xPum <= this.boundary.left) {
          this.xPum = this.boundary.left;
        } // 限制上下拖拽边界


        if (this.yPum < this.boundary.top) {
          this.yPum = this.boundary.top;
        } else if (this.yPum > this.screenHeight - this.elHeight - this.boundary.bottom) {
          this.yPum = this.screenHeight - this.elHeight - this.boundary.bottom;
        }

        if (this.direction != 'y') {
          target.style.left = this.xPum + 'px';
        }

        if (this.direction != 'x') {
          target.style.top = this.yPum + 'px';
        }
      }
    },
    touchEnd: function touchEnd(e) {
      var target = e.currentTarget;
      var touch = e.changedTouches[0];
      var currX = touch.clientX;
      var rightLocation = this.screenWidth - this.elWidth - this.boundary.right;

      if (currX > rightLocation) {
        currX = rightLocation; // console.log('往右划出边界');
      } else if (currX < this.boundary.left) {
        currX = this.boundary.left; // console.log('往左划出边界');
      } else {
        currX = currX < this.screenWidth / 2 ? this.boundary.left : rightLocation; // console.log('在边界内滑动');
      }

      if (this.direction != 'y' && this.attract) {
        if (currX < this.screenWidth / 2) {
          this.goLeft(target);
        } else {
          this.goRight(target, rightLocation);
        }
      }

      if (this.direction != 'x') {
        target.style.top = this.yPum + 'px';
      }
    },
    goLeft: function goLeft(target) {
      var _this = this;

      if (this.boundary.left) {
        if (target.style.left.split('px')[0] > this.boundary.left) {
          target.style.left = target.style.left.split('px')[0] - 10 + 'px';
          raf(function () {
            _this.goLeft(target);
          });
        } else {
          target.style.left = "".concat(this.boundary.left, "px");
        }
      } else {
        if (target.style.left.split('px')[0] > 10) {
          target.style.left = target.style.left.split('px')[0] - 10 + 'px';
          raf(function () {
            _this.goLeft(target);
          });
        } else {
          target.style.left = '0px';
        }
      }
    },
    goRight: function goRight(target, rightLocation) {
      var _this2 = this;

      if (rightLocation - parseInt(target.style.left.split('px')[0]) > 10) {
        target.style.left = parseInt(target.style.left.split('px')[0]) + 10 + 'px';
        raf(function () {
          _this2.goRight(target, rightLocation);
        });
      } else {
        target.style.left = rightLocation + 'px';
      }
    }
  },
  mounted: function mounted() {
    this.getElementInfo();
  },
  activated: function activated() {
    if (this.keepAlive) {
      this.keepAlive = false;
    }
  },
  deactivated: function deactivated() {
    this.keepAlive = true;
    this.$el.removeEventListener('touchmove', this.handleScroll, false);
    this.$el.removeEventListener('touchend', this.handleScroll, false);
  },
  destroyed: function destroyed() {
    this.$el.removeEventListener('touchmove', this.handleScroll, false);
    this.$el.removeEventListener('touchend', this.handleScroll, false);
  }
});
// CONCATENATED MODULE: ./src/packages/drag/drag.vue?vue&type=script&lang=js&
 /* harmony default export */ var drag_dragvue_type_script_lang_js_ = (dragvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/drag/drag.vue





/* normalize component */

var drag_component = normalizeComponent(
  drag_dragvue_type_script_lang_js_,
  dragvue_type_template_id_04510862_render,
  dragvue_type_template_id_04510862_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var drag = (drag_component.exports);
// EXTERNAL MODULE: ./src/packages/drag/drag.scss
var drag_drag = __webpack_require__(75);

// CONCATENATED MODULE: ./src/packages/drag/index.js



drag.install = function (Vue) {
  Vue.component(drag.name, drag);
};

/* harmony default export */ var packages_drag = (drag);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/address/address.vue?vue&type=template&id=e821993a&
var addressvue_type_template_id_e821993a_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-address"},[_c('nut-popup',{staticClass:"choose-address",attrs:{"round":"","position":"bottom"},on:{"close":_vm.close,"click-overlay":_vm.clickOverlay,"open":function($event){_vm.closeWay = 'self'}},model:{value:(_vm.showPopup),callback:function ($$v) {_vm.showPopup=$$v},expression:"showPopup"}},[_c('div',{staticClass:"title"},[(_vm.showModule == 'custom' && _vm.type == 'exist' && _vm.backBtnIcon)?_c('span',{staticClass:"arrow",on:{"click":_vm.switchModule}},[_c('nut-icon',{attrs:{"type":"self","url":_vm.backBtnIcon}})],1):_c('span',{staticClass:"arrow"}),_vm._v(" "),(_vm.type == 'custom')?_c('span',[_vm._v(_vm._s(_vm.customAddressTitle))]):_vm._e(),_vm._v(" "),(_vm.type == 'exist')?_c('span',[_vm._v(_vm._s(_vm.existAddressTitle))]):_vm._e(),_vm._v(" "),_c('span',{on:{"click":function($event){return _vm.handClose('cross')}}},[(_vm.closeBtnIcon)?_c('nut-icon',{attrs:{"size":"18px","type":"self","url":_vm.closeBtnIcon}}):_vm._e()],1)]),_vm._v(" "),(_vm.showModule == 'custom')?_c('div',{staticClass:"custom-address"},[_c('div',{staticClass:"region-tab"},[_vm._l((_vm.selectedRegion),function(item,key,index){return _c('div',{key:index,ref:'tab-item-' + key,refInFor:true,staticClass:"tab-item",class:[index == _vm.tabIndex ? 'active' : ''],on:{"click":function($event){return _vm.changeRegionTab(item, key, index)}}},[_c('span',[_vm._v(_vm._s(_vm.getTabName(item, index)))])])}),_vm._v(" "),_c('span',{ref:"regionLine",staticClass:"region-tab-line"})],2),_vm._v(" "),_c('div',{staticClass:"region-con"},[_c('ul',{staticClass:"region-group"},_vm._l((_vm.regionList[_vm.tabName[_vm.tabIndex]]),function(item,index){return _c('li',{key:index,staticClass:"region-item",class:[_vm.selectedRegion[_vm.tabName[_vm.tabIndex]].id == item.id ? 'active' : ''],on:{"click":function($event){return _vm.nextAreaList(item)}}},[(_vm.selectedRegion[_vm.tabName[_vm.tabIndex]].id == item.id)?_c('nut-icon',{attrs:{"type":"self","url":__webpack_require__(19)}}):_vm._e(),_vm._v(_vm._s(item.name))],1)}),0)])]):_vm._e(),_vm._v(" "),(_vm.showModule == 'exist')?_c('div',{staticClass:"exist-address"},[_c('div',{staticClass:"exist-address-group"},[_c('ul',{staticClass:"exist-ul"},_vm._l((_vm.existAddress),function(item,index){return _c('li',{key:index,staticClass:"exist-item",class:[item.selectedAddress ? 'active' : ''],on:{"click":function($event){return _vm.selectedExist(item)}}},[_c('nut-icon',{attrs:{"type":"self","url":item.selectedAddress ? _vm.selectedIcon : _vm.defaultIcon}}),_vm._v(" "),_c('span',[_vm._v(_vm._s(item.provinceName + item.cityName + item.countyName + item.townName + item.addressDetail))])],1)}),0)]),_vm._v(" "),(_vm.isShowCustomAddress && _vm.showModule == 'exist')?_c('div',{staticClass:"choose-other",on:{"click":_vm.switchModule}},[_c('div',{staticClass:"btn"},[_vm._v(_vm._s(_vm.customAndExistTitle))])]):_vm._e()]):_vm._e()])],1)}
var addressvue_type_template_id_e821993a_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/address/address.vue?vue&type=template&id=e821993a&

// CONCATENATED MODULE: ./node_modules/gsap/gsap-core.js
function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inheritsLoose(subClass, superClass) { subClass.prototype = Object.create(superClass.prototype); subClass.prototype.constructor = subClass; subClass.__proto__ = superClass; }

/*!
 * GSAP 3.5.1
 * https://greensock.com
 *
 * @license Copyright 2008-2020, GreenSock. All rights reserved.
 * Subject to the terms at https://greensock.com/standard-license or for
 * Club GreenSock members, the agreement issued with that membership.
 * @author: Jack Doyle, jack@greensock.com
*/

/* eslint-disable */
var _config = {
  autoSleep: 120,
  force3D: "auto",
  nullTargetWarn: 1,
  units: {
    lineHeight: ""
  }
},
    _defaults = {
  duration: .5,
  overwrite: false,
  delay: 0
},
    _bigNum = 1e8,
    _tinyNum = 1 / _bigNum,
    _2PI = Math.PI * 2,
    _HALF_PI = _2PI / 4,
    _gsID = 0,
    _sqrt = Math.sqrt,
    _cos = Math.cos,
    _sin = Math.sin,
    _isString = function _isString(value) {
  return typeof value === "string";
},
    _isFunction = function _isFunction(value) {
  return typeof value === "function";
},
    _isNumber = function _isNumber(value) {
  return typeof value === "number";
},
    _isUndefined = function _isUndefined(value) {
  return typeof value === "undefined";
},
    _isObject = function _isObject(value) {
  return typeof value === "object";
},
    _isNotFalse = function _isNotFalse(value) {
  return value !== false;
},
    _windowExists = function _windowExists() {
  return typeof window !== "undefined";
},
    _isFuncOrString = function _isFuncOrString(value) {
  return _isFunction(value) || _isString(value);
},
    _isTypedArray = typeof ArrayBuffer === "function" && ArrayBuffer.isView || function () {},
    // note: IE10 has ArrayBuffer, but NOT ArrayBuffer.isView().
_isArray = Array.isArray,
    _strictNumExp = /(?:-?\.?\d|\.)+/gi,
    //only numbers (including negatives and decimals) but NOT relative values.
_numExp = /[-+=.]*\d+[.e\-+]*\d*[e\-\+]*\d*/g,
    //finds any numbers, including ones that start with += or -=, negative numbers, and ones in scientific notation like 1e-8.
_numWithUnitExp = /[-+=.]*\d+[.e-]*\d*[a-z%]*/g,
    _complexStringNumExp = /[-+=.]*\d+(?:\.|e-|e)*\d*/gi,
    //duplicate so that while we're looping through matches from exec(), it doesn't contaminate the lastIndex of _numExp which we use to search for colors too.
_relExp = /[+-]=-?[\.\d]+/,
    _delimitedValueExp = /[#\-+.]*\b[a-z\d-=+%.]+/gi,
    _globalTimeline,
    _win,
    _coreInitted,
    _doc,
    _globals = {},
    _installScope = {},
    _coreReady,
    _install = function _install(scope) {
  return (_installScope = _merge(scope, _globals)) && gsap;
},
    _missingPlugin = function _missingPlugin(property, value) {
  return console.warn("Invalid property", property, "set to", value, "Missing plugin? gsap.registerPlugin()");
},
    _warn = function _warn(message, suppress) {
  return !suppress && console.warn(message);
},
    _addGlobal = function _addGlobal(name, obj) {
  return name && (_globals[name] = obj) && _installScope && (_installScope[name] = obj) || _globals;
},
    _emptyFunc = function _emptyFunc() {
  return 0;
},
    _reservedProps = {},
    _lazyTweens = [],
    _lazyLookup = {},
    _lastRenderedFrame,
    _plugins = {},
    _effects = {},
    _nextGCFrame = 30,
    _harnessPlugins = [],
    _callbackNames = "",
    _harness = function _harness(targets) {
  var target = targets[0],
      harnessPlugin,
      i;
  _isObject(target) || _isFunction(target) || (targets = [targets]);

  if (!(harnessPlugin = (target._gsap || {}).harness)) {
    i = _harnessPlugins.length;

    while (i-- && !_harnessPlugins[i].targetTest(target)) {}

    harnessPlugin = _harnessPlugins[i];
  }

  i = targets.length;

  while (i--) {
    targets[i] && (targets[i]._gsap || (targets[i]._gsap = new GSCache(targets[i], harnessPlugin))) || targets.splice(i, 1);
  }

  return targets;
},
    _getCache = function _getCache(target) {
  return target._gsap || _harness(toArray(target))[0]._gsap;
},
    _getProperty = function _getProperty(target, property, v) {
  return (v = target[property]) && _isFunction(v) ? target[property]() : _isUndefined(v) && target.getAttribute && target.getAttribute(property) || v;
},
    _forEachName = function _forEachName(names, func) {
  return (names = names.split(",")).forEach(func) || names;
},
    //split a comma-delimited list of names into an array, then run a forEach() function and return the split array (this is just a way to consolidate/shorten some code).
_round = function _round(value) {
  return Math.round(value * 100000) / 100000 || 0;
},
    _arrayContainsAny = function _arrayContainsAny(toSearch, toFind) {
  //searches one array to find matches for any of the items in the toFind array. As soon as one is found, it returns true. It does NOT return all the matches; it's simply a boolean search.
  var l = toFind.length,
      i = 0;

  for (; toSearch.indexOf(toFind[i]) < 0 && ++i < l;) {}

  return i < l;
},
    _parseVars = function _parseVars(params, type, parent) {
  //reads the arguments passed to one of the key methods and figures out if the user is defining things with the OLD/legacy syntax where the duration is the 2nd parameter, and then it adjusts things accordingly and spits back the corrected vars object (with the duration added if necessary, as well as runBackwards or startAt or immediateRender). type 0 = to()/staggerTo(), 1 = from()/staggerFrom(), 2 = fromTo()/staggerFromTo()
  var isLegacy = _isNumber(params[1]),
      varsIndex = (isLegacy ? 2 : 1) + (type < 2 ? 0 : 1),
      vars = params[varsIndex],
      irVars;

  isLegacy && (vars.duration = params[1]);
  vars.parent = parent;

  if (type) {
    irVars = vars;

    while (parent && !("immediateRender" in irVars)) {
      // inheritance hasn't happened yet, but someone may have set a default in an ancestor timeline. We could do vars.immediateRender = _isNotFalse(_inheritDefaults(vars).immediateRender) but that'd exact a slight performance penalty because _inheritDefaults() also runs in the Tween constructor. We're paying a small kb price here to gain speed.
      irVars = parent.vars.defaults || {};
      parent = _isNotFalse(parent.vars.inherit) && parent.parent;
    }

    vars.immediateRender = _isNotFalse(irVars.immediateRender);
    type < 2 ? vars.runBackwards = 1 : vars.startAt = params[varsIndex - 1]; // "from" vars
  }

  return vars;
},
    _lazyRender = function _lazyRender() {
  var l = _lazyTweens.length,
      a = _lazyTweens.slice(0),
      i,
      tween;

  _lazyLookup = {};
  _lazyTweens.length = 0;

  for (i = 0; i < l; i++) {
    tween = a[i];
    tween && tween._lazy && (tween.render(tween._lazy[0], tween._lazy[1], true)._lazy = 0);
  }
},
    _lazySafeRender = function _lazySafeRender(animation, time, suppressEvents, force) {
  _lazyTweens.length && _lazyRender();
  animation.render(time, suppressEvents, force);
  _lazyTweens.length && _lazyRender(); //in case rendering caused any tweens to lazy-init, we should render them because typically when someone calls seek() or time() or progress(), they expect an immediate render.
},
    _numericIfPossible = function _numericIfPossible(value) {
  var n = parseFloat(value);
  return (n || n === 0) && (value + "").match(_delimitedValueExp).length < 2 ? n : _isString(value) ? value.trim() : value;
},
    _passThrough = function _passThrough(p) {
  return p;
},
    _setDefaults = function _setDefaults(obj, defaults) {
  for (var p in defaults) {
    p in obj || (obj[p] = defaults[p]);
  }

  return obj;
},
    _setKeyframeDefaults = function _setKeyframeDefaults(obj, defaults) {
  for (var p in defaults) {
    p in obj || p === "duration" || p === "ease" || (obj[p] = defaults[p]);
  }
},
    _merge = function _merge(base, toMerge) {
  for (var p in toMerge) {
    base[p] = toMerge[p];
  }

  return base;
},
    _mergeDeep = function _mergeDeep(base, toMerge) {
  for (var p in toMerge) {
    base[p] = _isObject(toMerge[p]) ? _mergeDeep(base[p] || (base[p] = {}), toMerge[p]) : toMerge[p];
  }

  return base;
},
    _copyExcluding = function _copyExcluding(obj, excluding) {
  var copy = {},
      p;

  for (p in obj) {
    p in excluding || (copy[p] = obj[p]);
  }

  return copy;
},
    _inheritDefaults = function _inheritDefaults(vars) {
  var parent = vars.parent || _globalTimeline,
      func = vars.keyframes ? _setKeyframeDefaults : _setDefaults;

  if (_isNotFalse(vars.inherit)) {
    while (parent) {
      func(vars, parent.vars.defaults);
      parent = parent.parent || parent._dp;
    }
  }

  return vars;
},
    _arraysMatch = function _arraysMatch(a1, a2) {
  var i = a1.length,
      match = i === a2.length;

  while (match && i-- && a1[i] === a2[i]) {}

  return i < 0;
},
    _addLinkedListItem = function _addLinkedListItem(parent, child, firstProp, lastProp, sortBy) {
  if (firstProp === void 0) {
    firstProp = "_first";
  }

  if (lastProp === void 0) {
    lastProp = "_last";
  }

  var prev = parent[lastProp],
      t;

  if (sortBy) {
    t = child[sortBy];

    while (prev && prev[sortBy] > t) {
      prev = prev._prev;
    }
  }

  if (prev) {
    child._next = prev._next;
    prev._next = child;
  } else {
    child._next = parent[firstProp];
    parent[firstProp] = child;
  }

  if (child._next) {
    child._next._prev = child;
  } else {
    parent[lastProp] = child;
  }

  child._prev = prev;
  child.parent = child._dp = parent;
  return child;
},
    _removeLinkedListItem = function _removeLinkedListItem(parent, child, firstProp, lastProp) {
  if (firstProp === void 0) {
    firstProp = "_first";
  }

  if (lastProp === void 0) {
    lastProp = "_last";
  }

  var prev = child._prev,
      next = child._next;

  if (prev) {
    prev._next = next;
  } else if (parent[firstProp] === child) {
    parent[firstProp] = next;
  }

  if (next) {
    next._prev = prev;
  } else if (parent[lastProp] === child) {
    parent[lastProp] = prev;
  }

  child._next = child._prev = child.parent = null; // don't delete the _dp just so we can revert if necessary. But parent should be null to indicate the item isn't in a linked list.
},
    _removeFromParent = function _removeFromParent(child, onlyIfParentHasAutoRemove) {
  child.parent && (!onlyIfParentHasAutoRemove || child.parent.autoRemoveChildren) && child.parent.remove(child);
  child._act = 0;
},
    _uncache = function _uncache(animation, child) {
  if (animation && (!child || child._end > animation._dur || child._start < 0)) {
    // performance optimization: if a child animation is passed in we should only uncache if that child EXTENDS the animation (its end time is beyond the end)
    var a = animation;

    while (a) {
      a._dirty = 1;
      a = a.parent;
    }
  }

  return animation;
},
    _recacheAncestors = function _recacheAncestors(animation) {
  var parent = animation.parent;

  while (parent && parent.parent) {
    //sometimes we must force a re-sort of all children and update the duration/totalDuration of all ancestor timelines immediately in case, for example, in the middle of a render loop, one tween alters another tween's timeScale which shoves its startTime before 0, forcing the parent timeline to shift around and shiftChildren() which could affect that next tween's render (startTime). Doesn't matter for the root timeline though.
    parent._dirty = 1;
    parent.totalDuration();
    parent = parent.parent;
  }

  return animation;
},
    _hasNoPausedAncestors = function _hasNoPausedAncestors(animation) {
  return !animation || animation._ts && _hasNoPausedAncestors(animation.parent);
},
    _elapsedCycleDuration = function _elapsedCycleDuration(animation) {
  return animation._repeat ? _animationCycle(animation._tTime, animation = animation.duration() + animation._rDelay) * animation : 0;
},
    // feed in the totalTime and cycleDuration and it'll return the cycle (iteration minus 1) and if the playhead is exactly at the very END, it will NOT bump up to the next cycle.
_animationCycle = function _animationCycle(tTime, cycleDuration) {
  return (tTime /= cycleDuration) && ~~tTime === tTime ? ~~tTime - 1 : ~~tTime;
},
    _parentToChildTotalTime = function _parentToChildTotalTime(parentTime, child) {
  return (parentTime - child._start) * child._ts + (child._ts >= 0 ? 0 : child._dirty ? child.totalDuration() : child._tDur);
},
    _setEnd = function _setEnd(animation) {
  return animation._end = _round(animation._start + (animation._tDur / Math.abs(animation._ts || animation._rts || _tinyNum) || 0));
},
    _alignPlayhead = function _alignPlayhead(animation, totalTime) {
  // adjusts the animation's _start and _end according to the provided totalTime (only if the parent's smoothChildTiming is true and the animation isn't paused). It doesn't do any rendering or forcing things back into parent timelines, etc. - that's what totalTime() is for.
  var parent = animation._dp;

  if (parent && parent.smoothChildTiming && animation._ts) {
    animation._start = _round(animation._dp._time - (animation._ts > 0 ? totalTime / animation._ts : ((animation._dirty ? animation.totalDuration() : animation._tDur) - totalTime) / -animation._ts));

    _setEnd(animation);

    parent._dirty || _uncache(parent, animation); //for performance improvement. If the parent's cache is already dirty, it already took care of marking the ancestors as dirty too, so skip the function call here.
  }

  return animation;
},

/*
_totalTimeToTime = (clampedTotalTime, duration, repeat, repeatDelay, yoyo) => {
	let cycleDuration = duration + repeatDelay,
		time = _round(clampedTotalTime % cycleDuration);
	if (time > duration) {
		time = duration;
	}
	return (yoyo && (~~(clampedTotalTime / cycleDuration) & 1)) ? duration - time : time;
},
*/
_postAddChecks = function _postAddChecks(timeline, child) {
  var t;

  if (child._time || child._initted && !child._dur) {
    //in case, for example, the _start is moved on a tween that has already rendered. Imagine it's at its end state, then the startTime is moved WAY later (after the end of this timeline), it should render at its beginning.
    t = _parentToChildTotalTime(timeline.rawTime(), child);

    if (!child._dur || _clamp(0, child.totalDuration(), t) - child._tTime > _tinyNum) {
      child.render(t, true);
    }
  } //if the timeline has already ended but the inserted tween/timeline extends the duration, we should enable this timeline again so that it renders properly. We should also align the playhead with the parent timeline's when appropriate.


  if (_uncache(timeline, child)._dp && timeline._initted && timeline._time >= timeline._dur && timeline._ts) {
    //in case any of the ancestors had completed but should now be enabled...
    if (timeline._dur < timeline.duration()) {
      t = timeline;

      while (t._dp) {
        t.rawTime() >= 0 && t.totalTime(t._tTime); //moves the timeline (shifts its startTime) if necessary, and also enables it. If it's currently zero, though, it may not be scheduled to render until later so there's no need to force it to align with the current playhead position. Only move to catch up with the playhead.

        t = t._dp;
      }
    }

    timeline._zTime = -_tinyNum; // helps ensure that the next render() will be forced (crossingStart = true in render()), even if the duration hasn't changed (we're adding a child which would need to get rendered). Definitely an edge case. Note: we MUST do this AFTER the loop above where the totalTime() might trigger a render() because this _addToTimeline() method gets called from the Animation constructor, BEFORE tweens even record their targets, etc. so we wouldn't want things to get triggered in the wrong order.
  }
},
    _addToTimeline = function _addToTimeline(timeline, child, position, skipChecks) {
  child.parent && _removeFromParent(child);
  child._start = _round(position + child._delay);
  child._end = _round(child._start + (child.totalDuration() / Math.abs(child.timeScale()) || 0));

  _addLinkedListItem(timeline, child, "_first", "_last", timeline._sort ? "_start" : 0);

  timeline._recent = child;
  skipChecks || _postAddChecks(timeline, child);
  return timeline;
},
    _scrollTrigger = function _scrollTrigger(animation, trigger) {
  return (_globals.ScrollTrigger || _missingPlugin("scrollTrigger", trigger)) && _globals.ScrollTrigger.create(trigger, animation);
},
    _attemptInitTween = function _attemptInitTween(tween, totalTime, force, suppressEvents) {
  _initTween(tween, totalTime);

  if (!tween._initted) {
    return 1;
  }

  if (!force && tween._pt && (tween._dur && tween.vars.lazy !== false || !tween._dur && tween.vars.lazy) && _lastRenderedFrame !== _ticker.frame) {
    _lazyTweens.push(tween);

    tween._lazy = [totalTime, suppressEvents];
    return 1;
  }
},
    _renderZeroDurationTween = function _renderZeroDurationTween(tween, totalTime, suppressEvents, force) {
  var prevRatio = tween.ratio,
      ratio = totalTime < 0 || !totalTime && prevRatio && !tween._start && tween._zTime > _tinyNum && !tween._dp._lock || (tween._ts < 0 || tween._dp._ts < 0) && tween.data !== "isFromStart" && tween.data !== "isStart" ? 0 : 1,
      // check parent's _lock because when a timeline repeats/yoyos and does its artificial wrapping, we shouldn't force the ratio back to 0. Also, if the tween or its parent is reversed and the totalTime is 0, we should go to a ratio of 0.
  repeatDelay = tween._rDelay,
      tTime = 0,
      pt,
      iteration,
      prevIteration;

  if (repeatDelay && tween._repeat) {
    // in case there's a zero-duration tween that has a repeat with a repeatDelay
    tTime = _clamp(0, tween._tDur, totalTime);
    iteration = _animationCycle(tTime, repeatDelay);
    prevIteration = _animationCycle(tween._tTime, repeatDelay);

    if (iteration !== prevIteration) {
      prevRatio = 1 - ratio;
      tween.vars.repeatRefresh && tween._initted && tween.invalidate();
    }
  }

  if (ratio !== prevRatio || force || tween._zTime === _tinyNum || !totalTime && tween._zTime) {
    if (!tween._initted && _attemptInitTween(tween, totalTime, force, suppressEvents)) {
      // if we render the very beginning (time == 0) of a fromTo(), we must force the render (normal tweens wouldn't need to render at a time of 0 when the prevTime was also 0). This is also mandatory to make sure overwriting kicks in immediately.
      return;
    }

    prevIteration = tween._zTime;
    tween._zTime = totalTime || (suppressEvents ? _tinyNum : 0); // when the playhead arrives at EXACTLY time 0 (right on top) of a zero-duration tween, we need to discern if events are suppressed so that when the playhead moves again (next time), it'll trigger the callback. If events are NOT suppressed, obviously the callback would be triggered in this render. Basically, the callback should fire either when the playhead ARRIVES or LEAVES this exact spot, not both. Imagine doing a timeline.seek(0) and there's a callback that sits at 0. Since events are suppressed on that seek() by default, nothing will fire, but when the playhead moves off of that position, the callback should fire. This behavior is what people intuitively expect.

    suppressEvents || (suppressEvents = totalTime && !prevIteration); // if it was rendered previously at exactly 0 (_zTime) and now the playhead is moving away, DON'T fire callbacks otherwise they'll seem like duplicates.

    tween.ratio = ratio;
    tween._from && (ratio = 1 - ratio);
    tween._time = 0;
    tween._tTime = tTime;
    suppressEvents || _callback(tween, "onStart");
    pt = tween._pt;

    while (pt) {
      pt.r(ratio, pt.d);
      pt = pt._next;
    }

    tween._startAt && totalTime < 0 && tween._startAt.render(totalTime, true, true);
    tween._onUpdate && !suppressEvents && _callback(tween, "onUpdate");
    tTime && tween._repeat && !suppressEvents && tween.parent && _callback(tween, "onRepeat");

    if ((totalTime >= tween._tDur || totalTime < 0) && tween.ratio === ratio) {
      ratio && _removeFromParent(tween, 1);

      if (!suppressEvents) {
        _callback(tween, ratio ? "onComplete" : "onReverseComplete", true);

        tween._prom && tween._prom();
      }
    }
  } else if (!tween._zTime) {
    tween._zTime = totalTime;
  }
},
    _findNextPauseTween = function _findNextPauseTween(animation, prevTime, time) {
  var child;

  if (time > prevTime) {
    child = animation._first;

    while (child && child._start <= time) {
      if (!child._dur && child.data === "isPause" && child._start > prevTime) {
        return child;
      }

      child = child._next;
    }
  } else {
    child = animation._last;

    while (child && child._start >= time) {
      if (!child._dur && child.data === "isPause" && child._start < prevTime) {
        return child;
      }

      child = child._prev;
    }
  }
},
    _setDuration = function _setDuration(animation, duration, skipUncache, leavePlayhead) {
  var repeat = animation._repeat,
      dur = _round(duration) || 0,
      totalProgress = animation._tTime / animation._tDur;
  totalProgress && !leavePlayhead && (animation._time *= dur / animation._dur);
  animation._dur = dur;
  animation._tDur = !repeat ? dur : repeat < 0 ? 1e10 : _round(dur * (repeat + 1) + animation._rDelay * repeat);
  totalProgress && !leavePlayhead ? _alignPlayhead(animation, animation._tTime = animation._tDur * totalProgress) : animation.parent && _setEnd(animation);
  skipUncache || _uncache(animation.parent, animation);
  return animation;
},
    _onUpdateTotalDuration = function _onUpdateTotalDuration(animation) {
  return animation instanceof Timeline ? _uncache(animation) : _setDuration(animation, animation._dur);
},
    _zeroPosition = {
  _start: 0,
  endTime: _emptyFunc
},
    _parsePosition = function _parsePosition(animation, position) {
  var labels = animation.labels,
      recent = animation._recent || _zeroPosition,
      clippedDuration = animation.duration() >= _bigNum ? recent.endTime(false) : animation._dur,
      //in case there's a child that infinitely repeats, users almost never intend for the insertion point of a new child to be based on a SUPER long value like that so we clip it and assume the most recently-added child's endTime should be used instead.
  i,
      offset;

  if (_isString(position) && (isNaN(position) || position in labels)) {
    //if the string is a number like "1", check to see if there's a label with that name, otherwise interpret it as a number (absolute value).
    i = position.charAt(0);

    if (i === "<" || i === ">") {
      return (i === "<" ? recent._start : recent.endTime(recent._repeat >= 0)) + (parseFloat(position.substr(1)) || 0);
    }

    i = position.indexOf("=");

    if (i < 0) {
      position in labels || (labels[position] = clippedDuration);
      return labels[position];
    }

    offset = +(position.charAt(i - 1) + position.substr(i + 1));
    return i > 1 ? _parsePosition(animation, position.substr(0, i - 1)) + offset : clippedDuration + offset;
  }

  return position == null ? clippedDuration : +position;
},
    _conditionalReturn = function _conditionalReturn(value, func) {
  return value || value === 0 ? func(value) : func;
},
    _clamp = function _clamp(min, max, value) {
  return value < min ? min : value > max ? max : value;
},
    getUnit = function getUnit(value) {
  return (value = (value + "").substr((parseFloat(value) + "").length)) && isNaN(value) ? value : "";
},
    // note: protect against padded numbers as strings, like "100.100". That shouldn't return "00" as the unit. If it's numeric, return no unit.
clamp = function clamp(min, max, value) {
  return _conditionalReturn(value, function (v) {
    return _clamp(min, max, v);
  });
},
    _slice = [].slice,
    _isArrayLike = function _isArrayLike(value, nonEmpty) {
  return value && _isObject(value) && "length" in value && (!nonEmpty && !value.length || value.length - 1 in value && _isObject(value[0])) && !value.nodeType && value !== _win;
},
    _flatten = function _flatten(ar, leaveStrings, accumulator) {
  if (accumulator === void 0) {
    accumulator = [];
  }

  return ar.forEach(function (value) {
    var _accumulator;

    return _isString(value) && !leaveStrings || _isArrayLike(value, 1) ? (_accumulator = accumulator).push.apply(_accumulator, toArray(value)) : accumulator.push(value);
  }) || accumulator;
},
    //takes any value and returns an array. If it's a string (and leaveStrings isn't true), it'll use document.querySelectorAll() and convert that to an array. It'll also accept iterables like jQuery objects.
toArray = function toArray(value, leaveStrings) {
  return _isString(value) && !leaveStrings && (_coreInitted || !_wake()) ? _slice.call(_doc.querySelectorAll(value), 0) : _isArray(value) ? _flatten(value, leaveStrings) : _isArrayLike(value) ? _slice.call(value, 0) : value ? [value] : [];
},
    shuffle = function shuffle(a) {
  return a.sort(function () {
    return .5 - Math.random();
  });
},
    // alternative that's a bit faster and more reliably diverse but bigger:   for (let j, v, i = a.length; i; j = Math.floor(Math.random() * i), v = a[--i], a[i] = a[j], a[j] = v); return a;
//for distributing values across an array. Can accept a number, a function or (most commonly) a function which can contain the following properties: {base, amount, from, ease, grid, axis, length, each}. Returns a function that expects the following parameters: index, target, array. Recognizes the following
distribute = function distribute(v) {
  if (_isFunction(v)) {
    return v;
  }

  var vars = _isObject(v) ? v : {
    each: v
  },
      //n:1 is just to indicate v was a number; we leverage that later to set v according to the length we get. If a number is passed in, we treat it like the old stagger value where 0.1, for example, would mean that things would be distributed with 0.1 between each element in the array rather than a total "amount" that's chunked out among them all.
  ease = _parseEase(vars.ease),
      from = vars.from || 0,
      base = parseFloat(vars.base) || 0,
      cache = {},
      isDecimal = from > 0 && from < 1,
      ratios = isNaN(from) || isDecimal,
      axis = vars.axis,
      ratioX = from,
      ratioY = from;

  if (_isString(from)) {
    ratioX = ratioY = {
      center: .5,
      edges: .5,
      end: 1
    }[from] || 0;
  } else if (!isDecimal && ratios) {
    ratioX = from[0];
    ratioY = from[1];
  }

  return function (i, target, a) {
    var l = (a || vars).length,
        distances = cache[l],
        originX,
        originY,
        x,
        y,
        d,
        j,
        max,
        min,
        wrapAt;

    if (!distances) {
      wrapAt = vars.grid === "auto" ? 0 : (vars.grid || [1, _bigNum])[1];

      if (!wrapAt) {
        max = -_bigNum;

        while (max < (max = a[wrapAt++].getBoundingClientRect().left) && wrapAt < l) {}

        wrapAt--;
      }

      distances = cache[l] = [];
      originX = ratios ? Math.min(wrapAt, l) * ratioX - .5 : from % wrapAt;
      originY = ratios ? l * ratioY / wrapAt - .5 : from / wrapAt | 0;
      max = 0;
      min = _bigNum;

      for (j = 0; j < l; j++) {
        x = j % wrapAt - originX;
        y = originY - (j / wrapAt | 0);
        distances[j] = d = !axis ? _sqrt(x * x + y * y) : Math.abs(axis === "y" ? y : x);
        d > max && (max = d);
        d < min && (min = d);
      }

      from === "random" && shuffle(distances);
      distances.max = max - min;
      distances.min = min;
      distances.v = l = (parseFloat(vars.amount) || parseFloat(vars.each) * (wrapAt > l ? l - 1 : !axis ? Math.max(wrapAt, l / wrapAt) : axis === "y" ? l / wrapAt : wrapAt) || 0) * (from === "edges" ? -1 : 1);
      distances.b = l < 0 ? base - l : base;
      distances.u = getUnit(vars.amount || vars.each) || 0; //unit

      ease = ease && l < 0 ? _invertEase(ease) : ease;
    }

    l = (distances[i] - distances.min) / distances.max || 0;
    return _round(distances.b + (ease ? ease(l) : l) * distances.v) + distances.u; //round in order to work around floating point errors
  };
},
    _roundModifier = function _roundModifier(v) {
  //pass in 0.1 get a function that'll round to the nearest tenth, or 5 to round to the closest 5, or 0.001 to the closest 1000th, etc.
  var p = v < 1 ? Math.pow(10, (v + "").length - 2) : 1; //to avoid floating point math errors (like 24 * 0.1 == 2.4000000000000004), we chop off at a specific number of decimal places (much faster than toFixed()

  return function (raw) {
    return Math.floor(Math.round(parseFloat(raw) / v) * v * p) / p + (_isNumber(raw) ? 0 : getUnit(raw));
  };
},
    snap = function snap(snapTo, value) {
  var isArray = _isArray(snapTo),
      radius,
      is2D;

  if (!isArray && _isObject(snapTo)) {
    radius = isArray = snapTo.radius || _bigNum;

    if (snapTo.values) {
      snapTo = toArray(snapTo.values);

      if (is2D = !_isNumber(snapTo[0])) {
        radius *= radius; //performance optimization so we don't have to Math.sqrt() in the loop.
      }
    } else {
      snapTo = _roundModifier(snapTo.increment);
    }
  }

  return _conditionalReturn(value, !isArray ? _roundModifier(snapTo) : _isFunction(snapTo) ? function (raw) {
    is2D = snapTo(raw);
    return Math.abs(is2D - raw) <= radius ? is2D : raw;
  } : function (raw) {
    var x = parseFloat(is2D ? raw.x : raw),
        y = parseFloat(is2D ? raw.y : 0),
        min = _bigNum,
        closest = 0,
        i = snapTo.length,
        dx,
        dy;

    while (i--) {
      if (is2D) {
        dx = snapTo[i].x - x;
        dy = snapTo[i].y - y;
        dx = dx * dx + dy * dy;
      } else {
        dx = Math.abs(snapTo[i] - x);
      }

      if (dx < min) {
        min = dx;
        closest = i;
      }
    }

    closest = !radius || min <= radius ? snapTo[closest] : raw;
    return is2D || closest === raw || _isNumber(raw) ? closest : closest + getUnit(raw);
  });
},
    random = function random(min, max, roundingIncrement, returnFunction) {
  return _conditionalReturn(_isArray(min) ? !max : roundingIncrement === true ? !!(roundingIncrement = 0) : !returnFunction, function () {
    return _isArray(min) ? min[~~(Math.random() * min.length)] : (roundingIncrement = roundingIncrement || 1e-5) && (returnFunction = roundingIncrement < 1 ? Math.pow(10, (roundingIncrement + "").length - 2) : 1) && Math.floor(Math.round((min + Math.random() * (max - min)) / roundingIncrement) * roundingIncrement * returnFunction) / returnFunction;
  });
},
    pipe = function pipe() {
  for (var _len = arguments.length, functions = new Array(_len), _key = 0; _key < _len; _key++) {
    functions[_key] = arguments[_key];
  }

  return function (value) {
    return functions.reduce(function (v, f) {
      return f(v);
    }, value);
  };
},
    unitize = function unitize(func, unit) {
  return function (value) {
    return func(parseFloat(value)) + (unit || getUnit(value));
  };
},
    normalize = function normalize(min, max, value) {
  return mapRange(min, max, 0, 1, value);
},
    _wrapArray = function _wrapArray(a, wrapper, value) {
  return _conditionalReturn(value, function (index) {
    return a[~~wrapper(index)];
  });
},
    wrap = function wrap(min, max, value) {
  // NOTE: wrap() CANNOT be an arrow function! A very odd compiling bug causes problems (unrelated to GSAP).
  var range = max - min;
  return _isArray(min) ? _wrapArray(min, wrap(0, min.length), max) : _conditionalReturn(value, function (value) {
    return (range + (value - min) % range) % range + min;
  });
},
    wrapYoyo = function wrapYoyo(min, max, value) {
  var range = max - min,
      total = range * 2;
  return _isArray(min) ? _wrapArray(min, wrapYoyo(0, min.length - 1), max) : _conditionalReturn(value, function (value) {
    value = (total + (value - min) % total) % total || 0;
    return min + (value > range ? total - value : value);
  });
},
    _replaceRandom = function _replaceRandom(value) {
  //replaces all occurrences of random(...) in a string with the calculated random value. can be a range like random(-100, 100, 5) or an array like random([0, 100, 500])
  var prev = 0,
      s = "",
      i,
      nums,
      end,
      isArray;

  while (~(i = value.indexOf("random(", prev))) {
    end = value.indexOf(")", i);
    isArray = value.charAt(i + 7) === "[";
    nums = value.substr(i + 7, end - i - 7).match(isArray ? _delimitedValueExp : _strictNumExp);
    s += value.substr(prev, i - prev) + random(isArray ? nums : +nums[0], isArray ? 0 : +nums[1], +nums[2] || 1e-5);
    prev = end + 1;
  }

  return s + value.substr(prev, value.length - prev);
},
    mapRange = function mapRange(inMin, inMax, outMin, outMax, value) {
  var inRange = inMax - inMin,
      outRange = outMax - outMin;
  return _conditionalReturn(value, function (value) {
    return outMin + ((value - inMin) / inRange * outRange || 0);
  });
},
    interpolate = function interpolate(start, end, progress, mutate) {
  var func = isNaN(start + end) ? 0 : function (p) {
    return (1 - p) * start + p * end;
  };

  if (!func) {
    var isString = _isString(start),
        master = {},
        p,
        i,
        interpolators,
        l,
        il;

    progress === true && (mutate = 1) && (progress = null);

    if (isString) {
      start = {
        p: start
      };
      end = {
        p: end
      };
    } else if (_isArray(start) && !_isArray(end)) {
      interpolators = [];
      l = start.length;
      il = l - 2;

      for (i = 1; i < l; i++) {
        interpolators.push(interpolate(start[i - 1], start[i])); //build the interpolators up front as a performance optimization so that when the function is called many times, it can just reuse them.
      }

      l--;

      func = function func(p) {
        p *= l;
        var i = Math.min(il, ~~p);
        return interpolators[i](p - i);
      };

      progress = end;
    } else if (!mutate) {
      start = _merge(_isArray(start) ? [] : {}, start);
    }

    if (!interpolators) {
      for (p in end) {
        _addPropTween.call(master, start, p, "get", end[p]);
      }

      func = function func(p) {
        return _renderPropTweens(p, master) || (isString ? start.p : start);
      };
    }
  }

  return _conditionalReturn(progress, func);
},
    _getLabelInDirection = function _getLabelInDirection(timeline, fromTime, backward) {
  //used for nextLabel() and previousLabel()
  var labels = timeline.labels,
      min = _bigNum,
      p,
      distance,
      label;

  for (p in labels) {
    distance = labels[p] - fromTime;

    if (distance < 0 === !!backward && distance && min > (distance = Math.abs(distance))) {
      label = p;
      min = distance;
    }
  }

  return label;
},
    _callback = function _callback(animation, type, executeLazyFirst) {
  var v = animation.vars,
      callback = v[type],
      params,
      scope;

  if (!callback) {
    return;
  }

  params = v[type + "Params"];
  scope = v.callbackScope || animation;
  executeLazyFirst && _lazyTweens.length && _lazyRender(); //in case rendering caused any tweens to lazy-init, we should render them because typically when a timeline finishes, users expect things to have rendered fully. Imagine an onUpdate on a timeline that reports/checks tweened values.

  return params ? callback.apply(scope, params) : callback.call(scope);
},
    _interrupt = function _interrupt(animation) {
  _removeFromParent(animation);

  animation.progress() < 1 && _callback(animation, "onInterrupt");
  return animation;
},
    _quickTween,
    _createPlugin = function _createPlugin(config) {
  config = !config.name && config["default"] || config; //UMD packaging wraps things oddly, so for example MotionPathHelper becomes {MotionPathHelper:MotionPathHelper, default:MotionPathHelper}.

  var name = config.name,
      isFunc = _isFunction(config),
      Plugin = name && !isFunc && config.init ? function () {
    this._props = [];
  } : config,
      //in case someone passes in an object that's not a plugin, like CustomEase
  instanceDefaults = {
    init: _emptyFunc,
    render: _renderPropTweens,
    add: _addPropTween,
    kill: _killPropTweensOf,
    modifier: _addPluginModifier,
    rawVars: 0
  },
      statics = {
    targetTest: 0,
    get: 0,
    getSetter: _getSetter,
    aliases: {},
    register: 0
  };

  _wake();

  if (config !== Plugin) {
    if (_plugins[name]) {
      return;
    }

    _setDefaults(Plugin, _setDefaults(_copyExcluding(config, instanceDefaults), statics)); //static methods


    _merge(Plugin.prototype, _merge(instanceDefaults, _copyExcluding(config, statics))); //instance methods


    _plugins[Plugin.prop = name] = Plugin;

    if (config.targetTest) {
      _harnessPlugins.push(Plugin);

      _reservedProps[name] = 1;
    }

    name = (name === "css" ? "CSS" : name.charAt(0).toUpperCase() + name.substr(1)) + "Plugin"; //for the global name. "motionPath" should become MotionPathPlugin
  }

  _addGlobal(name, Plugin);

  config.register && config.register(gsap, Plugin, PropTween);
},

/*
 * --------------------------------------------------------------------------------------
 * COLORS
 * --------------------------------------------------------------------------------------
 */
_255 = 255,
    _colorLookup = {
  aqua: [0, _255, _255],
  lime: [0, _255, 0],
  silver: [192, 192, 192],
  black: [0, 0, 0],
  maroon: [128, 0, 0],
  teal: [0, 128, 128],
  blue: [0, 0, _255],
  navy: [0, 0, 128],
  white: [_255, _255, _255],
  olive: [128, 128, 0],
  yellow: [_255, _255, 0],
  orange: [_255, 165, 0],
  gray: [128, 128, 128],
  purple: [128, 0, 128],
  green: [0, 128, 0],
  red: [_255, 0, 0],
  pink: [_255, 192, 203],
  cyan: [0, _255, _255],
  transparent: [_255, _255, _255, 0]
},
    _hue = function _hue(h, m1, m2) {
  h = h < 0 ? h + 1 : h > 1 ? h - 1 : h;
  return (h * 6 < 1 ? m1 + (m2 - m1) * h * 6 : h < .5 ? m2 : h * 3 < 2 ? m1 + (m2 - m1) * (2 / 3 - h) * 6 : m1) * _255 + .5 | 0;
},
    splitColor = function splitColor(v, toHSL, forceAlpha) {
  var a = !v ? _colorLookup.black : _isNumber(v) ? [v >> 16, v >> 8 & _255, v & _255] : 0,
      r,
      g,
      b,
      h,
      s,
      l,
      max,
      min,
      d,
      wasHSL;

  if (!a) {
    if (v.substr(-1) === ",") {
      //sometimes a trailing comma is included and we should chop it off (typically from a comma-delimited list of values like a textShadow:"2px 2px 2px blue, 5px 5px 5px rgb(255,0,0)" - in this example "blue," has a trailing comma. We could strip it out inside parseComplex() but we'd need to do it to the beginning and ending values plus it wouldn't provide protection from other potential scenarios like if the user passes in a similar value.
      v = v.substr(0, v.length - 1);
    }

    if (_colorLookup[v]) {
      a = _colorLookup[v];
    } else if (v.charAt(0) === "#") {
      if (v.length === 4) {
        //for shorthand like #9F0
        r = v.charAt(1);
        g = v.charAt(2);
        b = v.charAt(3);
        v = "#" + r + r + g + g + b + b;
      }

      v = parseInt(v.substr(1), 16);
      a = [v >> 16, v >> 8 & _255, v & _255];
    } else if (v.substr(0, 3) === "hsl") {
      a = wasHSL = v.match(_strictNumExp);

      if (!toHSL) {
        h = +a[0] % 360 / 360;
        s = +a[1] / 100;
        l = +a[2] / 100;
        g = l <= .5 ? l * (s + 1) : l + s - l * s;
        r = l * 2 - g;
        a.length > 3 && (a[3] *= 1); //cast as number

        a[0] = _hue(h + 1 / 3, r, g);
        a[1] = _hue(h, r, g);
        a[2] = _hue(h - 1 / 3, r, g);
      } else if (~v.indexOf("=")) {
        //if relative values are found, just return the raw strings with the relative prefixes in place.
        a = v.match(_numExp);
        forceAlpha && a.length < 4 && (a[3] = 1);
        return a;
      }
    } else {
      a = v.match(_strictNumExp) || _colorLookup.transparent;
    }

    a = a.map(Number);
  }

  if (toHSL && !wasHSL) {
    r = a[0] / _255;
    g = a[1] / _255;
    b = a[2] / _255;
    max = Math.max(r, g, b);
    min = Math.min(r, g, b);
    l = (max + min) / 2;

    if (max === min) {
      h = s = 0;
    } else {
      d = max - min;
      s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
      h = max === r ? (g - b) / d + (g < b ? 6 : 0) : max === g ? (b - r) / d + 2 : (r - g) / d + 4;
      h *= 60;
    }

    a[0] = ~~(h + .5);
    a[1] = ~~(s * 100 + .5);
    a[2] = ~~(l * 100 + .5);
  }

  forceAlpha && a.length < 4 && (a[3] = 1);
  return a;
},
    _colorOrderData = function _colorOrderData(v) {
  // strips out the colors from the string, finds all the numeric slots (with units) and returns an array of those. The Array also has a "c" property which is an Array of the index values where the colors belong. This is to help work around issues where there's a mis-matched order of color/numeric data like drop-shadow(#f00 0px 1px 2px) and drop-shadow(0x 1px 2px #f00). This is basically a helper function used in _formatColors()
  var values = [],
      c = [],
      i = -1;
  v.split(_colorExp).forEach(function (v) {
    var a = v.match(_numWithUnitExp) || [];
    values.push.apply(values, a);
    c.push(i += a.length + 1);
  });
  values.c = c;
  return values;
},
    _formatColors = function _formatColors(s, toHSL, orderMatchData) {
  var result = "",
      colors = (s + result).match(_colorExp),
      type = toHSL ? "hsla(" : "rgba(",
      i = 0,
      c,
      shell,
      d,
      l;

  if (!colors) {
    return s;
  }

  colors = colors.map(function (color) {
    return (color = splitColor(color, toHSL, 1)) && type + (toHSL ? color[0] + "," + color[1] + "%," + color[2] + "%," + color[3] : color.join(",")) + ")";
  });

  if (orderMatchData) {
    d = _colorOrderData(s);
    c = orderMatchData.c;

    if (c.join(result) !== d.c.join(result)) {
      shell = s.replace(_colorExp, "1").split(_numWithUnitExp);
      l = shell.length - 1;

      for (; i < l; i++) {
        result += shell[i] + (~c.indexOf(i) ? colors.shift() || type + "0,0,0,0)" : (d.length ? d : colors.length ? colors : orderMatchData).shift());
      }
    }
  }

  if (!shell) {
    shell = s.split(_colorExp);
    l = shell.length - 1;

    for (; i < l; i++) {
      result += shell[i] + colors[i];
    }
  }

  return result + shell[l];
},
    _colorExp = function () {
  var s = "(?:\\b(?:(?:rgb|rgba|hsl|hsla)\\(.+?\\))|\\B#(?:[0-9a-f]{3}){1,2}\\b",
      //we'll dynamically build this Regular Expression to conserve file size. After building it, it will be able to find rgb(), rgba(), # (hexadecimal), and named color values like red, blue, purple, etc.,
  p;

  for (p in _colorLookup) {
    s += "|" + p + "\\b";
  }

  return new RegExp(s + ")", "gi");
}(),
    _hslExp = /hsl[a]?\(/,
    _colorStringFilter = function _colorStringFilter(a) {
  var combined = a.join(" "),
      toHSL;
  _colorExp.lastIndex = 0;

  if (_colorExp.test(combined)) {
    toHSL = _hslExp.test(combined);
    a[1] = _formatColors(a[1], toHSL);
    a[0] = _formatColors(a[0], toHSL, _colorOrderData(a[1])); // make sure the order of numbers/colors match with the END value.

    return true;
  }
},

/*
 * --------------------------------------------------------------------------------------
 * TICKER
 * --------------------------------------------------------------------------------------
 */
_tickerActive,
    _ticker = function () {
  var _getTime = Date.now,
      _lagThreshold = 500,
      _adjustedLag = 33,
      _startTime = _getTime(),
      _lastUpdate = _startTime,
      _gap = 1000 / 240,
      _nextTime = _gap,
      _listeners = [],
      _id,
      _req,
      _raf,
      _self,
      _delta,
      _i,
      _tick = function _tick(v) {
    var elapsed = _getTime() - _lastUpdate,
        manual = v === true,
        overlap,
        dispatch,
        time,
        frame;

    elapsed > _lagThreshold && (_startTime += elapsed - _adjustedLag);
    _lastUpdate += elapsed;
    time = _lastUpdate - _startTime;
    overlap = time - _nextTime;

    if (overlap > 0 || manual) {
      frame = ++_self.frame;
      _delta = time - _self.time * 1000;
      _self.time = time = time / 1000;
      _nextTime += overlap + (overlap >= _gap ? 4 : _gap - overlap);
      dispatch = 1;
    }

    manual || (_id = _req(_tick)); //make sure the request is made before we dispatch the "tick" event so that timing is maintained. Otherwise, if processing the "tick" requires a bunch of time (like 15ms) and we're using a setTimeout() that's based on 16.7ms, it'd technically take 31.7ms between frames otherwise.

    if (dispatch) {
      for (_i = 0; _i < _listeners.length; _i++) {
        // use _i and check _listeners.length instead of a variable because a listener could get removed during the loop, and if that happens to an element less than the current index, it'd throw things off in the loop.
        _listeners[_i](time, _delta, frame, v);
      }
    }
  };

  _self = {
    time: 0,
    frame: 0,
    tick: function tick() {
      _tick(true);
    },
    deltaRatio: function deltaRatio(fps) {
      return _delta / (1000 / (fps || 60));
    },
    wake: function wake() {
      if (_coreReady) {
        if (!_coreInitted && _windowExists()) {
          _win = _coreInitted = window;
          _doc = _win.document || {};
          _globals.gsap = gsap;
          (_win.gsapVersions || (_win.gsapVersions = [])).push(gsap.version);

          _install(_installScope || _win.GreenSockGlobals || !_win.gsap && _win || {});

          _raf = _win.requestAnimationFrame;
        }

        _id && _self.sleep();

        _req = _raf || function (f) {
          return setTimeout(f, _nextTime - _self.time * 1000 + 1 | 0);
        };

        _tickerActive = 1;

        _tick(2);
      }
    },
    sleep: function sleep() {
      (_raf ? _win.cancelAnimationFrame : clearTimeout)(_id);
      _tickerActive = 0;
      _req = _emptyFunc;
    },
    lagSmoothing: function lagSmoothing(threshold, adjustedLag) {
      _lagThreshold = threshold || 1 / _tinyNum; //zero should be interpreted as basically unlimited

      _adjustedLag = Math.min(adjustedLag, _lagThreshold, 0);
    },
    fps: function fps(_fps) {
      _gap = 1000 / (_fps || 240);
      _nextTime = _self.time * 1000 + _gap;
    },
    add: function add(callback) {
      _listeners.indexOf(callback) < 0 && _listeners.push(callback);

      _wake();
    },
    remove: function remove(callback) {
      var i;
      ~(i = _listeners.indexOf(callback)) && _listeners.splice(i, 1) && _i >= i && _i--;
    },
    _listeners: _listeners
  };
  return _self;
}(),
    _wake = function _wake() {
  return !_tickerActive && _ticker.wake();
},
    //also ensures the core classes are initialized.

/*
* -------------------------------------------------
* EASING
* -------------------------------------------------
*/
_easeMap = {},
    _customEaseExp = /^[\d.\-M][\d.\-,\s]/,
    _quotesExp = /["']/g,
    _parseObjectInString = function _parseObjectInString(value) {
  //takes a string like "{wiggles:10, type:anticipate})" and turns it into a real object. Notice it ends in ")" and includes the {} wrappers. This is because we only use this function for parsing ease configs and prioritized optimization rather than reusability.
  var obj = {},
      split = value.substr(1, value.length - 3).split(":"),
      key = split[0],
      i = 1,
      l = split.length,
      index,
      val,
      parsedVal;

  for (; i < l; i++) {
    val = split[i];
    index = i !== l - 1 ? val.lastIndexOf(",") : val.length;
    parsedVal = val.substr(0, index);
    obj[key] = isNaN(parsedVal) ? parsedVal.replace(_quotesExp, "").trim() : +parsedVal;
    key = val.substr(index + 1).trim();
  }

  return obj;
},
    _valueInParentheses = function _valueInParentheses(value) {
  var open = value.indexOf("(") + 1,
      close = value.indexOf(")"),
      nested = value.indexOf("(", open);
  return value.substring(open, ~nested && nested < close ? value.indexOf(")", close + 1) : close);
},
    _configEaseFromString = function _configEaseFromString(name) {
  //name can be a string like "elastic.out(1,0.5)", and pass in _easeMap as obj and it'll parse it out and call the actual function like _easeMap.Elastic.easeOut.config(1,0.5). It will also parse custom ease strings as long as CustomEase is loaded and registered (internally as _easeMap._CE).
  var split = (name + "").split("("),
      ease = _easeMap[split[0]];
  return ease && split.length > 1 && ease.config ? ease.config.apply(null, ~name.indexOf("{") ? [_parseObjectInString(split[1])] : _valueInParentheses(name).split(",").map(_numericIfPossible)) : _easeMap._CE && _customEaseExp.test(name) ? _easeMap._CE("", name) : ease;
},
    _invertEase = function _invertEase(ease) {
  return function (p) {
    return 1 - ease(1 - p);
  };
},
    // allow yoyoEase to be set in children and have those affected when the parent/ancestor timeline yoyos.
_propagateYoyoEase = function _propagateYoyoEase(timeline, isYoyo) {
  var child = timeline._first,
      ease;

  while (child) {
    if (child instanceof Timeline) {
      _propagateYoyoEase(child, isYoyo);
    } else if (child.vars.yoyoEase && (!child._yoyo || !child._repeat) && child._yoyo !== isYoyo) {
      if (child.timeline) {
        _propagateYoyoEase(child.timeline, isYoyo);
      } else {
        ease = child._ease;
        child._ease = child._yEase;
        child._yEase = ease;
        child._yoyo = isYoyo;
      }
    }

    child = child._next;
  }
},
    _parseEase = function _parseEase(ease, defaultEase) {
  return !ease ? defaultEase : (_isFunction(ease) ? ease : _easeMap[ease] || _configEaseFromString(ease)) || defaultEase;
},
    _insertEase = function _insertEase(names, easeIn, easeOut, easeInOut) {
  if (easeOut === void 0) {
    easeOut = function easeOut(p) {
      return 1 - easeIn(1 - p);
    };
  }

  if (easeInOut === void 0) {
    easeInOut = function easeInOut(p) {
      return p < .5 ? easeIn(p * 2) / 2 : 1 - easeIn((1 - p) * 2) / 2;
    };
  }

  var ease = {
    easeIn: easeIn,
    easeOut: easeOut,
    easeInOut: easeInOut
  },
      lowercaseName;

  _forEachName(names, function (name) {
    _easeMap[name] = _globals[name] = ease;
    _easeMap[lowercaseName = name.toLowerCase()] = easeOut;

    for (var p in ease) {
      _easeMap[lowercaseName + (p === "easeIn" ? ".in" : p === "easeOut" ? ".out" : ".inOut")] = _easeMap[name + "." + p] = ease[p];
    }
  });

  return ease;
},
    _easeInOutFromOut = function _easeInOutFromOut(easeOut) {
  return function (p) {
    return p < .5 ? (1 - easeOut(1 - p * 2)) / 2 : .5 + easeOut((p - .5) * 2) / 2;
  };
},
    _configElastic = function _configElastic(type, amplitude, period) {
  var p1 = amplitude >= 1 ? amplitude : 1,
      //note: if amplitude is < 1, we simply adjust the period for a more natural feel. Otherwise the math doesn't work right and the curve starts at 1.
  p2 = (period || (type ? .3 : .45)) / (amplitude < 1 ? amplitude : 1),
      p3 = p2 / _2PI * (Math.asin(1 / p1) || 0),
      easeOut = function easeOut(p) {
    return p === 1 ? 1 : p1 * Math.pow(2, -10 * p) * _sin((p - p3) * p2) + 1;
  },
      ease = type === "out" ? easeOut : type === "in" ? function (p) {
    return 1 - easeOut(1 - p);
  } : _easeInOutFromOut(easeOut);

  p2 = _2PI / p2; //precalculate to optimize

  ease.config = function (amplitude, period) {
    return _configElastic(type, amplitude, period);
  };

  return ease;
},
    _configBack = function _configBack(type, overshoot) {
  if (overshoot === void 0) {
    overshoot = 1.70158;
  }

  var easeOut = function easeOut(p) {
    return p ? --p * p * ((overshoot + 1) * p + overshoot) + 1 : 0;
  },
      ease = type === "out" ? easeOut : type === "in" ? function (p) {
    return 1 - easeOut(1 - p);
  } : _easeInOutFromOut(easeOut);

  ease.config = function (overshoot) {
    return _configBack(type, overshoot);
  };

  return ease;
}; // a cheaper (kb and cpu) but more mild way to get a parameterized weighted ease by feeding in a value between -1 (easeIn) and 1 (easeOut) where 0 is linear.
// _weightedEase = ratio => {
// 	let y = 0.5 + ratio / 2;
// 	return p => (2 * (1 - p) * p * y + p * p);
// },
// a stronger (but more expensive kb/cpu) parameterized weighted ease that lets you feed in a value between -1 (easeIn) and 1 (easeOut) where 0 is linear.
// _weightedEaseStrong = ratio => {
// 	ratio = .5 + ratio / 2;
// 	let o = 1 / 3 * (ratio < .5 ? ratio : 1 - ratio),
// 		b = ratio - o,
// 		c = ratio + o;
// 	return p => p === 1 ? p : 3 * b * (1 - p) * (1 - p) * p + 3 * c * (1 - p) * p * p + p * p * p;
// };


_forEachName("Linear,Quad,Cubic,Quart,Quint,Strong", function (name, i) {
  var power = i < 5 ? i + 1 : i;

  _insertEase(name + ",Power" + (power - 1), i ? function (p) {
    return Math.pow(p, power);
  } : function (p) {
    return p;
  }, function (p) {
    return 1 - Math.pow(1 - p, power);
  }, function (p) {
    return p < .5 ? Math.pow(p * 2, power) / 2 : 1 - Math.pow((1 - p) * 2, power) / 2;
  });
});

_easeMap.Linear.easeNone = _easeMap.none = _easeMap.Linear.easeIn;

_insertEase("Elastic", _configElastic("in"), _configElastic("out"), _configElastic());

(function (n, c) {
  var n1 = 1 / c,
      n2 = 2 * n1,
      n3 = 2.5 * n1,
      easeOut = function easeOut(p) {
    return p < n1 ? n * p * p : p < n2 ? n * Math.pow(p - 1.5 / c, 2) + .75 : p < n3 ? n * (p -= 2.25 / c) * p + .9375 : n * Math.pow(p - 2.625 / c, 2) + .984375;
  };

  _insertEase("Bounce", function (p) {
    return 1 - easeOut(1 - p);
  }, easeOut);
})(7.5625, 2.75);

_insertEase("Expo", function (p) {
  return p ? Math.pow(2, 10 * (p - 1)) : 0;
});

_insertEase("Circ", function (p) {
  return -(_sqrt(1 - p * p) - 1);
});

_insertEase("Sine", function (p) {
  return p === 1 ? 1 : -_cos(p * _HALF_PI) + 1;
});

_insertEase("Back", _configBack("in"), _configBack("out"), _configBack());

_easeMap.SteppedEase = _easeMap.steps = _globals.SteppedEase = {
  config: function config(steps, immediateStart) {
    if (steps === void 0) {
      steps = 1;
    }

    var p1 = 1 / steps,
        p2 = steps + (immediateStart ? 0 : 1),
        p3 = immediateStart ? 1 : 0,
        max = 1 - _tinyNum;
    return function (p) {
      return ((p2 * _clamp(0, max, p) | 0) + p3) * p1;
    };
  }
};
_defaults.ease = _easeMap["quad.out"];

_forEachName("onComplete,onUpdate,onStart,onRepeat,onReverseComplete,onInterrupt", function (name) {
  return _callbackNames += name + "," + name + "Params,";
});
/*
 * --------------------------------------------------------------------------------------
 * CACHE
 * --------------------------------------------------------------------------------------
 */


var GSCache = function GSCache(target, harness) {
  this.id = _gsID++;
  target._gsap = this;
  this.target = target;
  this.harness = harness;
  this.get = harness ? harness.get : _getProperty;
  this.set = harness ? harness.getSetter : _getSetter;
};
/*
 * --------------------------------------------------------------------------------------
 * ANIMATION
 * --------------------------------------------------------------------------------------
 */

var Animation = /*#__PURE__*/function () {
  function Animation(vars, time) {
    var parent = vars.parent || _globalTimeline;
    this.vars = vars;
    this._delay = +vars.delay || 0;

    if (this._repeat = vars.repeat || 0) {
      this._rDelay = vars.repeatDelay || 0;
      this._yoyo = !!vars.yoyo || !!vars.yoyoEase;
    }

    this._ts = 1;

    _setDuration(this, +vars.duration, 1, 1);

    this.data = vars.data;
    _tickerActive || _ticker.wake();
    parent && _addToTimeline(parent, this, time || time === 0 ? time : parent._time, 1);
    vars.reversed && this.reverse();
    vars.paused && this.paused(true);
  }

  var _proto = Animation.prototype;

  _proto.delay = function delay(value) {
    if (value || value === 0) {
      this.parent && this.parent.smoothChildTiming && this.startTime(this._start + value - this._delay);
      this._delay = value;
      return this;
    }

    return this._delay;
  };

  _proto.duration = function duration(value) {
    return arguments.length ? this.totalDuration(this._repeat > 0 ? value + (value + this._rDelay) * this._repeat : value) : this.totalDuration() && this._dur;
  };

  _proto.totalDuration = function totalDuration(value) {
    if (!arguments.length) {
      return this._tDur;
    }

    this._dirty = 0;
    return _setDuration(this, this._repeat < 0 ? value : (value - this._repeat * this._rDelay) / (this._repeat + 1));
  };

  _proto.totalTime = function totalTime(_totalTime, suppressEvents) {
    _wake();

    if (!arguments.length) {
      return this._tTime;
    }

    var parent = this._dp;

    if (parent && parent.smoothChildTiming && this._ts) {
      _alignPlayhead(this, _totalTime); //in case any of the ancestor timelines had completed but should now be enabled, we should reset their totalTime() which will also ensure that they're lined up properly and enabled. Skip for animations that are on the root (wasteful). Example: a TimelineLite.exportRoot() is performed when there's a paused tween on the root, the export will not complete until that tween is unpaused, but imagine a child gets restarted later, after all [unpaused] tweens have completed. The start of that child would get pushed out, but one of the ancestors may have completed.


      while (parent.parent) {
        if (parent.parent._time !== parent._start + (parent._ts >= 0 ? parent._tTime / parent._ts : (parent.totalDuration() - parent._tTime) / -parent._ts)) {
          parent.totalTime(parent._tTime, true);
        }

        parent = parent.parent;
      }

      if (!this.parent && this._dp.autoRemoveChildren && (this._ts > 0 && _totalTime < this._tDur || this._ts < 0 && _totalTime > 0 || !this._tDur && !_totalTime)) {
        //if the animation doesn't have a parent, put it back into its last parent (recorded as _dp for exactly cases like this). Limit to parents with autoRemoveChildren (like globalTimeline) so that if the user manually removes an animation from a timeline and then alters its playhead, it doesn't get added back in.
        _addToTimeline(this._dp, this, this._start - this._delay);
      }
    }

    if (this._tTime !== _totalTime || !this._dur && !suppressEvents || this._initted && Math.abs(this._zTime) === _tinyNum || !_totalTime && !this._initted && (this.add || this._ptLookup)) {
      // check for _ptLookup on a Tween instance to ensure it has actually finished being instantiated, otherwise if this.reverse() gets called in the Animation constructor, it could trigger a render() here even though the _targets weren't populated, thus when _init() is called there won't be any PropTweens (it'll act like the tween is non-functional)
      this._ts || (this._pTime = _totalTime); // otherwise, if an animation is paused, then the playhead is moved back to zero, then resumed, it'd revert back to the original time at the pause

      _lazySafeRender(this, _totalTime, suppressEvents);
    }

    return this;
  };

  _proto.time = function time(value, suppressEvents) {
    return arguments.length ? this.totalTime(Math.min(this.totalDuration(), value + _elapsedCycleDuration(this)) % this._dur || (value ? this._dur : 0), suppressEvents) : this._time; // note: if the modulus results in 0, the playhead could be exactly at the end or the beginning, and we always defer to the END with a non-zero value, otherwise if you set the time() to the very end (duration()), it would render at the START!
  };

  _proto.totalProgress = function totalProgress(value, suppressEvents) {
    return arguments.length ? this.totalTime(this.totalDuration() * value, suppressEvents) : this.totalDuration() ? Math.min(1, this._tTime / this._tDur) : this.ratio;
  };

  _proto.progress = function progress(value, suppressEvents) {
    return arguments.length ? this.totalTime(this.duration() * (this._yoyo && !(this.iteration() & 1) ? 1 - value : value) + _elapsedCycleDuration(this), suppressEvents) : this.duration() ? Math.min(1, this._time / this._dur) : this.ratio;
  };

  _proto.iteration = function iteration(value, suppressEvents) {
    var cycleDuration = this.duration() + this._rDelay;

    return arguments.length ? this.totalTime(this._time + (value - 1) * cycleDuration, suppressEvents) : this._repeat ? _animationCycle(this._tTime, cycleDuration) + 1 : 1;
  } // potential future addition:
  // isPlayingBackwards() {
  // 	let animation = this,
  // 		orientation = 1; // 1 = forward, -1 = backward
  // 	while (animation) {
  // 		orientation *= animation.reversed() || (animation.repeat() && !(animation.iteration() & 1)) ? -1 : 1;
  // 		animation = animation.parent;
  // 	}
  // 	return orientation < 0;
  // }
  ;

  _proto.timeScale = function timeScale(value) {
    if (!arguments.length) {
      return this._rts === -_tinyNum ? 0 : this._rts; // recorded timeScale. Special case: if someone calls reverse() on an animation with timeScale of 0, we assign it -_tinyNum to remember it's reversed.
    }

    if (this._rts === value) {
      return this;
    }

    var tTime = this.parent && this._ts ? _parentToChildTotalTime(this.parent._time, this) : this._tTime; // make sure to do the parentToChildTotalTime() BEFORE setting the new _ts because the old one must be used in that calculation.
    // prioritize rendering where the parent's playhead lines up instead of this._tTime because there could be a tween that's animating another tween's timeScale in the same rendering loop (same parent), thus if the timeScale tween renders first, it would alter _start BEFORE _tTime was set on that tick (in the rendering loop), effectively freezing it until the timeScale tween finishes.

    this._rts = +value || 0;
    this._ts = this._ps || value === -_tinyNum ? 0 : this._rts; // _ts is the functional timeScale which would be 0 if the animation is paused.

    return _recacheAncestors(this.totalTime(_clamp(-this._delay, this._tDur, tTime), true));
  };

  _proto.paused = function paused(value) {
    if (!arguments.length) {
      return this._ps;
    }

    if (this._ps !== value) {
      this._ps = value;

      if (value) {
        this._pTime = this._tTime || Math.max(-this._delay, this.rawTime()); // if the pause occurs during the delay phase, make sure that's factored in when resuming.

        this._ts = this._act = 0; // _ts is the functional timeScale, so a paused tween would effectively have a timeScale of 0. We record the "real" timeScale as _rts (recorded time scale)
      } else {
        _wake();

        this._ts = this._rts; //only defer to _pTime (pauseTime) if tTime is zero. Remember, someone could pause() an animation, then scrub the playhead and resume(). If the parent doesn't have smoothChildTiming, we render at the rawTime() because the startTime won't get updated.

        this.totalTime(this.parent && !this.parent.smoothChildTiming ? this.rawTime() : this._tTime || this._pTime, this.progress() === 1 && (this._tTime -= _tinyNum) && Math.abs(this._zTime) !== _tinyNum); // edge case: animation.progress(1).pause().play() wouldn't render again because the playhead is already at the end, but the call to totalTime() below will add it back to its parent...and not remove it again (since removing only happens upon rendering at a new time). Offsetting the _tTime slightly is done simply to cause the final render in totalTime() that'll pop it off its timeline (if autoRemoveChildren is true, of course). Check to make sure _zTime isn't -_tinyNum to avoid an edge case where the playhead is pushed to the end but INSIDE a tween/callback, the timeline itself is paused thus halting rendering and leaving a few unrendered. When resuming, it wouldn't render those otherwise.
      }
    }

    return this;
  };

  _proto.startTime = function startTime(value) {
    if (arguments.length) {
      this._start = value;
      var parent = this.parent || this._dp;
      parent && (parent._sort || !this.parent) && _addToTimeline(parent, this, value - this._delay);
      return this;
    }

    return this._start;
  };

  _proto.endTime = function endTime(includeRepeats) {
    return this._start + (_isNotFalse(includeRepeats) ? this.totalDuration() : this.duration()) / Math.abs(this._ts);
  };

  _proto.rawTime = function rawTime(wrapRepeats) {
    var parent = this.parent || this._dp; // _dp = detatched parent

    return !parent ? this._tTime : wrapRepeats && (!this._ts || this._repeat && this._time && this.totalProgress() < 1) ? this._tTime % (this._dur + this._rDelay) : !this._ts ? this._tTime : _parentToChildTotalTime(parent.rawTime(wrapRepeats), this);
  };

  _proto.globalTime = function globalTime(rawTime) {
    var animation = this,
        time = arguments.length ? rawTime : animation.rawTime();

    while (animation) {
      time = animation._start + time / (animation._ts || 1);
      animation = animation._dp;
    }

    return time;
  };

  _proto.repeat = function repeat(value) {
    if (arguments.length) {
      this._repeat = value;
      return _onUpdateTotalDuration(this);
    }

    return this._repeat;
  };

  _proto.repeatDelay = function repeatDelay(value) {
    if (arguments.length) {
      this._rDelay = value;
      return _onUpdateTotalDuration(this);
    }

    return this._rDelay;
  };

  _proto.yoyo = function yoyo(value) {
    if (arguments.length) {
      this._yoyo = value;
      return this;
    }

    return this._yoyo;
  };

  _proto.seek = function seek(position, suppressEvents) {
    return this.totalTime(_parsePosition(this, position), _isNotFalse(suppressEvents));
  };

  _proto.restart = function restart(includeDelay, suppressEvents) {
    return this.play().totalTime(includeDelay ? -this._delay : 0, _isNotFalse(suppressEvents));
  };

  _proto.play = function play(from, suppressEvents) {
    from != null && this.seek(from, suppressEvents);
    return this.reversed(false).paused(false);
  };

  _proto.reverse = function reverse(from, suppressEvents) {
    from != null && this.seek(from || this.totalDuration(), suppressEvents);
    return this.reversed(true).paused(false);
  };

  _proto.pause = function pause(atTime, suppressEvents) {
    atTime != null && this.seek(atTime, suppressEvents);
    return this.paused(true);
  };

  _proto.resume = function resume() {
    return this.paused(false);
  };

  _proto.reversed = function reversed(value) {
    if (arguments.length) {
      !!value !== this.reversed() && this.timeScale(-this._rts || (value ? -_tinyNum : 0)); // in case timeScale is zero, reversing would have no effect so we use _tinyNum.

      return this;
    }

    return this._rts < 0;
  };

  _proto.invalidate = function invalidate() {
    this._initted = 0;
    this._zTime = -_tinyNum;
    return this;
  };

  _proto.isActive = function isActive() {
    var parent = this.parent || this._dp,
        start = this._start,
        rawTime;
    return !!(!parent || this._ts && this._initted && parent.isActive() && (rawTime = parent.rawTime(true)) >= start && rawTime < this.endTime(true) - _tinyNum);
  };

  _proto.eventCallback = function eventCallback(type, callback, params) {
    var vars = this.vars;

    if (arguments.length > 1) {
      if (!callback) {
        delete vars[type];
      } else {
        vars[type] = callback;
        params && (vars[type + "Params"] = params);
        type === "onUpdate" && (this._onUpdate = callback);
      }

      return this;
    }

    return vars[type];
  };

  _proto.then = function then(onFulfilled) {
    var self = this;
    return new Promise(function (resolve) {
      var f = _isFunction(onFulfilled) ? onFulfilled : _passThrough,
          _resolve = function _resolve() {
        var _then = self.then;
        self.then = null; // temporarily null the then() method to avoid an infinite loop (see https://github.com/greensock/GSAP/issues/322)

        _isFunction(f) && (f = f(self)) && (f.then || f === self) && (self.then = _then);
        resolve(f);
        self.then = _then;
      };

      if (self._initted && self.totalProgress() === 1 && self._ts >= 0 || !self._tTime && self._ts < 0) {
        _resolve();
      } else {
        self._prom = _resolve;
      }
    });
  };

  _proto.kill = function kill() {
    _interrupt(this);
  };

  return Animation;
}();

_setDefaults(Animation.prototype, {
  _time: 0,
  _start: 0,
  _end: 0,
  _tTime: 0,
  _tDur: 0,
  _dirty: 0,
  _repeat: 0,
  _yoyo: false,
  parent: null,
  _initted: false,
  _rDelay: 0,
  _ts: 1,
  _dp: 0,
  ratio: 0,
  _zTime: -_tinyNum,
  _prom: 0,
  _ps: false,
  _rts: 1
});
/*
 * -------------------------------------------------
 * TIMELINE
 * -------------------------------------------------
 */


var Timeline = /*#__PURE__*/function (_Animation) {
  _inheritsLoose(Timeline, _Animation);

  function Timeline(vars, time) {
    var _this;

    if (vars === void 0) {
      vars = {};
    }

    _this = _Animation.call(this, vars, time) || this;
    _this.labels = {};
    _this.smoothChildTiming = !!vars.smoothChildTiming;
    _this.autoRemoveChildren = !!vars.autoRemoveChildren;
    _this._sort = _isNotFalse(vars.sortChildren);
    _this.parent && _postAddChecks(_this.parent, _assertThisInitialized(_this));
    vars.scrollTrigger && _scrollTrigger(_assertThisInitialized(_this), vars.scrollTrigger);
    return _this;
  }

  var _proto2 = Timeline.prototype;

  _proto2.to = function to(targets, vars, position) {
    new Tween(targets, _parseVars(arguments, 0, this), _parsePosition(this, _isNumber(vars) ? arguments[3] : position));
    return this;
  };

  _proto2.from = function from(targets, vars, position) {
    new Tween(targets, _parseVars(arguments, 1, this), _parsePosition(this, _isNumber(vars) ? arguments[3] : position));
    return this;
  };

  _proto2.fromTo = function fromTo(targets, fromVars, toVars, position) {
    new Tween(targets, _parseVars(arguments, 2, this), _parsePosition(this, _isNumber(fromVars) ? arguments[4] : position));
    return this;
  };

  _proto2.set = function set(targets, vars, position) {
    vars.duration = 0;
    vars.parent = this;
    _inheritDefaults(vars).repeatDelay || (vars.repeat = 0);
    vars.immediateRender = !!vars.immediateRender;
    new Tween(targets, vars, _parsePosition(this, position), 1);
    return this;
  };

  _proto2.call = function call(callback, params, position) {
    return _addToTimeline(this, Tween.delayedCall(0, callback, params), _parsePosition(this, position));
  } //ONLY for backward compatibility! Maybe delete?
  ;

  _proto2.staggerTo = function staggerTo(targets, duration, vars, stagger, position, onCompleteAll, onCompleteAllParams) {
    vars.duration = duration;
    vars.stagger = vars.stagger || stagger;
    vars.onComplete = onCompleteAll;
    vars.onCompleteParams = onCompleteAllParams;
    vars.parent = this;
    new Tween(targets, vars, _parsePosition(this, position));
    return this;
  };

  _proto2.staggerFrom = function staggerFrom(targets, duration, vars, stagger, position, onCompleteAll, onCompleteAllParams) {
    vars.runBackwards = 1;
    _inheritDefaults(vars).immediateRender = _isNotFalse(vars.immediateRender);
    return this.staggerTo(targets, duration, vars, stagger, position, onCompleteAll, onCompleteAllParams);
  };

  _proto2.staggerFromTo = function staggerFromTo(targets, duration, fromVars, toVars, stagger, position, onCompleteAll, onCompleteAllParams) {
    toVars.startAt = fromVars;
    _inheritDefaults(toVars).immediateRender = _isNotFalse(toVars.immediateRender);
    return this.staggerTo(targets, duration, toVars, stagger, position, onCompleteAll, onCompleteAllParams);
  };

  _proto2.render = function render(totalTime, suppressEvents, force) {
    var prevTime = this._time,
        tDur = this._dirty ? this.totalDuration() : this._tDur,
        dur = this._dur,
        tTime = this !== _globalTimeline && totalTime > tDur - _tinyNum && totalTime >= 0 ? tDur : totalTime < _tinyNum ? 0 : totalTime,
        crossingStart = this._zTime < 0 !== totalTime < 0 && (this._initted || !dur),
        time,
        child,
        next,
        iteration,
        cycleDuration,
        prevPaused,
        pauseTween,
        timeScale,
        prevStart,
        prevIteration,
        yoyo,
        isYoyo;

    if (tTime !== this._tTime || force || crossingStart) {
      if (prevTime !== this._time && dur) {
        //if totalDuration() finds a child with a negative startTime and smoothChildTiming is true, things get shifted around internally so we need to adjust the time accordingly. For example, if a tween starts at -30 we must shift EVERYTHING forward 30 seconds and move this timeline's startTime backward by 30 seconds so that things align with the playhead (no jump).
        tTime += this._time - prevTime;
        totalTime += this._time - prevTime;
      }

      time = tTime;
      prevStart = this._start;
      timeScale = this._ts;
      prevPaused = !timeScale;

      if (crossingStart) {
        dur || (prevTime = this._zTime); //when the playhead arrives at EXACTLY time 0 (right on top) of a zero-duration timeline, we need to discern if events are suppressed so that when the playhead moves again (next time), it'll trigger the callback. If events are NOT suppressed, obviously the callback would be triggered in this render. Basically, the callback should fire either when the playhead ARRIVES or LEAVES this exact spot, not both. Imagine doing a timeline.seek(0) and there's a callback that sits at 0. Since events are suppressed on that seek() by default, nothing will fire, but when the playhead moves off of that position, the callback should fire. This behavior is what people intuitively expect.

        (totalTime || !suppressEvents) && (this._zTime = totalTime);
      }

      if (this._repeat) {
        //adjust the time for repeats and yoyos
        yoyo = this._yoyo;
        cycleDuration = dur + this._rDelay;
        time = _round(tTime % cycleDuration); //round to avoid floating point errors. (4 % 0.8 should be 0 but some browsers report it as 0.79999999!)

        if (tTime === tDur) {
          // the tDur === tTime is for edge cases where there's a lengthy decimal on the duration and it may reach the very end but the time is rendered as not-quite-there (remember, tDur is rounded to 4 decimals whereas dur isn't)
          iteration = this._repeat;
          time = dur;
        } else {
          iteration = ~~(tTime / cycleDuration);

          if (iteration && iteration === tTime / cycleDuration) {
            time = dur;
            iteration--;
          }

          time > dur && (time = dur);
        }

        prevIteration = _animationCycle(this._tTime, cycleDuration);
        !prevTime && this._tTime && prevIteration !== iteration && (prevIteration = iteration); // edge case - if someone does addPause() at the very beginning of a repeating timeline, that pause is technically at the same spot as the end which causes this._time to get set to 0 when the totalTime would normally place the playhead at the end. See https://greensock.com/forums/topic/23823-closing-nav-animation-not-working-on-ie-and-iphone-6-maybe-other-older-browser/?tab=comments#comment-113005

        if (yoyo && iteration & 1) {
          time = dur - time;
          isYoyo = 1;
        }
        /*
        make sure children at the end/beginning of the timeline are rendered properly. If, for example,
        a 3-second long timeline rendered at 2.9 seconds previously, and now renders at 3.2 seconds (which
        would get translated to 2.8 seconds if the timeline yoyos or 0.2 seconds if it just repeats), there
        could be a callback or a short tween that's at 2.95 or 3 seconds in which wouldn't render. So
        we need to push the timeline to the end (and/or beginning depending on its yoyo value). Also we must
        ensure that zero-duration tweens at the very beginning or end of the Timeline work.
        */


        if (iteration !== prevIteration && !this._lock) {
          var rewinding = yoyo && prevIteration & 1,
              doesWrap = rewinding === (yoyo && iteration & 1);
          iteration < prevIteration && (rewinding = !rewinding);
          prevTime = rewinding ? 0 : dur;
          this._lock = 1;
          this.render(prevTime || (isYoyo ? 0 : _round(iteration * cycleDuration)), suppressEvents, !dur)._lock = 0;
          !suppressEvents && this.parent && _callback(this, "onRepeat");
          this.vars.repeatRefresh && !isYoyo && (this.invalidate()._lock = 1);

          if (prevTime !== this._time || prevPaused !== !this._ts) {
            return this;
          }

          dur = this._dur; // in case the duration changed in the onRepeat

          tDur = this._tDur;

          if (doesWrap) {
            this._lock = 2;
            prevTime = rewinding ? dur : -0.0001;
            this.render(prevTime, true);
            this.vars.repeatRefresh && !isYoyo && this.invalidate();
          }

          this._lock = 0;

          if (!this._ts && !prevPaused) {
            return this;
          } //in order for yoyoEase to work properly when there's a stagger, we must swap out the ease in each sub-tween.


          _propagateYoyoEase(this, isYoyo);
        }
      }

      if (this._hasPause && !this._forcing && this._lock < 2) {
        pauseTween = _findNextPauseTween(this, _round(prevTime), _round(time));

        if (pauseTween) {
          tTime -= time - (time = pauseTween._start);
        }
      }

      this._tTime = tTime;
      this._time = time;
      this._act = !timeScale; //as long as it's not paused, force it to be active so that if the user renders independent of the parent timeline, it'll be forced to re-render on the next tick.

      if (!this._initted) {
        this._onUpdate = this.vars.onUpdate;
        this._initted = 1;
        this._zTime = totalTime;
      }

      !prevTime && time && !suppressEvents && _callback(this, "onStart");

      if (time >= prevTime && totalTime >= 0) {
        child = this._first;

        while (child) {
          next = child._next;

          if ((child._act || time >= child._start) && child._ts && pauseTween !== child) {
            if (child.parent !== this) {
              // an extreme edge case - the child's render could do something like kill() the "next" one in the linked list, or reparent it. In that case we must re-initiate the whole render to be safe.
              return this.render(totalTime, suppressEvents, force);
            }

            child.render(child._ts > 0 ? (time - child._start) * child._ts : (child._dirty ? child.totalDuration() : child._tDur) + (time - child._start) * child._ts, suppressEvents, force);

            if (time !== this._time || !this._ts && !prevPaused) {
              //in case a tween pauses or seeks the timeline when rendering, like inside of an onUpdate/onComplete
              pauseTween = 0;
              next && (tTime += this._zTime = -_tinyNum); // it didn't finish rendering, so flag zTime as negative so that so that the next time render() is called it'll be forced (to render any remaining children)

              break;
            }
          }

          child = next;
        }
      } else {
        child = this._last;
        var adjustedTime = totalTime < 0 ? totalTime : time; //when the playhead goes backward beyond the start of this timeline, we must pass that information down to the child animations so that zero-duration tweens know whether to render their starting or ending values.

        while (child) {
          next = child._prev;

          if ((child._act || adjustedTime <= child._end) && child._ts && pauseTween !== child) {
            if (child.parent !== this) {
              // an extreme edge case - the child's render could do something like kill() the "next" one in the linked list, or reparent it. In that case we must re-initiate the whole render to be safe.
              return this.render(totalTime, suppressEvents, force);
            }

            child.render(child._ts > 0 ? (adjustedTime - child._start) * child._ts : (child._dirty ? child.totalDuration() : child._tDur) + (adjustedTime - child._start) * child._ts, suppressEvents, force);

            if (time !== this._time || !this._ts && !prevPaused) {
              //in case a tween pauses or seeks the timeline when rendering, like inside of an onUpdate/onComplete
              pauseTween = 0;
              next && (tTime += this._zTime = adjustedTime ? -_tinyNum : _tinyNum); // it didn't finish rendering, so adjust zTime so that so that the next time render() is called it'll be forced (to render any remaining children)

              break;
            }
          }

          child = next;
        }
      }

      if (pauseTween && !suppressEvents) {
        this.pause();
        pauseTween.render(time >= prevTime ? 0 : -_tinyNum)._zTime = time >= prevTime ? 1 : -1;

        if (this._ts) {
          //the callback resumed playback! So since we may have held back the playhead due to where the pause is positioned, go ahead and jump to where it's SUPPOSED to be (if no pause happened).
          this._start = prevStart; //if the pause was at an earlier time and the user resumed in the callback, it could reposition the timeline (changing its startTime), throwing things off slightly, so we make sure the _start doesn't shift.

          _setEnd(this);

          return this.render(totalTime, suppressEvents, force);
        }
      }

      this._onUpdate && !suppressEvents && _callback(this, "onUpdate", true);
      if (tTime === tDur && tDur >= this.totalDuration() || !tTime && prevTime) if (prevStart === this._start || Math.abs(timeScale) !== Math.abs(this._ts)) if (!this._lock) {
        (totalTime || !dur) && (tTime === tDur && this._ts > 0 || !tTime && this._ts < 0) && _removeFromParent(this, 1); // don't remove if the timeline is reversed and the playhead isn't at 0, otherwise tl.progress(1).reverse() won't work. Only remove if the playhead is at the end and timeScale is positive, or if the playhead is at 0 and the timeScale is negative.

        if (!suppressEvents && !(totalTime < 0 && !prevTime) && (tTime || prevTime)) {
          _callback(this, tTime === tDur ? "onComplete" : "onReverseComplete", true);

          this._prom && !(tTime < tDur && this.timeScale() > 0) && this._prom();
        }
      }
    }

    return this;
  };

  _proto2.add = function add(child, position) {
    var _this2 = this;

    if (!_isNumber(position)) {
      position = _parsePosition(this, position);
    }

    if (!(child instanceof Animation)) {
      if (_isArray(child)) {
        child.forEach(function (obj) {
          return _this2.add(obj, position);
        });
        return this;
      }

      if (_isString(child)) {
        return this.addLabel(child, position);
      }

      if (_isFunction(child)) {
        child = Tween.delayedCall(0, child);
      } else {
        return this;
      }
    }

    return this !== child ? _addToTimeline(this, child, position) : this; //don't allow a timeline to be added to itself as a child!
  };

  _proto2.getChildren = function getChildren(nested, tweens, timelines, ignoreBeforeTime) {
    if (nested === void 0) {
      nested = true;
    }

    if (tweens === void 0) {
      tweens = true;
    }

    if (timelines === void 0) {
      timelines = true;
    }

    if (ignoreBeforeTime === void 0) {
      ignoreBeforeTime = -_bigNum;
    }

    var a = [],
        child = this._first;

    while (child) {
      if (child._start >= ignoreBeforeTime) {
        if (child instanceof Tween) {
          tweens && a.push(child);
        } else {
          timelines && a.push(child);
          nested && a.push.apply(a, child.getChildren(true, tweens, timelines));
        }
      }

      child = child._next;
    }

    return a;
  };

  _proto2.getById = function getById(id) {
    var animations = this.getChildren(1, 1, 1),
        i = animations.length;

    while (i--) {
      if (animations[i].vars.id === id) {
        return animations[i];
      }
    }
  };

  _proto2.remove = function remove(child) {
    if (_isString(child)) {
      return this.removeLabel(child);
    }

    if (_isFunction(child)) {
      return this.killTweensOf(child);
    }

    _removeLinkedListItem(this, child);

    if (child === this._recent) {
      this._recent = this._last;
    }

    return _uncache(this);
  };

  _proto2.totalTime = function totalTime(_totalTime2, suppressEvents) {
    if (!arguments.length) {
      return this._tTime;
    }

    this._forcing = 1;

    if (!this._dp && this._ts) {
      //special case for the global timeline (or any other that has no parent or detached parent).
      this._start = _round(_ticker.time - (this._ts > 0 ? _totalTime2 / this._ts : (this.totalDuration() - _totalTime2) / -this._ts));
    }

    _Animation.prototype.totalTime.call(this, _totalTime2, suppressEvents);

    this._forcing = 0;
    return this;
  };

  _proto2.addLabel = function addLabel(label, position) {
    this.labels[label] = _parsePosition(this, position);
    return this;
  };

  _proto2.removeLabel = function removeLabel(label) {
    delete this.labels[label];
    return this;
  };

  _proto2.addPause = function addPause(position, callback, params) {
    var t = Tween.delayedCall(0, callback || _emptyFunc, params);
    t.data = "isPause";
    this._hasPause = 1;
    return _addToTimeline(this, t, _parsePosition(this, position));
  };

  _proto2.removePause = function removePause(position) {
    var child = this._first;
    position = _parsePosition(this, position);

    while (child) {
      if (child._start === position && child.data === "isPause") {
        _removeFromParent(child);
      }

      child = child._next;
    }
  };

  _proto2.killTweensOf = function killTweensOf(targets, props, onlyActive) {
    var tweens = this.getTweensOf(targets, onlyActive),
        i = tweens.length;

    while (i--) {
      _overwritingTween !== tweens[i] && tweens[i].kill(targets, props);
    }

    return this;
  };

  _proto2.getTweensOf = function getTweensOf(targets, onlyActive) {
    var a = [],
        parsedTargets = toArray(targets),
        child = this._first,
        isGlobalTime = _isNumber(onlyActive),
        // a number is interpreted as a global time. If the animation spans
    children;

    while (child) {
      if (child instanceof Tween) {
        if (_arrayContainsAny(child._targets, parsedTargets) && (isGlobalTime ? (!_overwritingTween || child._initted && child._ts) && child.globalTime(0) <= onlyActive && child.globalTime(child.totalDuration()) > onlyActive : !onlyActive || child.isActive())) {
          // note: if this is for overwriting, it should only be for tweens that aren't paused and are initted.
          a.push(child);
        }
      } else if ((children = child.getTweensOf(parsedTargets, onlyActive)).length) {
        a.push.apply(a, children);
      }

      child = child._next;
    }

    return a;
  };

  _proto2.tweenTo = function tweenTo(position, vars) {
    vars = vars || {};

    var tl = this,
        endTime = _parsePosition(tl, position),
        _vars = vars,
        startAt = _vars.startAt,
        _onStart = _vars.onStart,
        onStartParams = _vars.onStartParams,
        tween = Tween.to(tl, _setDefaults(vars, {
      ease: "none",
      lazy: false,
      time: endTime,
      overwrite: "auto",
      duration: vars.duration || Math.abs((endTime - (startAt && "time" in startAt ? startAt.time : tl._time)) / tl.timeScale()) || _tinyNum,
      onStart: function onStart() {
        tl.pause();
        var duration = vars.duration || Math.abs((endTime - tl._time) / tl.timeScale());
        tween._dur !== duration && _setDuration(tween, duration, 0, 1).render(tween._time, true, true);
        _onStart && _onStart.apply(tween, onStartParams || []); //in case the user had an onStart in the vars - we don't want to overwrite it.
      }
    }));

    return tween;
  };

  _proto2.tweenFromTo = function tweenFromTo(fromPosition, toPosition, vars) {
    return this.tweenTo(toPosition, _setDefaults({
      startAt: {
        time: _parsePosition(this, fromPosition)
      }
    }, vars));
  };

  _proto2.recent = function recent() {
    return this._recent;
  };

  _proto2.nextLabel = function nextLabel(afterTime) {
    if (afterTime === void 0) {
      afterTime = this._time;
    }

    return _getLabelInDirection(this, _parsePosition(this, afterTime));
  };

  _proto2.previousLabel = function previousLabel(beforeTime) {
    if (beforeTime === void 0) {
      beforeTime = this._time;
    }

    return _getLabelInDirection(this, _parsePosition(this, beforeTime), 1);
  };

  _proto2.currentLabel = function currentLabel(value) {
    return arguments.length ? this.seek(value, true) : this.previousLabel(this._time + _tinyNum);
  };

  _proto2.shiftChildren = function shiftChildren(amount, adjustLabels, ignoreBeforeTime) {
    if (ignoreBeforeTime === void 0) {
      ignoreBeforeTime = 0;
    }

    var child = this._first,
        labels = this.labels,
        p;

    while (child) {
      if (child._start >= ignoreBeforeTime) {
        child._start += amount;
        child._end += amount;
      }

      child = child._next;
    }

    if (adjustLabels) {
      for (p in labels) {
        if (labels[p] >= ignoreBeforeTime) {
          labels[p] += amount;
        }
      }
    }

    return _uncache(this);
  };

  _proto2.invalidate = function invalidate() {
    var child = this._first;
    this._lock = 0;

    while (child) {
      child.invalidate();
      child = child._next;
    }

    return _Animation.prototype.invalidate.call(this);
  };

  _proto2.clear = function clear(includeLabels) {
    if (includeLabels === void 0) {
      includeLabels = true;
    }

    var child = this._first,
        next;

    while (child) {
      next = child._next;
      this.remove(child);
      child = next;
    }

    this._time = this._tTime = this._pTime = 0;
    includeLabels && (this.labels = {});
    return _uncache(this);
  };

  _proto2.totalDuration = function totalDuration(value) {
    var max = 0,
        self = this,
        child = self._last,
        prevStart = _bigNum,
        prev,
        start,
        parent;

    if (arguments.length) {
      return self.timeScale((self._repeat < 0 ? self.duration() : self.totalDuration()) / (self.reversed() ? -value : value));
    }

    if (self._dirty) {
      parent = self.parent;

      while (child) {
        prev = child._prev; //record it here in case the tween changes position in the sequence...

        child._dirty && child.totalDuration(); //could change the tween._startTime, so make sure the animation's cache is clean before analyzing it.

        start = child._start;

        if (start > prevStart && self._sort && child._ts && !self._lock) {
          //in case one of the tweens shifted out of order, it needs to be re-inserted into the correct position in the sequence
          self._lock = 1; //prevent endless recursive calls - there are methods that get triggered that check duration/totalDuration when we add().

          _addToTimeline(self, child, start - child._delay, 1)._lock = 0;
        } else {
          prevStart = start;
        }

        if (start < 0 && child._ts) {
          //children aren't allowed to have negative startTimes unless smoothChildTiming is true, so adjust here if one is found.
          max -= start;

          if (!parent && !self._dp || parent && parent.smoothChildTiming) {
            self._start += start / self._ts;
            self._time -= start;
            self._tTime -= start;
          }

          self.shiftChildren(-start, false, -1e999);
          prevStart = 0;
        }

        child._end > max && child._ts && (max = child._end);
        child = prev;
      }

      _setDuration(self, self === _globalTimeline && self._time > max ? self._time : max, 1, 1);

      self._dirty = 0;
    }

    return self._tDur;
  };

  Timeline.updateRoot = function updateRoot(time) {
    if (_globalTimeline._ts) {
      _lazySafeRender(_globalTimeline, _parentToChildTotalTime(time, _globalTimeline));

      _lastRenderedFrame = _ticker.frame;
    }

    if (_ticker.frame >= _nextGCFrame) {
      _nextGCFrame += _config.autoSleep || 120;
      var child = _globalTimeline._first;
      if (!child || !child._ts) if (_config.autoSleep && _ticker._listeners.length < 2) {
        while (child && !child._ts) {
          child = child._next;
        }

        child || _ticker.sleep();
      }
    }
  };

  return Timeline;
}(Animation);

_setDefaults(Timeline.prototype, {
  _lock: 0,
  _hasPause: 0,
  _forcing: 0
});

var _addComplexStringPropTween = function _addComplexStringPropTween(target, prop, start, end, setter, stringFilter, funcParam) {
  //note: we call _addComplexStringPropTween.call(tweenInstance...) to ensure that it's scoped properly. We may call it from within a plugin too, thus "this" would refer to the plugin.
  var pt = new PropTween(this._pt, target, prop, 0, 1, _renderComplexString, null, setter),
      index = 0,
      matchIndex = 0,
      result,
      startNums,
      color,
      endNum,
      chunk,
      startNum,
      hasRandom,
      a;
  pt.b = start;
  pt.e = end;
  start += ""; //ensure values are strings

  end += "";

  if (hasRandom = ~end.indexOf("random(")) {
    end = _replaceRandom(end);
  }

  if (stringFilter) {
    a = [start, end];
    stringFilter(a, target, prop); //pass an array with the starting and ending values and let the filter do whatever it needs to the values.

    start = a[0];
    end = a[1];
  }

  startNums = start.match(_complexStringNumExp) || [];

  while (result = _complexStringNumExp.exec(end)) {
    endNum = result[0];
    chunk = end.substring(index, result.index);

    if (color) {
      color = (color + 1) % 5;
    } else if (chunk.substr(-5) === "rgba(") {
      color = 1;
    }

    if (endNum !== startNums[matchIndex++]) {
      startNum = parseFloat(startNums[matchIndex - 1]) || 0; //these nested PropTweens are handled in a special way - we'll never actually call a render or setter method on them. We'll just loop through them in the parent complex string PropTween's render method.

      pt._pt = {
        _next: pt._pt,
        p: chunk || matchIndex === 1 ? chunk : ",",
        //note: SVG spec allows omission of comma/space when a negative sign is wedged between two numbers, like 2.5-5.3 instead of 2.5,-5.3 but when tweening, the negative value may switch to positive, so we insert the comma just in case.
        s: startNum,
        c: endNum.charAt(1) === "=" ? parseFloat(endNum.substr(2)) * (endNum.charAt(0) === "-" ? -1 : 1) : parseFloat(endNum) - startNum,
        m: color && color < 4 ? Math.round : 0
      };
      index = _complexStringNumExp.lastIndex;
    }
  }

  pt.c = index < end.length ? end.substring(index, end.length) : ""; //we use the "c" of the PropTween to store the final part of the string (after the last number)

  pt.fp = funcParam;

  if (_relExp.test(end) || hasRandom) {
    pt.e = 0; //if the end string contains relative values or dynamic random(...) values, delete the end it so that on the final render we don't actually set it to the string with += or -= characters (forces it to use the calculated value).
  }

  this._pt = pt; //start the linked list with this new PropTween. Remember, we call _addComplexStringPropTween.call(tweenInstance...) to ensure that it's scoped properly. We may call it from within a plugin too, thus "this" would refer to the plugin.

  return pt;
},
    _addPropTween = function _addPropTween(target, prop, start, end, index, targets, modifier, stringFilter, funcParam) {
  _isFunction(end) && (end = end(index || 0, target, targets));
  var currentValue = target[prop],
      parsedStart = start !== "get" ? start : !_isFunction(currentValue) ? currentValue : funcParam ? target[prop.indexOf("set") || !_isFunction(target["get" + prop.substr(3)]) ? prop : "get" + prop.substr(3)](funcParam) : target[prop](),
      setter = !_isFunction(currentValue) ? _setterPlain : funcParam ? _setterFuncWithParam : _setterFunc,
      pt;

  if (_isString(end)) {
    if (~end.indexOf("random(")) {
      end = _replaceRandom(end);
    }

    if (end.charAt(1) === "=") {
      end = parseFloat(parsedStart) + parseFloat(end.substr(2)) * (end.charAt(0) === "-" ? -1 : 1) + (getUnit(parsedStart) || 0);
    }
  }

  if (parsedStart !== end) {
    if (!isNaN(parsedStart * end)) {
      pt = new PropTween(this._pt, target, prop, +parsedStart || 0, end - (parsedStart || 0), typeof currentValue === "boolean" ? _renderBoolean : _renderPlain, 0, setter);
      funcParam && (pt.fp = funcParam);
      modifier && pt.modifier(modifier, this, target);
      return this._pt = pt;
    }

    !currentValue && !(prop in target) && _missingPlugin(prop, end);
    return _addComplexStringPropTween.call(this, target, prop, parsedStart, end, setter, stringFilter || _config.stringFilter, funcParam);
  }
},
    //creates a copy of the vars object and processes any function-based values (putting the resulting values directly into the copy) as well as strings with "random()" in them. It does NOT process relative values.
_processVars = function _processVars(vars, index, target, targets, tween) {
  _isFunction(vars) && (vars = _parseFuncOrString(vars, tween, index, target, targets));

  if (!_isObject(vars) || vars.style && vars.nodeType || _isArray(vars) || _isTypedArray(vars)) {
    return _isString(vars) ? _parseFuncOrString(vars, tween, index, target, targets) : vars;
  }

  var copy = {},
      p;

  for (p in vars) {
    copy[p] = _parseFuncOrString(vars[p], tween, index, target, targets);
  }

  return copy;
},
    _checkPlugin = function _checkPlugin(property, vars, tween, index, target, targets) {
  var plugin, pt, ptLookup, i;

  if (_plugins[property] && (plugin = new _plugins[property]()).init(target, plugin.rawVars ? vars[property] : _processVars(vars[property], index, target, targets, tween), tween, index, targets) !== false) {
    tween._pt = pt = new PropTween(tween._pt, target, property, 0, 1, plugin.render, plugin, 0, plugin.priority);

    if (tween !== _quickTween) {
      ptLookup = tween._ptLookup[tween._targets.indexOf(target)]; //note: we can't use tween._ptLookup[index] because for staggered tweens, the index from the fullTargets array won't match what it is in each individual tween that spawns from the stagger.

      i = plugin._props.length;

      while (i--) {
        ptLookup[plugin._props[i]] = pt;
      }
    }
  }

  return plugin;
},
    _overwritingTween,
    //store a reference temporarily so we can avoid overwriting itself.
_initTween = function _initTween(tween, time) {
  var vars = tween.vars,
      ease = vars.ease,
      startAt = vars.startAt,
      immediateRender = vars.immediateRender,
      lazy = vars.lazy,
      onUpdate = vars.onUpdate,
      onUpdateParams = vars.onUpdateParams,
      callbackScope = vars.callbackScope,
      runBackwards = vars.runBackwards,
      yoyoEase = vars.yoyoEase,
      keyframes = vars.keyframes,
      autoRevert = vars.autoRevert,
      dur = tween._dur,
      prevStartAt = tween._startAt,
      targets = tween._targets,
      parent = tween.parent,
      fullTargets = parent && parent.data === "nested" ? parent.parent._targets : targets,
      autoOverwrite = tween._overwrite === "auto",
      tl = tween.timeline,
      cleanVars,
      i,
      p,
      pt,
      target,
      hasPriority,
      gsData,
      harness,
      plugin,
      ptLookup,
      index,
      harnessVars,
      overwritten;
  tl && (!keyframes || !ease) && (ease = "none");
  tween._ease = _parseEase(ease, _defaults.ease);
  tween._yEase = yoyoEase ? _invertEase(_parseEase(yoyoEase === true ? ease : yoyoEase, _defaults.ease)) : 0;

  if (yoyoEase && tween._yoyo && !tween._repeat) {
    //there must have been a parent timeline with yoyo:true that is currently in its yoyo phase, so flip the eases.
    yoyoEase = tween._yEase;
    tween._yEase = tween._ease;
    tween._ease = yoyoEase;
  }

  if (!tl) {
    //if there's an internal timeline, skip all the parsing because we passed that task down the chain.
    harness = targets[0] ? _getCache(targets[0]).harness : 0;
    harnessVars = harness && vars[harness.prop]; //someone may need to specify CSS-specific values AND non-CSS values, like if the element has an "x" property plus it's a standard DOM element. We allow people to distinguish by wrapping plugin-specific stuff in a css:{} object for example.

    cleanVars = _copyExcluding(vars, _reservedProps);
    prevStartAt && prevStartAt.render(-1, true).kill();

    if (startAt) {
      _removeFromParent(tween._startAt = Tween.set(targets, _setDefaults({
        data: "isStart",
        overwrite: false,
        parent: parent,
        immediateRender: true,
        lazy: _isNotFalse(lazy),
        startAt: null,
        delay: 0,
        onUpdate: onUpdate,
        onUpdateParams: onUpdateParams,
        callbackScope: callbackScope,
        stagger: 0
      }, startAt))); //copy the properties/values into a new object to avoid collisions, like var to = {x:0}, from = {x:500}; timeline.fromTo(e, from, to).fromTo(e, to, from);


      if (immediateRender) {
        if (time > 0) {
          autoRevert || (tween._startAt = 0); //tweens that render immediately (like most from() and fromTo() tweens) shouldn't revert when their parent timeline's playhead goes backward past the startTime because the initial render could have happened anytime and it shouldn't be directly correlated to this tween's startTime. Imagine setting up a complex animation where the beginning states of various objects are rendered immediately but the tween doesn't happen for quite some time - if we revert to the starting values as soon as the playhead goes backward past the tween's startTime, it will throw things off visually. Reversion should only happen in Timeline instances where immediateRender was false or when autoRevert is explicitly set to true.
        } else if (dur && !(time < 0 && prevStartAt)) {
          time && (tween._zTime = time);
          return; //we skip initialization here so that overwriting doesn't occur until the tween actually begins. Otherwise, if you create several immediateRender:true tweens of the same target/properties to drop into a Timeline, the last one created would overwrite the first ones because they didn't get placed into the timeline yet before the first render occurs and kicks in overwriting.
        }
      }
    } else if (runBackwards && dur) {
      //from() tweens must be handled uniquely: their beginning values must be rendered but we don't want overwriting to occur yet (when time is still 0). Wait until the tween actually begins before doing all the routines like overwriting. At that time, we should render at the END of the tween to ensure that things initialize correctly (remember, from() tweens go backwards)
      if (prevStartAt) {
        !autoRevert && (tween._startAt = 0);
      } else {
        time && (immediateRender = false); //in rare cases (like if a from() tween runs and then is invalidate()-ed), immediateRender could be true but the initial forced-render gets skipped, so there's no need to force the render in this context when the _time is greater than 0

        p = _setDefaults({
          overwrite: false,
          data: "isFromStart",
          //we tag the tween with as "isFromStart" so that if [inside a plugin] we need to only do something at the very END of a tween, we have a way of identifying this tween as merely the one that's setting the beginning values for a "from()" tween. For example, clearProps in CSSPlugin should only get applied at the very END of a tween and without this tag, from(...{height:100, clearProps:"height", delay:1}) would wipe the height at the beginning of the tween and after 1 second, it'd kick back in.
          lazy: immediateRender && _isNotFalse(lazy),
          immediateRender: immediateRender,
          //zero-duration tweens render immediately by default, but if we're not specifically instructed to render this tween immediately, we should skip this and merely _init() to record the starting values (rendering them immediately would push them to completion which is wasteful in that case - we'd have to render(-1) immediately after)
          stagger: 0,
          parent: parent //ensures that nested tweens that had a stagger are handled properly, like gsap.from(".class", {y:gsap.utils.wrap([-100,100])})

        }, cleanVars);
        harnessVars && (p[harness.prop] = harnessVars); // in case someone does something like .from(..., {css:{}})

        _removeFromParent(tween._startAt = Tween.set(targets, p));

        if (!immediateRender) {
          _initTween(tween._startAt, _tinyNum); //ensures that the initial values are recorded

        } else if (!time) {
          return;
        }
      }
    }

    tween._pt = 0;
    lazy = dur && _isNotFalse(lazy) || lazy && !dur;

    for (i = 0; i < targets.length; i++) {
      target = targets[i];
      gsData = target._gsap || _harness(targets)[i]._gsap;
      tween._ptLookup[i] = ptLookup = {};
      _lazyLookup[gsData.id] && _lazyTweens.length && _lazyRender(); //if other tweens of the same target have recently initted but haven't rendered yet, we've got to force the render so that the starting values are correct (imagine populating a timeline with a bunch of sequential tweens and then jumping to the end)

      index = fullTargets === targets ? i : fullTargets.indexOf(target);

      if (harness && (plugin = new harness()).init(target, harnessVars || cleanVars, tween, index, fullTargets) !== false) {
        tween._pt = pt = new PropTween(tween._pt, target, plugin.name, 0, 1, plugin.render, plugin, 0, plugin.priority);

        plugin._props.forEach(function (name) {
          ptLookup[name] = pt;
        });

        plugin.priority && (hasPriority = 1);
      }

      if (!harness || harnessVars) {
        for (p in cleanVars) {
          if (_plugins[p] && (plugin = _checkPlugin(p, cleanVars, tween, index, target, fullTargets))) {
            plugin.priority && (hasPriority = 1);
          } else {
            ptLookup[p] = pt = _addPropTween.call(tween, target, p, "get", cleanVars[p], index, fullTargets, 0, vars.stringFilter);
          }
        }
      }

      tween._op && tween._op[i] && tween.kill(target, tween._op[i]);

      if (autoOverwrite && tween._pt) {
        _overwritingTween = tween;

        _globalTimeline.killTweensOf(target, ptLookup, tween.globalTime(0)); //Also make sure the overwriting doesn't overwrite THIS tween!!!


        overwritten = !tween.parent;
        _overwritingTween = 0;
      }

      tween._pt && lazy && (_lazyLookup[gsData.id] = 1);
    }

    hasPriority && _sortPropTweensByPriority(tween);
    tween._onInit && tween._onInit(tween); //plugins like RoundProps must wait until ALL of the PropTweens are instantiated. In the plugin's init() function, it sets the _onInit on the tween instance. May not be pretty/intuitive, but it's fast and keeps file size down.
  }

  tween._from = !tl && !!vars.runBackwards; //nested timelines should never run backwards - the backwards-ness is in the child tweens.

  tween._onUpdate = onUpdate;
  tween._initted = (!tween._op || tween._pt) && !overwritten; // if overwrittenProps resulted in the entire tween being killed, do NOT flag it as initted or else it may render for one tick.
},
    _addAliasesToVars = function _addAliasesToVars(targets, vars) {
  var harness = targets[0] ? _getCache(targets[0]).harness : 0,
      propertyAliases = harness && harness.aliases,
      copy,
      p,
      i,
      aliases;

  if (!propertyAliases) {
    return vars;
  }

  copy = _merge({}, vars);

  for (p in propertyAliases) {
    if (p in copy) {
      aliases = propertyAliases[p].split(",");
      i = aliases.length;

      while (i--) {
        copy[aliases[i]] = copy[p];
      }
    }
  }

  return copy;
},
    _parseFuncOrString = function _parseFuncOrString(value, tween, i, target, targets) {
  return _isFunction(value) ? value.call(tween, i, target, targets) : _isString(value) && ~value.indexOf("random(") ? _replaceRandom(value) : value;
},
    _staggerTweenProps = _callbackNames + "repeat,repeatDelay,yoyo,repeatRefresh,yoyoEase",
    _staggerPropsToSkip = (_staggerTweenProps + ",id,stagger,delay,duration,paused,scrollTrigger").split(",");
/*
 * --------------------------------------------------------------------------------------
 * TWEEN
 * --------------------------------------------------------------------------------------
 */


var Tween = /*#__PURE__*/function (_Animation2) {
  _inheritsLoose(Tween, _Animation2);

  function Tween(targets, vars, time, skipInherit) {
    var _this3;

    if (typeof vars === "number") {
      time.duration = vars;
      vars = time;
      time = null;
    }

    _this3 = _Animation2.call(this, skipInherit ? vars : _inheritDefaults(vars), time) || this;
    var _this3$vars = _this3.vars,
        duration = _this3$vars.duration,
        delay = _this3$vars.delay,
        immediateRender = _this3$vars.immediateRender,
        stagger = _this3$vars.stagger,
        overwrite = _this3$vars.overwrite,
        keyframes = _this3$vars.keyframes,
        defaults = _this3$vars.defaults,
        scrollTrigger = _this3$vars.scrollTrigger,
        yoyoEase = _this3$vars.yoyoEase,
        parent = _this3.parent,
        parsedTargets = (_isArray(targets) || _isTypedArray(targets) ? _isNumber(targets[0]) : "length" in vars) ? [targets] : toArray(targets),
        tl,
        i,
        copy,
        l,
        p,
        curTarget,
        staggerFunc,
        staggerVarsToMerge;
    _this3._targets = parsedTargets.length ? _harness(parsedTargets) : _warn("GSAP target " + targets + " not found. https://greensock.com", !_config.nullTargetWarn) || [];
    _this3._ptLookup = []; //PropTween lookup. An array containing an object for each target, having keys for each tweening property

    _this3._overwrite = overwrite;

    if (keyframes || stagger || _isFuncOrString(duration) || _isFuncOrString(delay)) {
      vars = _this3.vars;
      tl = _this3.timeline = new Timeline({
        data: "nested",
        defaults: defaults || {}
      });
      tl.kill();
      tl.parent = _assertThisInitialized(_this3);

      if (keyframes) {
        _setDefaults(tl.vars.defaults, {
          ease: "none"
        });

        keyframes.forEach(function (frame) {
          return tl.to(parsedTargets, frame, ">");
        });
      } else {
        l = parsedTargets.length;
        staggerFunc = stagger ? distribute(stagger) : _emptyFunc;

        if (_isObject(stagger)) {
          //users can pass in callbacks like onStart/onComplete in the stagger object. These should fire with each individual tween.
          for (p in stagger) {
            if (~_staggerTweenProps.indexOf(p)) {
              staggerVarsToMerge || (staggerVarsToMerge = {});
              staggerVarsToMerge[p] = stagger[p];
            }
          }
        }

        for (i = 0; i < l; i++) {
          copy = {};

          for (p in vars) {
            if (_staggerPropsToSkip.indexOf(p) < 0) {
              copy[p] = vars[p];
            }
          }

          copy.stagger = 0;
          yoyoEase && (copy.yoyoEase = yoyoEase);
          staggerVarsToMerge && _merge(copy, staggerVarsToMerge);
          curTarget = parsedTargets[i]; //don't just copy duration or delay because if they're a string or function, we'd end up in an infinite loop because _isFuncOrString() would evaluate as true in the child tweens, entering this loop, etc. So we parse the value straight from vars and default to 0.

          copy.duration = +_parseFuncOrString(duration, _assertThisInitialized(_this3), i, curTarget, parsedTargets);
          copy.delay = (+_parseFuncOrString(delay, _assertThisInitialized(_this3), i, curTarget, parsedTargets) || 0) - _this3._delay;

          if (!stagger && l === 1 && copy.delay) {
            // if someone does delay:"random(1, 5)", repeat:-1, for example, the delay shouldn't be inside the repeat.
            _this3._delay = delay = copy.delay;
            _this3._start += delay;
            copy.delay = 0;
          }

          tl.to(curTarget, copy, staggerFunc(i, curTarget, parsedTargets));
        }

        tl.duration() ? duration = delay = 0 : _this3.timeline = 0; // if the timeline's duration is 0, we don't need a timeline internally!
      }

      duration || _this3.duration(duration = tl.duration());
    } else {
      _this3.timeline = 0; //speed optimization, faster lookups (no going up the prototype chain)
    }

    if (overwrite === true) {
      _overwritingTween = _assertThisInitialized(_this3);

      _globalTimeline.killTweensOf(parsedTargets);

      _overwritingTween = 0;
    }

    parent && _postAddChecks(parent, _assertThisInitialized(_this3));

    if (immediateRender || !duration && !keyframes && _this3._start === _round(parent._time) && _isNotFalse(immediateRender) && _hasNoPausedAncestors(_assertThisInitialized(_this3)) && parent.data !== "nested") {
      _this3._tTime = -_tinyNum; //forces a render without having to set the render() "force" parameter to true because we want to allow lazying by default (using the "force" parameter always forces an immediate full render)

      _this3.render(Math.max(0, -delay)); //in case delay is negative

    }

    scrollTrigger && _scrollTrigger(_assertThisInitialized(_this3), scrollTrigger);
    return _this3;
  }

  var _proto3 = Tween.prototype;

  _proto3.render = function render(totalTime, suppressEvents, force) {
    var prevTime = this._time,
        tDur = this._tDur,
        dur = this._dur,
        tTime = totalTime > tDur - _tinyNum && totalTime >= 0 ? tDur : totalTime < _tinyNum ? 0 : totalTime,
        time,
        pt,
        iteration,
        cycleDuration,
        prevIteration,
        isYoyo,
        ratio,
        timeline,
        yoyoEase;

    if (!dur) {
      _renderZeroDurationTween(this, totalTime, suppressEvents, force);
    } else if (tTime !== this._tTime || !totalTime || force || this._startAt && this._zTime < 0 !== totalTime < 0) {
      //this senses if we're crossing over the start time, in which case we must record _zTime and force the render, but we do it in this lengthy conditional way for performance reasons (usually we can skip the calculations): this._initted && (this._zTime < 0) !== (totalTime < 0)
      time = tTime;
      timeline = this.timeline;

      if (this._repeat) {
        //adjust the time for repeats and yoyos
        cycleDuration = dur + this._rDelay;
        time = _round(tTime % cycleDuration); //round to avoid floating point errors. (4 % 0.8 should be 0 but some browsers report it as 0.79999999!)

        if (tTime === tDur) {
          // the tDur === tTime is for edge cases where there's a lengthy decimal on the duration and it may reach the very end but the time is rendered as not-quite-there (remember, tDur is rounded to 4 decimals whereas dur isn't)
          iteration = this._repeat;
          time = dur;
        } else {
          iteration = ~~(tTime / cycleDuration);

          if (iteration && iteration === tTime / cycleDuration) {
            time = dur;
            iteration--;
          }

          time > dur && (time = dur);
        }

        isYoyo = this._yoyo && iteration & 1;

        if (isYoyo) {
          yoyoEase = this._yEase;
          time = dur - time;
        }

        prevIteration = _animationCycle(this._tTime, cycleDuration);

        if (time === prevTime && !force && this._initted) {
          //could be during the repeatDelay part. No need to render and fire callbacks.
          return this;
        }

        if (iteration !== prevIteration) {
          timeline && this._yEase && _propagateYoyoEase(timeline, isYoyo); //repeatRefresh functionality

          if (this.vars.repeatRefresh && !isYoyo && !this._lock) {
            this._lock = force = 1; //force, otherwise if lazy is true, the _attemptInitTween() will return and we'll jump out and get caught bouncing on each tick.

            this.render(_round(cycleDuration * iteration), true).invalidate()._lock = 0;
          }
        }
      }

      if (!this._initted) {
        if (_attemptInitTween(this, totalTime < 0 ? totalTime : time, force, suppressEvents)) {
          this._tTime = 0; // in constructor if immediateRender is true, we set _tTime to -_tinyNum to have the playhead cross the starting point but we can't leave _tTime as a negative number.

          return this;
        }

        if (dur !== this._dur) {
          // while initting, a plugin like InertiaPlugin might alter the duration, so rerun from the start to ensure everything renders as it should.
          return this.render(totalTime, suppressEvents, force);
        }
      }

      this._tTime = tTime;
      this._time = time;

      if (!this._act && this._ts) {
        this._act = 1; //as long as it's not paused, force it to be active so that if the user renders independent of the parent timeline, it'll be forced to re-render on the next tick.

        this._lazy = 0;
      }

      this.ratio = ratio = (yoyoEase || this._ease)(time / dur);

      if (this._from) {
        this.ratio = ratio = 1 - ratio;
      }

      time && !prevTime && !suppressEvents && _callback(this, "onStart");
      pt = this._pt;

      while (pt) {
        pt.r(ratio, pt.d);
        pt = pt._next;
      }

      timeline && timeline.render(totalTime < 0 ? totalTime : !time && isYoyo ? -_tinyNum : timeline._dur * ratio, suppressEvents, force) || this._startAt && (this._zTime = totalTime);

      if (this._onUpdate && !suppressEvents) {
        totalTime < 0 && this._startAt && this._startAt.render(totalTime, true, force); //note: for performance reasons, we tuck this conditional logic inside less traveled areas (most tweens don't have an onUpdate). We'd just have it at the end before the onComplete, but the values should be updated before any onUpdate is called, so we ALSO put it here and then if it's not called, we do so later near the onComplete.

        _callback(this, "onUpdate");
      }

      this._repeat && iteration !== prevIteration && this.vars.onRepeat && !suppressEvents && this.parent && _callback(this, "onRepeat");

      if ((tTime === this._tDur || !tTime) && this._tTime === tTime) {
        totalTime < 0 && this._startAt && !this._onUpdate && this._startAt.render(totalTime, true, true);
        (totalTime || !dur) && (tTime === this._tDur && this._ts > 0 || !tTime && this._ts < 0) && _removeFromParent(this, 1); // don't remove if we're rendering at exactly a time of 0, as there could be autoRevert values that should get set on the next tick (if the playhead goes backward beyond the startTime, negative totalTime). Don't remove if the timeline is reversed and the playhead isn't at 0, otherwise tl.progress(1).reverse() won't work. Only remove if the playhead is at the end and timeScale is positive, or if the playhead is at 0 and the timeScale is negative.

        if (!suppressEvents && !(totalTime < 0 && !prevTime) && (tTime || prevTime)) {
          // if prevTime and tTime are zero, we shouldn't fire the onReverseComplete. This could happen if you gsap.to(... {paused:true}).play();
          _callback(this, tTime === tDur ? "onComplete" : "onReverseComplete", true);

          this._prom && !(tTime < tDur && this.timeScale() > 0) && this._prom();
        }
      }
    }

    return this;
  };

  _proto3.targets = function targets() {
    return this._targets;
  };

  _proto3.invalidate = function invalidate() {
    this._pt = this._op = this._startAt = this._onUpdate = this._act = this._lazy = 0;
    this._ptLookup = [];
    this.timeline && this.timeline.invalidate();
    return _Animation2.prototype.invalidate.call(this);
  };

  _proto3.kill = function kill(targets, vars) {
    if (vars === void 0) {
      vars = "all";
    }

    if (!targets && (!vars || vars === "all")) {
      this._lazy = 0;

      if (this.parent) {
        return _interrupt(this);
      }
    }

    if (this.timeline) {
      var tDur = this.timeline.totalDuration();
      this.timeline.killTweensOf(targets, vars, _overwritingTween && _overwritingTween.vars.overwrite !== true)._first || _interrupt(this); // if nothing is left tweenng, interrupt.

      this.parent && tDur !== this.timeline.totalDuration() && _setDuration(this, this._dur * this.timeline._tDur / tDur, 0, 1); // if a nested tween is killed that changes the duration, it should affect this tween's duration. We must use the ratio, though, because sometimes the internal timeline is stretched like for keyframes where they don't all add up to whatever the parent tween's duration was set to.

      return this;
    }

    var parsedTargets = this._targets,
        killingTargets = targets ? toArray(targets) : parsedTargets,
        propTweenLookup = this._ptLookup,
        firstPT = this._pt,
        overwrittenProps,
        curLookup,
        curOverwriteProps,
        props,
        p,
        pt,
        i;

    if ((!vars || vars === "all") && _arraysMatch(parsedTargets, killingTargets)) {
      vars === "all" && (this._pt = 0);
      return _interrupt(this);
    }

    overwrittenProps = this._op = this._op || [];

    if (vars !== "all") {
      //so people can pass in a comma-delimited list of property names
      if (_isString(vars)) {
        p = {};

        _forEachName(vars, function (name) {
          return p[name] = 1;
        });

        vars = p;
      }

      vars = _addAliasesToVars(parsedTargets, vars);
    }

    i = parsedTargets.length;

    while (i--) {
      if (~killingTargets.indexOf(parsedTargets[i])) {
        curLookup = propTweenLookup[i];

        if (vars === "all") {
          overwrittenProps[i] = vars;
          props = curLookup;
          curOverwriteProps = {};
        } else {
          curOverwriteProps = overwrittenProps[i] = overwrittenProps[i] || {};
          props = vars;
        }

        for (p in props) {
          pt = curLookup && curLookup[p];

          if (pt) {
            if (!("kill" in pt.d) || pt.d.kill(p) === true) {
              _removeLinkedListItem(this, pt, "_pt");
            }

            delete curLookup[p];
          }

          if (curOverwriteProps !== "all") {
            curOverwriteProps[p] = 1;
          }
        }
      }
    }

    this._initted && !this._pt && firstPT && _interrupt(this); //if all tweening properties are killed, kill the tween. Without this line, if there's a tween with multiple targets and then you killTweensOf() each target individually, the tween would technically still remain active and fire its onComplete even though there aren't any more properties tweening.

    return this;
  };

  Tween.to = function to(targets, vars) {
    return new Tween(targets, vars, arguments[2]);
  };

  Tween.from = function from(targets, vars) {
    return new Tween(targets, _parseVars(arguments, 1));
  };

  Tween.delayedCall = function delayedCall(delay, callback, params, scope) {
    return new Tween(callback, 0, {
      immediateRender: false,
      lazy: false,
      overwrite: false,
      delay: delay,
      onComplete: callback,
      onReverseComplete: callback,
      onCompleteParams: params,
      onReverseCompleteParams: params,
      callbackScope: scope
    });
  };

  Tween.fromTo = function fromTo(targets, fromVars, toVars) {
    return new Tween(targets, _parseVars(arguments, 2));
  };

  Tween.set = function set(targets, vars) {
    vars.duration = 0;
    vars.repeatDelay || (vars.repeat = 0);
    return new Tween(targets, vars);
  };

  Tween.killTweensOf = function killTweensOf(targets, props, onlyActive) {
    return _globalTimeline.killTweensOf(targets, props, onlyActive);
  };

  return Tween;
}(Animation);

_setDefaults(Tween.prototype, {
  _targets: [],
  _lazy: 0,
  _startAt: 0,
  _op: 0,
  _onInit: 0
}); //add the pertinent timeline methods to Tween instances so that users can chain conveniently and create a timeline automatically. (removed due to concerns that it'd ultimately add to more confusion especially for beginners)
// _forEachName("to,from,fromTo,set,call,add,addLabel,addPause", name => {
// 	Tween.prototype[name] = function() {
// 		let tl = new Timeline();
// 		return _addToTimeline(tl, this)[name].apply(tl, toArray(arguments));
// 	}
// });
//for backward compatibility. Leverage the timeline calls.


_forEachName("staggerTo,staggerFrom,staggerFromTo", function (name) {
  Tween[name] = function () {
    var tl = new Timeline(),
        params = _slice.call(arguments, 0);

    params.splice(name === "staggerFromTo" ? 5 : 4, 0, 0);
    return tl[name].apply(tl, params);
  };
});
/*
 * --------------------------------------------------------------------------------------
 * PROPTWEEN
 * --------------------------------------------------------------------------------------
 */


var _setterPlain = function _setterPlain(target, property, value) {
  return target[property] = value;
},
    _setterFunc = function _setterFunc(target, property, value) {
  return target[property](value);
},
    _setterFuncWithParam = function _setterFuncWithParam(target, property, value, data) {
  return target[property](data.fp, value);
},
    _setterAttribute = function _setterAttribute(target, property, value) {
  return target.setAttribute(property, value);
},
    _getSetter = function _getSetter(target, property) {
  return _isFunction(target[property]) ? _setterFunc : _isUndefined(target[property]) && target.setAttribute ? _setterAttribute : _setterPlain;
},
    _renderPlain = function _renderPlain(ratio, data) {
  return data.set(data.t, data.p, Math.round((data.s + data.c * ratio) * 10000) / 10000, data);
},
    _renderBoolean = function _renderBoolean(ratio, data) {
  return data.set(data.t, data.p, !!(data.s + data.c * ratio), data);
},
    _renderComplexString = function _renderComplexString(ratio, data) {
  var pt = data._pt,
      s = "";

  if (!ratio && data.b) {
    //b = beginning string
    s = data.b;
  } else if (ratio === 1 && data.e) {
    //e = ending string
    s = data.e;
  } else {
    while (pt) {
      s = pt.p + (pt.m ? pt.m(pt.s + pt.c * ratio) : Math.round((pt.s + pt.c * ratio) * 10000) / 10000) + s; //we use the "p" property for the text inbetween (like a suffix). And in the context of a complex string, the modifier (m) is typically just Math.round(), like for RGB colors.

      pt = pt._next;
    }

    s += data.c; //we use the "c" of the PropTween to store the final chunk of non-numeric text.
  }

  data.set(data.t, data.p, s, data);
},
    _renderPropTweens = function _renderPropTweens(ratio, data) {
  var pt = data._pt;

  while (pt) {
    pt.r(ratio, pt.d);
    pt = pt._next;
  }
},
    _addPluginModifier = function _addPluginModifier(modifier, tween, target, property) {
  var pt = this._pt,
      next;

  while (pt) {
    next = pt._next;
    pt.p === property && pt.modifier(modifier, tween, target);
    pt = next;
  }
},
    _killPropTweensOf = function _killPropTweensOf(property) {
  var pt = this._pt,
      hasNonDependentRemaining,
      next;

  while (pt) {
    next = pt._next;

    if (pt.p === property && !pt.op || pt.op === property) {
      _removeLinkedListItem(this, pt, "_pt");
    } else if (!pt.dep) {
      hasNonDependentRemaining = 1;
    }

    pt = next;
  }

  return !hasNonDependentRemaining;
},
    _setterWithModifier = function _setterWithModifier(target, property, value, data) {
  data.mSet(target, property, data.m.call(data.tween, value, data.mt), data);
},
    _sortPropTweensByPriority = function _sortPropTweensByPriority(parent) {
  var pt = parent._pt,
      next,
      pt2,
      first,
      last; //sorts the PropTween linked list in order of priority because some plugins need to do their work after ALL of the PropTweens were created (like RoundPropsPlugin and ModifiersPlugin)

  while (pt) {
    next = pt._next;
    pt2 = first;

    while (pt2 && pt2.pr > pt.pr) {
      pt2 = pt2._next;
    }

    if (pt._prev = pt2 ? pt2._prev : last) {
      pt._prev._next = pt;
    } else {
      first = pt;
    }

    if (pt._next = pt2) {
      pt2._prev = pt;
    } else {
      last = pt;
    }

    pt = next;
  }

  parent._pt = first;
}; //PropTween key: t = target, p = prop, r = renderer, d = data, s = start, c = change, op = overwriteProperty (ONLY populated when it's different than p), pr = priority, _next/_prev for the linked list siblings, set = setter, m = modifier, mSet = modifierSetter (the original setter, before a modifier was added)


var PropTween = /*#__PURE__*/function () {
  function PropTween(next, target, prop, start, change, renderer, data, setter, priority) {
    this.t = target;
    this.s = start;
    this.c = change;
    this.p = prop;
    this.r = renderer || _renderPlain;
    this.d = data || this;
    this.set = setter || _setterPlain;
    this.pr = priority || 0;
    this._next = next;

    if (next) {
      next._prev = this;
    }
  }

  var _proto4 = PropTween.prototype;

  _proto4.modifier = function modifier(func, tween, target) {
    this.mSet = this.mSet || this.set; //in case it was already set (a PropTween can only have one modifier)

    this.set = _setterWithModifier;
    this.m = func;
    this.mt = target; //modifier target

    this.tween = tween;
  };

  return PropTween;
}(); //Initialization tasks

_forEachName(_callbackNames + "parent,duration,ease,delay,overwrite,runBackwards,startAt,yoyo,immediateRender,repeat,repeatDelay,data,paused,reversed,lazy,callbackScope,stringFilter,id,yoyoEase,stagger,inherit,repeatRefresh,keyframes,autoRevert,scrollTrigger", function (name) {
  return _reservedProps[name] = 1;
});

_globals.TweenMax = _globals.TweenLite = Tween;
_globals.TimelineLite = _globals.TimelineMax = Timeline;
_globalTimeline = new Timeline({
  sortChildren: false,
  defaults: _defaults,
  autoRemoveChildren: true,
  id: "root",
  smoothChildTiming: true
});
_config.stringFilter = _colorStringFilter;
/*
 * --------------------------------------------------------------------------------------
 * GSAP
 * --------------------------------------------------------------------------------------
 */

var _gsap = {
  registerPlugin: function registerPlugin() {
    for (var _len2 = arguments.length, args = new Array(_len2), _key2 = 0; _key2 < _len2; _key2++) {
      args[_key2] = arguments[_key2];
    }

    args.forEach(function (config) {
      return _createPlugin(config);
    });
  },
  timeline: function timeline(vars) {
    return new Timeline(vars);
  },
  getTweensOf: function getTweensOf(targets, onlyActive) {
    return _globalTimeline.getTweensOf(targets, onlyActive);
  },
  getProperty: function getProperty(target, property, unit, uncache) {
    _isString(target) && (target = toArray(target)[0]); //in case selector text or an array is passed in

    var getter = _getCache(target || {}).get,
        format = unit ? _passThrough : _numericIfPossible;

    unit === "native" && (unit = "");
    return !target ? target : !property ? function (property, unit, uncache) {
      return format((_plugins[property] && _plugins[property].get || getter)(target, property, unit, uncache));
    } : format((_plugins[property] && _plugins[property].get || getter)(target, property, unit, uncache));
  },
  quickSetter: function quickSetter(target, property, unit) {
    target = toArray(target);

    if (target.length > 1) {
      var setters = target.map(function (t) {
        return gsap.quickSetter(t, property, unit);
      }),
          l = setters.length;
      return function (value) {
        var i = l;

        while (i--) {
          setters[i](value);
        }
      };
    }

    target = target[0] || {};

    var Plugin = _plugins[property],
        cache = _getCache(target),
        p = cache.harness && (cache.harness.aliases || {})[property] || property,
        // in case it's an alias, like "rotate" for "rotation".
    setter = Plugin ? function (value) {
      var p = new Plugin();
      _quickTween._pt = 0;
      p.init(target, unit ? value + unit : value, _quickTween, 0, [target]);
      p.render(1, p);
      _quickTween._pt && _renderPropTweens(1, _quickTween);
    } : cache.set(target, p);

    return Plugin ? setter : function (value) {
      return setter(target, p, unit ? value + unit : value, cache, 1);
    };
  },
  isTweening: function isTweening(targets) {
    return _globalTimeline.getTweensOf(targets, true).length > 0;
  },
  defaults: function defaults(value) {
    value && value.ease && (value.ease = _parseEase(value.ease, _defaults.ease));
    return _mergeDeep(_defaults, value || {});
  },
  config: function config(value) {
    return _mergeDeep(_config, value || {});
  },
  registerEffect: function registerEffect(_ref) {
    var name = _ref.name,
        effect = _ref.effect,
        plugins = _ref.plugins,
        defaults = _ref.defaults,
        extendTimeline = _ref.extendTimeline;
    (plugins || "").split(",").forEach(function (pluginName) {
      return pluginName && !_plugins[pluginName] && !_globals[pluginName] && _warn(name + " effect requires " + pluginName + " plugin.");
    });

    _effects[name] = function (targets, vars, tl) {
      return effect(toArray(targets), _setDefaults(vars || {}, defaults), tl);
    };

    if (extendTimeline) {
      Timeline.prototype[name] = function (targets, vars, position) {
        return this.add(_effects[name](targets, _isObject(vars) ? vars : (position = vars) && {}, this), position);
      };
    }
  },
  registerEase: function registerEase(name, ease) {
    _easeMap[name] = _parseEase(ease);
  },
  parseEase: function parseEase(ease, defaultEase) {
    return arguments.length ? _parseEase(ease, defaultEase) : _easeMap;
  },
  getById: function getById(id) {
    return _globalTimeline.getById(id);
  },
  exportRoot: function exportRoot(vars, includeDelayedCalls) {
    if (vars === void 0) {
      vars = {};
    }

    var tl = new Timeline(vars),
        child,
        next;
    tl.smoothChildTiming = _isNotFalse(vars.smoothChildTiming);

    _globalTimeline.remove(tl);

    tl._dp = 0; //otherwise it'll get re-activated when adding children and be re-introduced into _globalTimeline's linked list (then added to itself).

    tl._time = tl._tTime = _globalTimeline._time;
    child = _globalTimeline._first;

    while (child) {
      next = child._next;

      if (includeDelayedCalls || !(!child._dur && child instanceof Tween && child.vars.onComplete === child._targets[0])) {
        _addToTimeline(tl, child, child._start - child._delay);
      }

      child = next;
    }

    _addToTimeline(_globalTimeline, tl, 0);

    return tl;
  },
  utils: {
    wrap: wrap,
    wrapYoyo: wrapYoyo,
    distribute: distribute,
    random: random,
    snap: snap,
    normalize: normalize,
    getUnit: getUnit,
    clamp: clamp,
    splitColor: splitColor,
    toArray: toArray,
    mapRange: mapRange,
    pipe: pipe,
    unitize: unitize,
    interpolate: interpolate,
    shuffle: shuffle
  },
  install: _install,
  effects: _effects,
  ticker: _ticker,
  updateRoot: Timeline.updateRoot,
  plugins: _plugins,
  globalTimeline: _globalTimeline,
  core: {
    PropTween: PropTween,
    globals: _addGlobal,
    Tween: Tween,
    Timeline: Timeline,
    Animation: Animation,
    getCache: _getCache,
    _removeLinkedListItem: _removeLinkedListItem
  }
};

_forEachName("to,from,fromTo,delayedCall,set,killTweensOf", function (name) {
  return _gsap[name] = Tween[name];
});

_ticker.add(Timeline.updateRoot);

_quickTween = _gsap.to({}, {
  duration: 0
}); // ---- EXTRA PLUGINS --------------------------------------------------------

var _getPluginPropTween = function _getPluginPropTween(plugin, prop) {
  var pt = plugin._pt;

  while (pt && pt.p !== prop && pt.op !== prop && pt.fp !== prop) {
    pt = pt._next;
  }

  return pt;
},
    _addModifiers = function _addModifiers(tween, modifiers) {
  var targets = tween._targets,
      p,
      i,
      pt;

  for (p in modifiers) {
    i = targets.length;

    while (i--) {
      pt = tween._ptLookup[i][p];

      if (pt && (pt = pt.d)) {
        if (pt._pt) {
          // is a plugin
          pt = _getPluginPropTween(pt, p);
        }

        pt && pt.modifier && pt.modifier(modifiers[p], tween, targets[i], p);
      }
    }
  }
},
    _buildModifierPlugin = function _buildModifierPlugin(name, modifier) {
  return {
    name: name,
    rawVars: 1,
    //don't pre-process function-based values or "random()" strings.
    init: function init(target, vars, tween) {
      tween._onInit = function (tween) {
        var temp, p;

        if (_isString(vars)) {
          temp = {};

          _forEachName(vars, function (name) {
            return temp[name] = 1;
          }); //if the user passes in a comma-delimited list of property names to roundProps, like "x,y", we round to whole numbers.


          vars = temp;
        }

        if (modifier) {
          temp = {};

          for (p in vars) {
            temp[p] = modifier(vars[p]);
          }

          vars = temp;
        }

        _addModifiers(tween, vars);
      };
    }
  };
}; //register core plugins


var gsap = _gsap.registerPlugin({
  name: "attr",
  init: function init(target, vars, tween, index, targets) {
    var p, pt;

    for (p in vars) {
      pt = this.add(target, "setAttribute", (target.getAttribute(p) || 0) + "", vars[p], index, targets, 0, 0, p);
      pt && (pt.op = p);

      this._props.push(p);
    }
  }
}, {
  name: "endArray",
  init: function init(target, value) {
    var i = value.length;

    while (i--) {
      this.add(target, i, target[i] || 0, value[i]);
    }
  }
}, _buildModifierPlugin("roundProps", _roundModifier), _buildModifierPlugin("modifiers"), _buildModifierPlugin("snap", snap)) || _gsap; //to prevent the core plugins from being dropped via aggressive tree shaking, we must include them in the variable declaration in this way.

Tween.version = Timeline.version = gsap.version = "3.5.1";
_coreReady = 1;

if (_windowExists()) {
  _wake();
}

var Power0 = _easeMap.Power0,
    Power1 = _easeMap.Power1,
    Power2 = _easeMap.Power2,
    Power3 = _easeMap.Power3,
    Power4 = _easeMap.Power4,
    Linear = _easeMap.Linear,
    Quad = _easeMap.Quad,
    Cubic = _easeMap.Cubic,
    Quart = _easeMap.Quart,
    Quint = _easeMap.Quint,
    Strong = _easeMap.Strong,
    Elastic = _easeMap.Elastic,
    Back = _easeMap.Back,
    SteppedEase = _easeMap.SteppedEase,
    Bounce = _easeMap.Bounce,
    Sine = _easeMap.Sine,
    Expo = _easeMap.Expo,
    Circ = _easeMap.Circ;

 //export some internal methods/orojects for use in CSSPlugin so that we can externalize that file and allow custom builds that exclude it.


// CONCATENATED MODULE: ./node_modules/gsap/CSSPlugin.js
/*!
 * CSSPlugin 3.5.1
 * https://greensock.com
 *
 * Copyright 2008-2020, GreenSock. All rights reserved.
 * Subject to the terms at https://greensock.com/standard-license or for
 * Club GreenSock members, the agreement issued with that membership.
 * @author: Jack Doyle, jack@greensock.com
*/

/* eslint-disable */


var CSSPlugin_win,
    CSSPlugin_doc,
    _docElement,
    _pluginInitted,
    _tempDiv,
    _tempDivStyler,
    _recentSetterPlugin,
    CSSPlugin_windowExists = function _windowExists() {
  return typeof window !== "undefined";
},
    _transformProps = {},
    _RAD2DEG = 180 / Math.PI,
    _DEG2RAD = Math.PI / 180,
    _atan2 = Math.atan2,
    CSSPlugin_bigNum = 1e8,
    _capsExp = /([A-Z])/g,
    _horizontalExp = /(?:left|right|width|margin|padding|x)/i,
    _complexExp = /[\s,\(]\S/,
    _propertyAliases = {
  autoAlpha: "opacity,visibility",
  scale: "scaleX,scaleY",
  alpha: "opacity"
},
    _renderCSSProp = function _renderCSSProp(ratio, data) {
  return data.set(data.t, data.p, Math.round((data.s + data.c * ratio) * 10000) / 10000 + data.u, data);
},
    _renderPropWithEnd = function _renderPropWithEnd(ratio, data) {
  return data.set(data.t, data.p, ratio === 1 ? data.e : Math.round((data.s + data.c * ratio) * 10000) / 10000 + data.u, data);
},
    _renderCSSPropWithBeginning = function _renderCSSPropWithBeginning(ratio, data) {
  return data.set(data.t, data.p, ratio ? Math.round((data.s + data.c * ratio) * 10000) / 10000 + data.u : data.b, data);
},
    //if units change, we need a way to render the original unit/value when the tween goes all the way back to the beginning (ratio:0)
_renderRoundedCSSProp = function _renderRoundedCSSProp(ratio, data) {
  var value = data.s + data.c * ratio;
  data.set(data.t, data.p, ~~(value + (value < 0 ? -.5 : .5)) + data.u, data);
},
    _renderNonTweeningValue = function _renderNonTweeningValue(ratio, data) {
  return data.set(data.t, data.p, ratio ? data.e : data.b, data);
},
    _renderNonTweeningValueOnlyAtEnd = function _renderNonTweeningValueOnlyAtEnd(ratio, data) {
  return data.set(data.t, data.p, ratio !== 1 ? data.b : data.e, data);
},
    _setterCSSStyle = function _setterCSSStyle(target, property, value) {
  return target.style[property] = value;
},
    _setterCSSProp = function _setterCSSProp(target, property, value) {
  return target.style.setProperty(property, value);
},
    _setterTransform = function _setterTransform(target, property, value) {
  return target._gsap[property] = value;
},
    _setterScale = function _setterScale(target, property, value) {
  return target._gsap.scaleX = target._gsap.scaleY = value;
},
    _setterScaleWithRender = function _setterScaleWithRender(target, property, value, data, ratio) {
  var cache = target._gsap;
  cache.scaleX = cache.scaleY = value;
  cache.renderTransform(ratio, cache);
},
    _setterTransformWithRender = function _setterTransformWithRender(target, property, value, data, ratio) {
  var cache = target._gsap;
  cache[property] = value;
  cache.renderTransform(ratio, cache);
},
    _transformProp = "transform",
    _transformOriginProp = _transformProp + "Origin",
    _supports3D,
    _createElement = function _createElement(type, ns) {
  var e = CSSPlugin_doc.createElementNS ? CSSPlugin_doc.createElementNS((ns || "http://www.w3.org/1999/xhtml").replace(/^https/, "http"), type) : CSSPlugin_doc.createElement(type); //some servers swap in https for http in the namespace which can break things, making "style" inaccessible.

  return e.style ? e : CSSPlugin_doc.createElement(type); //some environments won't allow access to the element's style when created with a namespace in which case we default to the standard createElement() to work around the issue. Also note that when GSAP is embedded directly inside an SVG file, createElement() won't allow access to the style object in Firefox (see https://greensock.com/forums/topic/20215-problem-using-tweenmax-in-standalone-self-containing-svg-file-err-cannot-set-property-csstext-of-undefined/).
},
    _getComputedProperty = function _getComputedProperty(target, property, skipPrefixFallback) {
  var cs = getComputedStyle(target);
  return cs[property] || cs.getPropertyValue(property.replace(_capsExp, "-$1").toLowerCase()) || cs.getPropertyValue(property) || !skipPrefixFallback && _getComputedProperty(target, _checkPropPrefix(property) || property, 1) || ""; //css variables may not need caps swapped out for dashes and lowercase.
},
    _prefixes = "O,Moz,ms,Ms,Webkit".split(","),
    _checkPropPrefix = function _checkPropPrefix(property, element, preferPrefix) {
  var e = element || _tempDiv,
      s = e.style,
      i = 5;

  if (property in s && !preferPrefix) {
    return property;
  }

  property = property.charAt(0).toUpperCase() + property.substr(1);

  while (i-- && !(_prefixes[i] + property in s)) {}

  return i < 0 ? null : (i === 3 ? "ms" : i >= 0 ? _prefixes[i] : "") + property;
},
    _initCore = function _initCore() {
  if (CSSPlugin_windowExists() && window.document) {
    CSSPlugin_win = window;
    CSSPlugin_doc = CSSPlugin_win.document;
    _docElement = CSSPlugin_doc.documentElement;
    _tempDiv = _createElement("div") || {
      style: {}
    };
    _tempDivStyler = _createElement("div");
    _transformProp = _checkPropPrefix(_transformProp);
    _transformOriginProp = _transformProp + "Origin";
    _tempDiv.style.cssText = "border-width:0;line-height:0;position:absolute;padding:0"; //make sure to override certain properties that may contaminate measurements, in case the user has overreaching style sheets.

    _supports3D = !!_checkPropPrefix("perspective");
    _pluginInitted = 1;
  }
},
    _getBBoxHack = function _getBBoxHack(swapIfPossible) {
  //works around issues in some browsers (like Firefox) that don't correctly report getBBox() on SVG elements inside a <defs> element and/or <mask>. We try creating an SVG, adding it to the documentElement and toss the element in there so that it's definitely part of the rendering tree, then grab the bbox and if it works, we actually swap out the original getBBox() method for our own that does these extra steps whenever getBBox is needed. This helps ensure that performance is optimal (only do all these extra steps when absolutely necessary...most elements don't need it).
  var svg = _createElement("svg", this.ownerSVGElement && this.ownerSVGElement.getAttribute("xmlns") || "http://www.w3.org/2000/svg"),
      oldParent = this.parentNode,
      oldSibling = this.nextSibling,
      oldCSS = this.style.cssText,
      bbox;

  _docElement.appendChild(svg);

  svg.appendChild(this);
  this.style.display = "block";

  if (swapIfPossible) {
    try {
      bbox = this.getBBox();
      this._gsapBBox = this.getBBox; //store the original

      this.getBBox = _getBBoxHack;
    } catch (e) {}
  } else if (this._gsapBBox) {
    bbox = this._gsapBBox();
  }

  if (oldParent) {
    if (oldSibling) {
      oldParent.insertBefore(this, oldSibling);
    } else {
      oldParent.appendChild(this);
    }
  }

  _docElement.removeChild(svg);

  this.style.cssText = oldCSS;
  return bbox;
},
    _getAttributeFallbacks = function _getAttributeFallbacks(target, attributesArray) {
  var i = attributesArray.length;

  while (i--) {
    if (target.hasAttribute(attributesArray[i])) {
      return target.getAttribute(attributesArray[i]);
    }
  }
},
    _getBBox = function _getBBox(target) {
  var bounds;

  try {
    bounds = target.getBBox(); //Firefox throws errors if you try calling getBBox() on an SVG element that's not rendered (like in a <symbol> or <defs>). https://bugzilla.mozilla.org/show_bug.cgi?id=612118
  } catch (error) {
    bounds = _getBBoxHack.call(target, true);
  }

  bounds && (bounds.width || bounds.height) || target.getBBox === _getBBoxHack || (bounds = _getBBoxHack.call(target, true)); //some browsers (like Firefox) misreport the bounds if the element has zero width and height (it just assumes it's at x:0, y:0), thus we need to manually grab the position in that case.

  return bounds && !bounds.width && !bounds.x && !bounds.y ? {
    x: +_getAttributeFallbacks(target, ["x", "cx", "x1"]) || 0,
    y: +_getAttributeFallbacks(target, ["y", "cy", "y1"]) || 0,
    width: 0,
    height: 0
  } : bounds;
},
    _isSVG = function _isSVG(e) {
  return !!(e.getCTM && (!e.parentNode || e.ownerSVGElement) && _getBBox(e));
},
    //reports if the element is an SVG on which getBBox() actually works
_removeProperty = function _removeProperty(target, property) {
  if (property) {
    var style = target.style;

    if (property in _transformProps && property !== _transformOriginProp) {
      property = _transformProp;
    }

    if (style.removeProperty) {
      if (property.substr(0, 2) === "ms" || property.substr(0, 6) === "webkit") {
        //Microsoft and some Webkit browsers don't conform to the standard of capitalizing the first prefix character, so we adjust so that when we prefix the caps with a dash, it's correct (otherwise it'd be "ms-transform" instead of "-ms-transform" for IE9, for example)
        property = "-" + property;
      }

      style.removeProperty(property.replace(_capsExp, "-$1").toLowerCase());
    } else {
      //note: old versions of IE use "removeAttribute()" instead of "removeProperty()"
      style.removeAttribute(property);
    }
  }
},
    CSSPlugin_addNonTweeningPT = function _addNonTweeningPT(plugin, target, property, beginning, end, onlySetAtEnd) {
  var pt = new PropTween(plugin._pt, target, property, 0, 1, onlySetAtEnd ? _renderNonTweeningValueOnlyAtEnd : _renderNonTweeningValue);
  plugin._pt = pt;
  pt.b = beginning;
  pt.e = end;

  plugin._props.push(property);

  return pt;
},
    _nonConvertibleUnits = {
  deg: 1,
  rad: 1,
  turn: 1
},
    //takes a single value like 20px and converts it to the unit specified, like "%", returning only the numeric amount.
CSSPlugin_convertToUnit = function _convertToUnit(target, property, value, unit) {
  var curValue = parseFloat(value) || 0,
      curUnit = (value + "").trim().substr((curValue + "").length) || "px",
      // some browsers leave extra whitespace at the beginning of CSS variables, hence the need to trim()
  style = _tempDiv.style,
      horizontal = _horizontalExp.test(property),
      isRootSVG = target.tagName.toLowerCase() === "svg",
      measureProperty = (isRootSVG ? "client" : "offset") + (horizontal ? "Width" : "Height"),
      amount = 100,
      toPixels = unit === "px",
      toPercent = unit === "%",
      px,
      parent,
      cache,
      isSVG;

  if (unit === curUnit || !curValue || _nonConvertibleUnits[unit] || _nonConvertibleUnits[curUnit]) {
    return curValue;
  }

  curUnit !== "px" && !toPixels && (curValue = _convertToUnit(target, property, value, "px"));
  isSVG = target.getCTM && _isSVG(target);

  if (toPercent && (_transformProps[property] || ~property.indexOf("adius"))) {
    //transforms and borderRadius are relative to the size of the element itself!
    return _round(curValue / (isSVG ? target.getBBox()[horizontal ? "width" : "height"] : target[measureProperty]) * amount);
  }

  style[horizontal ? "width" : "height"] = amount + (toPixels ? curUnit : unit);
  parent = ~property.indexOf("adius") || unit === "em" && target.appendChild && !isRootSVG ? target : target.parentNode;

  if (isSVG) {
    parent = (target.ownerSVGElement || {}).parentNode;
  }

  if (!parent || parent === CSSPlugin_doc || !parent.appendChild) {
    parent = CSSPlugin_doc.body;
  }

  cache = parent._gsap;

  if (cache && toPercent && cache.width && horizontal && cache.time === _ticker.time) {
    return _round(curValue / cache.width * amount);
  } else {
    (toPercent || curUnit === "%") && (style.position = _getComputedProperty(target, "position"));
    parent === target && (style.position = "static"); // like for borderRadius, if it's a % we must have it relative to the target itself but that may not have position: relative or position: absolute in which case it'd go up the chain until it finds its offsetParent (bad). position: static protects against that.

    parent.appendChild(_tempDiv);
    px = _tempDiv[measureProperty];
    parent.removeChild(_tempDiv);
    style.position = "absolute";

    if (horizontal && toPercent) {
      cache = _getCache(parent);
      cache.time = _ticker.time;
      cache.width = parent[measureProperty];
    }
  }

  return _round(toPixels ? px * curValue / amount : px && curValue ? amount / px * curValue : 0);
},
    CSSPlugin_get = function _get(target, property, unit, uncache) {
  var value;
  _pluginInitted || _initCore();

  if (property in _propertyAliases && property !== "transform") {
    property = _propertyAliases[property];

    if (~property.indexOf(",")) {
      property = property.split(",")[0];
    }
  }

  if (_transformProps[property] && property !== "transform") {
    value = CSSPlugin_parseTransform(target, uncache);
    value = property !== "transformOrigin" ? value[property] : _firstTwoOnly(_getComputedProperty(target, _transformOriginProp)) + " " + value.zOrigin + "px";
  } else {
    value = target.style[property];

    if (!value || value === "auto" || uncache || ~(value + "").indexOf("calc(")) {
      value = _specialProps[property] && _specialProps[property](target, property, unit) || _getComputedProperty(target, property) || _getProperty(target, property) || (property === "opacity" ? 1 : 0); // note: some browsers, like Firefox, don't report borderRadius correctly! Instead, it only reports every corner like  borderTopLeftRadius
    }
  }

  return unit && !~(value + "").indexOf(" ") ? CSSPlugin_convertToUnit(target, property, value, unit) + unit : value;
},
    CSSPlugin_tweenComplexCSSString = function _tweenComplexCSSString(target, prop, start, end) {
  //note: we call _tweenComplexCSSString.call(pluginInstance...) to ensure that it's scoped properly. We may call it from within a plugin too, thus "this" would refer to the plugin.
  if (!start || start === "none") {
    // some browsers like Safari actually PREFER the prefixed property and mis-report the unprefixed value like clipPath (BUG). In other words, even though clipPath exists in the style ("clipPath" in target.style) and it's set in the CSS properly (along with -webkit-clip-path), Safari reports clipPath as "none" whereas WebkitClipPath reports accurately like "ellipse(100% 0% at 50% 0%)", so in this case we must SWITCH to using the prefixed property instead. See https://greensock.com/forums/topic/18310-clippath-doesnt-work-on-ios/
    var p = _checkPropPrefix(prop, target, 1),
        s = p && _getComputedProperty(target, p, 1);

    if (s && s !== start) {
      prop = p;
      start = s;
    } else if (prop === "borderColor") {
      start = _getComputedProperty(target, "borderTopColor"); // Firefox bug: always reports "borderColor" as "", so we must fall back to borderTopColor. See https://greensock.com/forums/topic/24583-how-to-return-colors-that-i-had-after-reverse/
    }
  }

  var pt = new PropTween(this._pt, target.style, prop, 0, 1, _renderComplexString),
      index = 0,
      matchIndex = 0,
      a,
      result,
      startValues,
      startNum,
      color,
      startValue,
      endValue,
      endNum,
      chunk,
      endUnit,
      startUnit,
      relative,
      endValues;
  pt.b = start;
  pt.e = end;
  start += ""; //ensure values are strings

  end += "";

  if (end === "auto") {
    target.style[prop] = end;
    end = _getComputedProperty(target, prop) || end;
    target.style[prop] = start;
  }

  a = [start, end];

  _colorStringFilter(a); //pass an array with the starting and ending values and let the filter do whatever it needs to the values. If colors are found, it returns true and then we must match where the color shows up order-wise because for things like boxShadow, sometimes the browser provides the computed values with the color FIRST, but the user provides it with the color LAST, so flip them if necessary. Same for drop-shadow().


  start = a[0];
  end = a[1];
  startValues = start.match(_numWithUnitExp) || [];
  endValues = end.match(_numWithUnitExp) || [];

  if (endValues.length) {
    while (result = _numWithUnitExp.exec(end)) {
      endValue = result[0];
      chunk = end.substring(index, result.index);

      if (color) {
        color = (color + 1) % 5;
      } else if (chunk.substr(-5) === "rgba(" || chunk.substr(-5) === "hsla(") {
        color = 1;
      }

      if (endValue !== (startValue = startValues[matchIndex++] || "")) {
        startNum = parseFloat(startValue) || 0;
        startUnit = startValue.substr((startNum + "").length);
        relative = endValue.charAt(1) === "=" ? +(endValue.charAt(0) + "1") : 0;

        if (relative) {
          endValue = endValue.substr(2);
        }

        endNum = parseFloat(endValue);
        endUnit = endValue.substr((endNum + "").length);
        index = _numWithUnitExp.lastIndex - endUnit.length;

        if (!endUnit) {
          //if something like "perspective:300" is passed in and we must add a unit to the end
          endUnit = endUnit || _config.units[prop] || startUnit;

          if (index === end.length) {
            end += endUnit;
            pt.e += endUnit;
          }
        }

        if (startUnit !== endUnit) {
          startNum = CSSPlugin_convertToUnit(target, prop, startValue, endUnit) || 0;
        } //these nested PropTweens are handled in a special way - we'll never actually call a render or setter method on them. We'll just loop through them in the parent complex string PropTween's render method.


        pt._pt = {
          _next: pt._pt,
          p: chunk || matchIndex === 1 ? chunk : ",",
          //note: SVG spec allows omission of comma/space when a negative sign is wedged between two numbers, like 2.5-5.3 instead of 2.5,-5.3 but when tweening, the negative value may switch to positive, so we insert the comma just in case.
          s: startNum,
          c: relative ? relative * endNum : endNum - startNum,
          m: color && color < 4 ? Math.round : 0
        };
      }
    }

    pt.c = index < end.length ? end.substring(index, end.length) : ""; //we use the "c" of the PropTween to store the final part of the string (after the last number)
  } else {
    pt.r = prop === "display" && end === "none" ? _renderNonTweeningValueOnlyAtEnd : _renderNonTweeningValue;
  }

  if (_relExp.test(end)) {
    pt.e = 0; //if the end string contains relative values or dynamic random(...) values, delete the end it so that on the final render we don't actually set it to the string with += or -= characters (forces it to use the calculated value).
  }

  this._pt = pt; //start the linked list with this new PropTween. Remember, we call _tweenComplexCSSString.call(pluginInstance...) to ensure that it's scoped properly. We may call it from within another plugin too, thus "this" would refer to the plugin.

  return pt;
},
    _keywordToPercent = {
  top: "0%",
  bottom: "100%",
  left: "0%",
  right: "100%",
  center: "50%"
},
    _convertKeywordsToPercentages = function _convertKeywordsToPercentages(value) {
  var split = value.split(" "),
      x = split[0],
      y = split[1] || "50%";

  if (x === "top" || x === "bottom" || y === "left" || y === "right") {
    //the user provided them in the wrong order, so flip them
    value = x;
    x = y;
    y = value;
  }

  split[0] = _keywordToPercent[x] || x;
  split[1] = _keywordToPercent[y] || y;
  return split.join(" ");
},
    _renderClearProps = function _renderClearProps(ratio, data) {
  if (data.tween && data.tween._time === data.tween._dur) {
    var target = data.t,
        style = target.style,
        props = data.u,
        cache = target._gsap,
        prop,
        clearTransforms,
        i;

    if (props === "all" || props === true) {
      style.cssText = "";
      clearTransforms = 1;
    } else {
      props = props.split(",");
      i = props.length;

      while (--i > -1) {
        prop = props[i];

        if (_transformProps[prop]) {
          clearTransforms = 1;
          prop = prop === "transformOrigin" ? _transformOriginProp : _transformProp;
        }

        _removeProperty(target, prop);
      }
    }

    if (clearTransforms) {
      _removeProperty(target, _transformProp);

      if (cache) {
        cache.svg && target.removeAttribute("transform");

        CSSPlugin_parseTransform(target, 1); // force all the cached values back to "normal"/identity, otherwise if there's another tween that's already set to render transforms on this element, it could display the wrong values.


        cache.uncache = 1;
      }
    }
  }
},
    // note: specialProps should return 1 if (and only if) they have a non-zero priority. It indicates we need to sort the linked list.
_specialProps = {
  clearProps: function clearProps(plugin, target, property, endValue, tween) {
    if (tween.data !== "isFromStart") {
      var pt = plugin._pt = new PropTween(plugin._pt, target, property, 0, 0, _renderClearProps);
      pt.u = endValue;
      pt.pr = -10;
      pt.tween = tween;

      plugin._props.push(property);

      return 1;
    }
  }
  /* className feature (about 0.4kb gzipped).
  , className(plugin, target, property, endValue, tween) {
  	let _renderClassName = (ratio, data) => {
  			data.css.render(ratio, data.css);
  			if (!ratio || ratio === 1) {
  				let inline = data.rmv,
  					target = data.t,
  					p;
  				target.setAttribute("class", ratio ? data.e : data.b);
  				for (p in inline) {
  					_removeProperty(target, p);
  				}
  			}
  		},
  		_getAllStyles = (target) => {
  			let styles = {},
  				computed = getComputedStyle(target),
  				p;
  			for (p in computed) {
  				if (isNaN(p) && p !== "cssText" && p !== "length") {
  					styles[p] = computed[p];
  				}
  			}
  			_setDefaults(styles, _parseTransform(target, 1));
  			return styles;
  		},
  		startClassList = target.getAttribute("class"),
  		style = target.style,
  		cssText = style.cssText,
  		cache = target._gsap,
  		classPT = cache.classPT,
  		inlineToRemoveAtEnd = {},
  		data = {t:target, plugin:plugin, rmv:inlineToRemoveAtEnd, b:startClassList, e:(endValue.charAt(1) !== "=") ? endValue : startClassList.replace(new RegExp("(?:\\s|^)" + endValue.substr(2) + "(?![\\w-])"), "") + ((endValue.charAt(0) === "+") ? " " + endValue.substr(2) : "")},
  		changingVars = {},
  		startVars = _getAllStyles(target),
  		transformRelated = /(transform|perspective)/i,
  		endVars, p;
  	if (classPT) {
  		classPT.r(1, classPT.d);
  		_removeLinkedListItem(classPT.d.plugin, classPT, "_pt");
  	}
  	target.setAttribute("class", data.e);
  	endVars = _getAllStyles(target, true);
  	target.setAttribute("class", startClassList);
  	for (p in endVars) {
  		if (endVars[p] !== startVars[p] && !transformRelated.test(p)) {
  			changingVars[p] = endVars[p];
  			if (!style[p] && style[p] !== "0") {
  				inlineToRemoveAtEnd[p] = 1;
  			}
  		}
  	}
  	cache.classPT = plugin._pt = new PropTween(plugin._pt, target, "className", 0, 0, _renderClassName, data, 0, -11);
  	if (style.cssText !== cssText) { //only apply if things change. Otherwise, in cases like a background-image that's pulled dynamically, it could cause a refresh. See https://greensock.com/forums/topic/20368-possible-gsap-bug-switching-classnames-in-chrome/.
  		style.cssText = cssText; //we recorded cssText before we swapped classes and ran _getAllStyles() because in cases when a className tween is overwritten, we remove all the related tweening properties from that class change (otherwise class-specific stuff can't override properties we've directly set on the target's style object due to specificity).
  	}
  	_parseTransform(target, true); //to clear the caching of transforms
  	data.css = new gsap.plugins.css();
  	data.css.init(target, changingVars, tween);
  	plugin._props.push(...data.css._props);
  	return 1;
  }
  */

},

/*
 * --------------------------------------------------------------------------------------
 * TRANSFORMS
 * --------------------------------------------------------------------------------------
 */
_identity2DMatrix = [1, 0, 0, 1, 0, 0],
    _rotationalProperties = {},
    _isNullTransform = function _isNullTransform(value) {
  return value === "matrix(1, 0, 0, 1, 0, 0)" || value === "none" || !value;
},
    CSSPlugin_getComputedTransformMatrixAsArray = function _getComputedTransformMatrixAsArray(target) {
  var matrixString = _getComputedProperty(target, _transformProp);

  return _isNullTransform(matrixString) ? _identity2DMatrix : matrixString.substr(7).match(_numExp).map(_round);
},
    CSSPlugin_getMatrix = function _getMatrix(target, force2D) {
  var cache = target._gsap || _getCache(target),
      style = target.style,
      matrix = CSSPlugin_getComputedTransformMatrixAsArray(target),
      parent,
      nextSibling,
      temp,
      addedToDOM;

  if (cache.svg && target.getAttribute("transform")) {
    temp = target.transform.baseVal.consolidate().matrix; //ensures that even complex values like "translate(50,60) rotate(135,0,0)" are parsed because it mashes it into a matrix.

    matrix = [temp.a, temp.b, temp.c, temp.d, temp.e, temp.f];
    return matrix.join(",") === "1,0,0,1,0,0" ? _identity2DMatrix : matrix;
  } else if (matrix === _identity2DMatrix && !target.offsetParent && target !== _docElement && !cache.svg) {
    //note: if offsetParent is null, that means the element isn't in the normal document flow, like if it has display:none or one of its ancestors has display:none). Firefox returns null for getComputedStyle() if the element is in an iframe that has display:none. https://bugzilla.mozilla.org/show_bug.cgi?id=548397
    //browsers don't report transforms accurately unless the element is in the DOM and has a display value that's not "none". Firefox and Microsoft browsers have a partial bug where they'll report transforms even if display:none BUT not any percentage-based values like translate(-50%, 8px) will be reported as if it's translate(0, 8px).
    temp = style.display;
    style.display = "block";
    parent = target.parentNode;

    if (!parent || !target.offsetParent) {
      // note: in 3.3.0 we switched target.offsetParent to _doc.body.contains(target) to avoid [sometimes unnecessary] MutationObserver calls but that wasn't adequate because there are edge cases where nested position: fixed elements need to get reparented to accurately sense transforms. See https://github.com/greensock/GSAP/issues/388 and https://github.com/greensock/GSAP/issues/375
      addedToDOM = 1; //flag

      nextSibling = target.nextSibling;

      _docElement.appendChild(target); //we must add it to the DOM in order to get values properly

    }

    matrix = CSSPlugin_getComputedTransformMatrixAsArray(target);
    temp ? style.display = temp : _removeProperty(target, "display");

    if (addedToDOM) {
      nextSibling ? parent.insertBefore(target, nextSibling) : parent ? parent.appendChild(target) : _docElement.removeChild(target);
    }
  }

  return force2D && matrix.length > 6 ? [matrix[0], matrix[1], matrix[4], matrix[5], matrix[12], matrix[13]] : matrix;
},
    _applySVGOrigin = function _applySVGOrigin(target, origin, originIsAbsolute, smooth, matrixArray, pluginToAddPropTweensTo) {
  var cache = target._gsap,
      matrix = matrixArray || CSSPlugin_getMatrix(target, true),
      xOriginOld = cache.xOrigin || 0,
      yOriginOld = cache.yOrigin || 0,
      xOffsetOld = cache.xOffset || 0,
      yOffsetOld = cache.yOffset || 0,
      a = matrix[0],
      b = matrix[1],
      c = matrix[2],
      d = matrix[3],
      tx = matrix[4],
      ty = matrix[5],
      originSplit = origin.split(" "),
      xOrigin = parseFloat(originSplit[0]) || 0,
      yOrigin = parseFloat(originSplit[1]) || 0,
      bounds,
      determinant,
      x,
      y;

  if (!originIsAbsolute) {
    bounds = _getBBox(target);
    xOrigin = bounds.x + (~originSplit[0].indexOf("%") ? xOrigin / 100 * bounds.width : xOrigin);
    yOrigin = bounds.y + (~(originSplit[1] || originSplit[0]).indexOf("%") ? yOrigin / 100 * bounds.height : yOrigin);
  } else if (matrix !== _identity2DMatrix && (determinant = a * d - b * c)) {
    //if it's zero (like if scaleX and scaleY are zero), skip it to avoid errors with dividing by zero.
    x = xOrigin * (d / determinant) + yOrigin * (-c / determinant) + (c * ty - d * tx) / determinant;
    y = xOrigin * (-b / determinant) + yOrigin * (a / determinant) - (a * ty - b * tx) / determinant;
    xOrigin = x;
    yOrigin = y;
  }

  if (smooth || smooth !== false && cache.smooth) {
    tx = xOrigin - xOriginOld;
    ty = yOrigin - yOriginOld;
    cache.xOffset = xOffsetOld + (tx * a + ty * c) - tx;
    cache.yOffset = yOffsetOld + (tx * b + ty * d) - ty;
  } else {
    cache.xOffset = cache.yOffset = 0;
  }

  cache.xOrigin = xOrigin;
  cache.yOrigin = yOrigin;
  cache.smooth = !!smooth;
  cache.origin = origin;
  cache.originIsAbsolute = !!originIsAbsolute;
  target.style[_transformOriginProp] = "0px 0px"; //otherwise, if someone sets  an origin via CSS, it will likely interfere with the SVG transform attribute ones (because remember, we're baking the origin into the matrix() value).

  if (pluginToAddPropTweensTo) {
    CSSPlugin_addNonTweeningPT(pluginToAddPropTweensTo, cache, "xOrigin", xOriginOld, xOrigin);

    CSSPlugin_addNonTweeningPT(pluginToAddPropTweensTo, cache, "yOrigin", yOriginOld, yOrigin);

    CSSPlugin_addNonTweeningPT(pluginToAddPropTweensTo, cache, "xOffset", xOffsetOld, cache.xOffset);

    CSSPlugin_addNonTweeningPT(pluginToAddPropTweensTo, cache, "yOffset", yOffsetOld, cache.yOffset);
  }

  target.setAttribute("data-svg-origin", xOrigin + " " + yOrigin);
},
    CSSPlugin_parseTransform = function _parseTransform(target, uncache) {
  var cache = target._gsap || new GSCache(target);

  if ("x" in cache && !uncache && !cache.uncache) {
    return cache;
  }

  var style = target.style,
      invertedScaleX = cache.scaleX < 0,
      px = "px",
      deg = "deg",
      origin = _getComputedProperty(target, _transformOriginProp) || "0",
      x,
      y,
      z,
      scaleX,
      scaleY,
      rotation,
      rotationX,
      rotationY,
      skewX,
      skewY,
      perspective,
      xOrigin,
      yOrigin,
      matrix,
      angle,
      cos,
      sin,
      a,
      b,
      c,
      d,
      a12,
      a22,
      t1,
      t2,
      t3,
      a13,
      a23,
      a33,
      a42,
      a43,
      a32;
  x = y = z = rotation = rotationX = rotationY = skewX = skewY = perspective = 0;
  scaleX = scaleY = 1;
  cache.svg = !!(target.getCTM && _isSVG(target));
  matrix = CSSPlugin_getMatrix(target, cache.svg);

  if (cache.svg) {
    t1 = !cache.uncache && target.getAttribute("data-svg-origin");

    _applySVGOrigin(target, t1 || origin, !!t1 || cache.originIsAbsolute, cache.smooth !== false, matrix);
  }

  xOrigin = cache.xOrigin || 0;
  yOrigin = cache.yOrigin || 0;

  if (matrix !== _identity2DMatrix) {
    a = matrix[0]; //a11

    b = matrix[1]; //a21

    c = matrix[2]; //a31

    d = matrix[3]; //a41

    x = a12 = matrix[4];
    y = a22 = matrix[5]; //2D matrix

    if (matrix.length === 6) {
      scaleX = Math.sqrt(a * a + b * b);
      scaleY = Math.sqrt(d * d + c * c);
      rotation = a || b ? _atan2(b, a) * _RAD2DEG : 0; //note: if scaleX is 0, we cannot accurately measure rotation. Same for skewX with a scaleY of 0. Therefore, we default to the previously recorded value (or zero if that doesn't exist).

      skewX = c || d ? _atan2(c, d) * _RAD2DEG + rotation : 0;
      skewX && (scaleY *= Math.cos(skewX * _DEG2RAD));

      if (cache.svg) {
        x -= xOrigin - (xOrigin * a + yOrigin * c);
        y -= yOrigin - (xOrigin * b + yOrigin * d);
      } //3D matrix

    } else {
      a32 = matrix[6];
      a42 = matrix[7];
      a13 = matrix[8];
      a23 = matrix[9];
      a33 = matrix[10];
      a43 = matrix[11];
      x = matrix[12];
      y = matrix[13];
      z = matrix[14];
      angle = _atan2(a32, a33);
      rotationX = angle * _RAD2DEG; //rotationX

      if (angle) {
        cos = Math.cos(-angle);
        sin = Math.sin(-angle);
        t1 = a12 * cos + a13 * sin;
        t2 = a22 * cos + a23 * sin;
        t3 = a32 * cos + a33 * sin;
        a13 = a12 * -sin + a13 * cos;
        a23 = a22 * -sin + a23 * cos;
        a33 = a32 * -sin + a33 * cos;
        a43 = a42 * -sin + a43 * cos;
        a12 = t1;
        a22 = t2;
        a32 = t3;
      } //rotationY


      angle = _atan2(-c, a33);
      rotationY = angle * _RAD2DEG;

      if (angle) {
        cos = Math.cos(-angle);
        sin = Math.sin(-angle);
        t1 = a * cos - a13 * sin;
        t2 = b * cos - a23 * sin;
        t3 = c * cos - a33 * sin;
        a43 = d * sin + a43 * cos;
        a = t1;
        b = t2;
        c = t3;
      } //rotationZ


      angle = _atan2(b, a);
      rotation = angle * _RAD2DEG;

      if (angle) {
        cos = Math.cos(angle);
        sin = Math.sin(angle);
        t1 = a * cos + b * sin;
        t2 = a12 * cos + a22 * sin;
        b = b * cos - a * sin;
        a22 = a22 * cos - a12 * sin;
        a = t1;
        a12 = t2;
      }

      if (rotationX && Math.abs(rotationX) + Math.abs(rotation) > 359.9) {
        //when rotationY is set, it will often be parsed as 180 degrees different than it should be, and rotationX and rotation both being 180 (it looks the same), so we adjust for that here.
        rotationX = rotation = 0;
        rotationY = 180 - rotationY;
      }

      scaleX = _round(Math.sqrt(a * a + b * b + c * c));
      scaleY = _round(Math.sqrt(a22 * a22 + a32 * a32));
      angle = _atan2(a12, a22);
      skewX = Math.abs(angle) > 0.0002 ? angle * _RAD2DEG : 0;
      perspective = a43 ? 1 / (a43 < 0 ? -a43 : a43) : 0;
    }

    if (cache.svg) {
      //sense if there are CSS transforms applied on an SVG element in which case we must overwrite them when rendering. The transform attribute is more reliable cross-browser, but we can't just remove the CSS ones because they may be applied in a CSS rule somewhere (not just inline).
      t1 = target.getAttribute("transform");
      cache.forceCSS = target.setAttribute("transform", "") || !_isNullTransform(_getComputedProperty(target, _transformProp));
      t1 && target.setAttribute("transform", t1);
    }
  }

  if (Math.abs(skewX) > 90 && Math.abs(skewX) < 270) {
    if (invertedScaleX) {
      scaleX *= -1;
      skewX += rotation <= 0 ? 180 : -180;
      rotation += rotation <= 0 ? 180 : -180;
    } else {
      scaleY *= -1;
      skewX += skewX <= 0 ? 180 : -180;
    }
  }

  cache.x = ((cache.xPercent = x && Math.round(target.offsetWidth / 2) === Math.round(-x) ? -50 : 0) ? 0 : x) + px;
  cache.y = ((cache.yPercent = y && Math.round(target.offsetHeight / 2) === Math.round(-y) ? -50 : 0) ? 0 : y) + px;
  cache.z = z + px;
  cache.scaleX = _round(scaleX);
  cache.scaleY = _round(scaleY);
  cache.rotation = _round(rotation) + deg;
  cache.rotationX = _round(rotationX) + deg;
  cache.rotationY = _round(rotationY) + deg;
  cache.skewX = skewX + deg;
  cache.skewY = skewY + deg;
  cache.transformPerspective = perspective + px;

  if (cache.zOrigin = parseFloat(origin.split(" ")[2]) || 0) {
    style[_transformOriginProp] = _firstTwoOnly(origin);
  }

  cache.xOffset = cache.yOffset = 0;
  cache.force3D = _config.force3D;
  cache.renderTransform = cache.svg ? CSSPlugin_renderSVGTransforms : _supports3D ? _renderCSSTransforms : _renderNon3DTransforms;
  cache.uncache = 0;
  return cache;
},
    _firstTwoOnly = function _firstTwoOnly(value) {
  return (value = value.split(" "))[0] + " " + value[1];
},
    //for handling transformOrigin values, stripping out the 3rd dimension
CSSPlugin_addPxTranslate = function _addPxTranslate(target, start, value) {
  var unit = getUnit(start);
  return _round(parseFloat(start) + parseFloat(CSSPlugin_convertToUnit(target, "x", value + "px", unit))) + unit;
},
    _renderNon3DTransforms = function _renderNon3DTransforms(ratio, cache) {
  cache.z = "0px";
  cache.rotationY = cache.rotationX = "0deg";
  cache.force3D = 0;

  _renderCSSTransforms(ratio, cache);
},
    _zeroDeg = "0deg",
    _zeroPx = "0px",
    _endParenthesis = ") ",
    _renderCSSTransforms = function _renderCSSTransforms(ratio, cache) {
  var _ref = cache || this,
      xPercent = _ref.xPercent,
      yPercent = _ref.yPercent,
      x = _ref.x,
      y = _ref.y,
      z = _ref.z,
      rotation = _ref.rotation,
      rotationY = _ref.rotationY,
      rotationX = _ref.rotationX,
      skewX = _ref.skewX,
      skewY = _ref.skewY,
      scaleX = _ref.scaleX,
      scaleY = _ref.scaleY,
      transformPerspective = _ref.transformPerspective,
      force3D = _ref.force3D,
      target = _ref.target,
      zOrigin = _ref.zOrigin,
      transforms = "",
      use3D = force3D === "auto" && ratio && ratio !== 1 || force3D === true; // Safari has a bug that causes it not to render 3D transform-origin values properly, so we force the z origin to 0, record it in the cache, and then do the math here to offset the translate values accordingly (basically do the 3D transform-origin part manually)


  if (zOrigin && (rotationX !== _zeroDeg || rotationY !== _zeroDeg)) {
    var angle = parseFloat(rotationY) * _DEG2RAD,
        a13 = Math.sin(angle),
        a33 = Math.cos(angle),
        cos;

    angle = parseFloat(rotationX) * _DEG2RAD;
    cos = Math.cos(angle);
    x = CSSPlugin_addPxTranslate(target, x, a13 * cos * -zOrigin);
    y = CSSPlugin_addPxTranslate(target, y, -Math.sin(angle) * -zOrigin);
    z = CSSPlugin_addPxTranslate(target, z, a33 * cos * -zOrigin + zOrigin);
  }

  if (transformPerspective !== _zeroPx) {
    transforms += "perspective(" + transformPerspective + _endParenthesis;
  }

  if (xPercent || yPercent) {
    transforms += "translate(" + xPercent + "%, " + yPercent + "%) ";
  }

  if (use3D || x !== _zeroPx || y !== _zeroPx || z !== _zeroPx) {
    transforms += z !== _zeroPx || use3D ? "translate3d(" + x + ", " + y + ", " + z + ") " : "translate(" + x + ", " + y + _endParenthesis;
  }

  if (rotation !== _zeroDeg) {
    transforms += "rotate(" + rotation + _endParenthesis;
  }

  if (rotationY !== _zeroDeg) {
    transforms += "rotateY(" + rotationY + _endParenthesis;
  }

  if (rotationX !== _zeroDeg) {
    transforms += "rotateX(" + rotationX + _endParenthesis;
  }

  if (skewX !== _zeroDeg || skewY !== _zeroDeg) {
    transforms += "skew(" + skewX + ", " + skewY + _endParenthesis;
  }

  if (scaleX !== 1 || scaleY !== 1) {
    transforms += "scale(" + scaleX + ", " + scaleY + _endParenthesis;
  }

  target.style[_transformProp] = transforms || "translate(0, 0)";
},
    CSSPlugin_renderSVGTransforms = function _renderSVGTransforms(ratio, cache) {
  var _ref2 = cache || this,
      xPercent = _ref2.xPercent,
      yPercent = _ref2.yPercent,
      x = _ref2.x,
      y = _ref2.y,
      rotation = _ref2.rotation,
      skewX = _ref2.skewX,
      skewY = _ref2.skewY,
      scaleX = _ref2.scaleX,
      scaleY = _ref2.scaleY,
      target = _ref2.target,
      xOrigin = _ref2.xOrigin,
      yOrigin = _ref2.yOrigin,
      xOffset = _ref2.xOffset,
      yOffset = _ref2.yOffset,
      forceCSS = _ref2.forceCSS,
      tx = parseFloat(x),
      ty = parseFloat(y),
      a11,
      a21,
      a12,
      a22,
      temp;

  rotation = parseFloat(rotation);
  skewX = parseFloat(skewX);
  skewY = parseFloat(skewY);

  if (skewY) {
    //for performance reasons, we combine all skewing into the skewX and rotation values. Remember, a skewY of 10 degrees looks the same as a rotation of 10 degrees plus a skewX of 10 degrees.
    skewY = parseFloat(skewY);
    skewX += skewY;
    rotation += skewY;
  }

  if (rotation || skewX) {
    rotation *= _DEG2RAD;
    skewX *= _DEG2RAD;
    a11 = Math.cos(rotation) * scaleX;
    a21 = Math.sin(rotation) * scaleX;
    a12 = Math.sin(rotation - skewX) * -scaleY;
    a22 = Math.cos(rotation - skewX) * scaleY;

    if (skewX) {
      skewY *= _DEG2RAD;
      temp = Math.tan(skewX - skewY);
      temp = Math.sqrt(1 + temp * temp);
      a12 *= temp;
      a22 *= temp;

      if (skewY) {
        temp = Math.tan(skewY);
        temp = Math.sqrt(1 + temp * temp);
        a11 *= temp;
        a21 *= temp;
      }
    }

    a11 = _round(a11);
    a21 = _round(a21);
    a12 = _round(a12);
    a22 = _round(a22);
  } else {
    a11 = scaleX;
    a22 = scaleY;
    a21 = a12 = 0;
  }

  if (tx && !~(x + "").indexOf("px") || ty && !~(y + "").indexOf("px")) {
    tx = CSSPlugin_convertToUnit(target, "x", x, "px");
    ty = CSSPlugin_convertToUnit(target, "y", y, "px");
  }

  if (xOrigin || yOrigin || xOffset || yOffset) {
    tx = _round(tx + xOrigin - (xOrigin * a11 + yOrigin * a12) + xOffset);
    ty = _round(ty + yOrigin - (xOrigin * a21 + yOrigin * a22) + yOffset);
  }

  if (xPercent || yPercent) {
    //The SVG spec doesn't support percentage-based translation in the "transform" attribute, so we merge it into the translation to simulate it.
    temp = target.getBBox();
    tx = _round(tx + xPercent / 100 * temp.width);
    ty = _round(ty + yPercent / 100 * temp.height);
  }

  temp = "matrix(" + a11 + "," + a21 + "," + a12 + "," + a22 + "," + tx + "," + ty + ")";
  target.setAttribute("transform", temp);

  if (forceCSS) {
    //some browsers prioritize CSS transforms over the transform attribute. When we sense that the user has CSS transforms applied, we must overwrite them this way (otherwise some browser simply won't render the  transform attribute changes!)
    target.style[_transformProp] = temp;
  }
},
    CSSPlugin_addRotationalPropTween = function _addRotationalPropTween(plugin, target, property, startNum, endValue, relative) {
  var cap = 360,
      isString = _isString(endValue),
      endNum = parseFloat(endValue) * (isString && ~endValue.indexOf("rad") ? _RAD2DEG : 1),
      change = relative ? endNum * relative : endNum - startNum,
      finalValue = startNum + change + "deg",
      direction,
      pt;

  if (isString) {
    direction = endValue.split("_")[1];

    if (direction === "short") {
      change %= cap;

      if (change !== change % (cap / 2)) {
        change += change < 0 ? cap : -cap;
      }
    }

    if (direction === "cw" && change < 0) {
      change = (change + cap * CSSPlugin_bigNum) % cap - ~~(change / cap) * cap;
    } else if (direction === "ccw" && change > 0) {
      change = (change - cap * CSSPlugin_bigNum) % cap - ~~(change / cap) * cap;
    }
  }

  plugin._pt = pt = new PropTween(plugin._pt, target, property, startNum, change, _renderPropWithEnd);
  pt.e = finalValue;
  pt.u = "deg";

  plugin._props.push(property);

  return pt;
},
    CSSPlugin_addRawTransformPTs = function _addRawTransformPTs(plugin, transforms, target) {
  //for handling cases where someone passes in a whole transform string, like transform: "scale(2, 3) rotate(20deg) translateY(30em)"
  var style = _tempDivStyler.style,
      startCache = target._gsap,
      exclude = "perspective,force3D,transformOrigin,svgOrigin",
      endCache,
      p,
      startValue,
      endValue,
      startNum,
      endNum,
      startUnit,
      endUnit;
  style.cssText = getComputedStyle(target).cssText + ";position:absolute;display:block;"; //%-based translations will fail unless we set the width/height to match the original target (and padding/borders can affect it)

  style[_transformProp] = transforms;

  CSSPlugin_doc.body.appendChild(_tempDivStyler);

  endCache = CSSPlugin_parseTransform(_tempDivStyler, 1);

  for (p in _transformProps) {
    startValue = startCache[p];
    endValue = endCache[p];

    if (startValue !== endValue && exclude.indexOf(p) < 0) {
      //tweening to no perspective gives very unintuitive results - just keep the same perspective in that case.
      startUnit = getUnit(startValue);
      endUnit = getUnit(endValue);
      startNum = startUnit !== endUnit ? CSSPlugin_convertToUnit(target, p, startValue, endUnit) : parseFloat(startValue);
      endNum = parseFloat(endValue);
      plugin._pt = new PropTween(plugin._pt, startCache, p, startNum, endNum - startNum, _renderCSSProp);
      plugin._pt.u = endUnit || 0;

      plugin._props.push(p);
    }
  }

  CSSPlugin_doc.body.removeChild(_tempDivStyler);
}; // handle splitting apart padding, margin, borderWidth, and borderRadius into their 4 components. Firefox, for example, won't report borderRadius correctly - it will only do borderTopLeftRadius and the other corners. We also want to handle paddingTop, marginLeft, borderRightWidth, etc.


_forEachName("padding,margin,Width,Radius", function (name, index) {
  var t = "Top",
      r = "Right",
      b = "Bottom",
      l = "Left",
      props = (index < 3 ? [t, r, b, l] : [t + l, t + r, b + r, b + l]).map(function (side) {
    return index < 2 ? name + side : "border" + side + name;
  });

  _specialProps[index > 1 ? "border" + name : name] = function (plugin, target, property, endValue, tween) {
    var a, vars;

    if (arguments.length < 4) {
      // getter, passed target, property, and unit (from _get())
      a = props.map(function (prop) {
        return CSSPlugin_get(plugin, prop, property);
      });
      vars = a.join(" ");
      return vars.split(a[0]).length === 5 ? a[0] : vars;
    }

    a = (endValue + "").split(" ");
    vars = {};
    props.forEach(function (prop, i) {
      return vars[prop] = a[i] = a[i] || a[(i - 1) / 2 | 0];
    });
    plugin.init(target, vars, tween);
  };
});

var CSSPlugin = {
  name: "css",
  register: _initCore,
  targetTest: function targetTest(target) {
    return target.style && target.nodeType;
  },
  init: function init(target, vars, tween, index, targets) {
    var props = this._props,
        style = target.style,
        startValue,
        endValue,
        endNum,
        startNum,
        type,
        specialProp,
        p,
        startUnit,
        endUnit,
        relative,
        isTransformRelated,
        transformPropTween,
        cache,
        smooth,
        hasPriority;
    _pluginInitted || _initCore();

    for (p in vars) {
      if (p === "autoRound") {
        continue;
      }

      endValue = vars[p];

      if (_plugins[p] && _checkPlugin(p, vars, tween, index, target, targets)) {
        //plugins
        continue;
      }

      type = typeof endValue;
      specialProp = _specialProps[p];

      if (type === "function") {
        endValue = endValue.call(tween, index, target, targets);
        type = typeof endValue;
      }

      if (type === "string" && ~endValue.indexOf("random(")) {
        endValue = _replaceRandom(endValue);
      }

      if (specialProp) {
        if (specialProp(this, target, p, endValue, tween)) {
          hasPriority = 1;
        }
      } else if (p.substr(0, 2) === "--") {
        //CSS variable
        this.add(style, "setProperty", getComputedStyle(target).getPropertyValue(p) + "", endValue + "", index, targets, 0, 0, p);
      } else if (type !== "undefined") {
        startValue = CSSPlugin_get(target, p);
        startNum = parseFloat(startValue);
        relative = type === "string" && endValue.charAt(1) === "=" ? +(endValue.charAt(0) + "1") : 0;

        if (relative) {
          endValue = endValue.substr(2);
        }

        endNum = parseFloat(endValue);

        if (p in _propertyAliases) {
          if (p === "autoAlpha") {
            //special case where we control the visibility along with opacity. We still allow the opacity value to pass through and get tweened.
            if (startNum === 1 && CSSPlugin_get(target, "visibility") === "hidden" && endNum) {
              //if visibility is initially set to "hidden", we should interpret that as intent to make opacity 0 (a convenience)
              startNum = 0;
            }

            CSSPlugin_addNonTweeningPT(this, style, "visibility", startNum ? "inherit" : "hidden", endNum ? "inherit" : "hidden", !endNum);
          }

          if (p !== "scale" && p !== "transform") {
            p = _propertyAliases[p];
            ~p.indexOf(",") && (p = p.split(",")[0]);
          }
        }

        isTransformRelated = p in _transformProps; //--- TRANSFORM-RELATED ---

        if (isTransformRelated) {
          if (!transformPropTween) {
            cache = target._gsap;
            cache.renderTransform || CSSPlugin_parseTransform(target); // if, for example, gsap.set(... {transform:"translateX(50vw)"}), the _get() call doesn't parse the transform, thus cache.renderTransform won't be set yet so force the parsing of the transform here.

            smooth = vars.smoothOrigin !== false && cache.smooth;
            transformPropTween = this._pt = new PropTween(this._pt, style, _transformProp, 0, 1, cache.renderTransform, cache, 0, -1); //the first time through, create the rendering PropTween so that it runs LAST (in the linked list, we keep adding to the beginning)

            transformPropTween.dep = 1; //flag it as dependent so that if things get killed/overwritten and this is the only PropTween left, we can safely kill the whole tween.
          }

          if (p === "scale") {
            this._pt = new PropTween(this._pt, cache, "scaleY", cache.scaleY, relative ? relative * endNum : endNum - cache.scaleY);
            props.push("scaleY", p);
            p += "X";
          } else if (p === "transformOrigin") {
            endValue = _convertKeywordsToPercentages(endValue); //in case something like "left top" or "bottom right" is passed in. Convert to percentages.

            if (cache.svg) {
              _applySVGOrigin(target, endValue, 0, smooth, 0, this);
            } else {
              endUnit = parseFloat(endValue.split(" ")[2]) || 0; //handle the zOrigin separately!

              endUnit !== cache.zOrigin && CSSPlugin_addNonTweeningPT(this, cache, "zOrigin", cache.zOrigin, endUnit);

              CSSPlugin_addNonTweeningPT(this, style, p, _firstTwoOnly(startValue), _firstTwoOnly(endValue));
            }

            continue;
          } else if (p === "svgOrigin") {
            _applySVGOrigin(target, endValue, 1, smooth, 0, this);

            continue;
          } else if (p in _rotationalProperties) {
            CSSPlugin_addRotationalPropTween(this, cache, p, startNum, endValue, relative);

            continue;
          } else if (p === "smoothOrigin") {
            CSSPlugin_addNonTweeningPT(this, cache, "smooth", cache.smooth, endValue);

            continue;
          } else if (p === "force3D") {
            cache[p] = endValue;
            continue;
          } else if (p === "transform") {
            CSSPlugin_addRawTransformPTs(this, endValue, target);

            continue;
          }
        } else if (!(p in style)) {
          p = _checkPropPrefix(p) || p;
        }

        if (isTransformRelated || (endNum || endNum === 0) && (startNum || startNum === 0) && !_complexExp.test(endValue) && p in style) {
          startUnit = (startValue + "").substr((startNum + "").length);
          endNum || (endNum = 0); // protect against NaN

          endUnit = getUnit(endValue) || (p in _config.units ? _config.units[p] : startUnit);
          startUnit !== endUnit && (startNum = CSSPlugin_convertToUnit(target, p, startValue, endUnit));
          this._pt = new PropTween(this._pt, isTransformRelated ? cache : style, p, startNum, relative ? relative * endNum : endNum - startNum, endUnit === "px" && vars.autoRound !== false && !isTransformRelated ? _renderRoundedCSSProp : _renderCSSProp);
          this._pt.u = endUnit || 0;

          if (startUnit !== endUnit) {
            //when the tween goes all the way back to the beginning, we need to revert it to the OLD/ORIGINAL value (with those units). We record that as a "b" (beginning) property and point to a render method that handles that. (performance optimization)
            this._pt.b = startValue;
            this._pt.r = _renderCSSPropWithBeginning;
          }
        } else if (!(p in style)) {
          if (p in target) {
            //maybe it's not a style - it could be a property added directly to an element in which case we'll try to animate that.
            this.add(target, p, target[p], endValue, index, targets);
          } else {
            _missingPlugin(p, endValue);

            continue;
          }
        } else {
          CSSPlugin_tweenComplexCSSString.call(this, target, p, startValue, endValue);
        }

        props.push(p);
      }
    }

    hasPriority && _sortPropTweensByPriority(this);
  },
  get: CSSPlugin_get,
  aliases: _propertyAliases,
  getSetter: function getSetter(target, property, plugin) {
    //returns a setter function that accepts target, property, value and applies it accordingly. Remember, properties like "x" aren't as simple as target.style.property = value because they've got to be applied to a proxy object and then merged into a transform string in a renderer.
    var p = _propertyAliases[property];
    p && p.indexOf(",") < 0 && (property = p);
    return property in _transformProps && property !== _transformOriginProp && (target._gsap.x || CSSPlugin_get(target, "x")) ? plugin && _recentSetterPlugin === plugin ? property === "scale" ? _setterScale : _setterTransform : (_recentSetterPlugin = plugin || {}) && (property === "scale" ? _setterScaleWithRender : _setterTransformWithRender) : target.style && !_isUndefined(target.style[property]) ? _setterCSSStyle : ~property.indexOf("-") ? _setterCSSProp : _getSetter(target, property);
  },
  core: {
    _removeProperty: _removeProperty,
    _getMatrix: CSSPlugin_getMatrix
  }
};
gsap.utils.checkPrefix = _checkPropPrefix;

(function (positionAndScale, rotation, others, aliases) {
  var all = _forEachName(positionAndScale + "," + rotation + "," + others, function (name) {
    _transformProps[name] = 1;
  });

  _forEachName(rotation, function (name) {
    _config.units[name] = "deg";
    _rotationalProperties[name] = 1;
  });

  _propertyAliases[all[13]] = positionAndScale + "," + rotation;

  _forEachName(aliases, function (name) {
    var split = name.split(":");
    _propertyAliases[split[1]] = all[split[0]];
  });
})("x,y,z,scale,scaleX,scaleY,xPercent,yPercent", "rotation,rotationX,rotationY,skewX,skewY", "transform,transformOrigin,svgOrigin,force3D,smoothOrigin,transformPerspective", "0:translateX,1:translateY,2:translateZ,8:rotate,8:rotationZ,8:rotateZ,9:rotateX,10:rotateY");

_forEachName("x,y,z,top,right,bottom,left,width,height,fontSize,padding,margin,perspective", function (name) {
  _config.units[name] = "px";
});

gsap.registerPlugin(CSSPlugin);

// CONCATENATED MODULE: ./node_modules/gsap/index.js


var gsapWithCSS = gsap.registerPlugin(CSSPlugin) || gsap,
    // to protect from tree shaking
TweenMaxWithCSS = gsapWithCSS.core.Tween;

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/address/address.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//



/* harmony default export */ var addressvue_type_script_lang_js_ = ({
  name: 'nut-address',
  props: {
    value: {
      type: Boolean,
      default: false
    },
    type: {
      type: String,
      default: 'custom'
    },
    customAddressTitle: {
      type: String,
      default: '请选择所在地区'
    },
    province: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    // 省
    city: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    // 市
    country: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    // 县
    town: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    // 镇
    isShowCustomAddress: {
      type: Boolean,
      default: true
    },
    // 是否显示‘选择其他地区’按钮 type=‘exist’ 生效
    existAddress: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    // 现存地址列表
    existAddressTitle: {
      type: String,
      default: '配送至'
    },
    customAndExistTitle: {
      type: String,
      default: '选择其他地址'
    },
    defaultIcon: {
      // 地址选择列表前 - 默认的图标
      type: String,
      default: __webpack_require__(16)
    },
    selectedIcon: {
      // 地址选择列表前 - 选中的图标
      type: String,
      default: __webpack_require__(22)
    },
    closeBtnIcon: {
      // 关闭弹框按钮 icon
      type: String,
      default: __webpack_require__(18)
    },
    backBtnIcon: {
      // 选择其他地址左上角返回 icon
      type: String,
      default: __webpack_require__(17)
    }
  },
  data: function data() {
    return {
      showPopup: false,
      showModule: 'exist',
      //展示 exist 还是 custom 主要用于‘选择其他地址’
      tabIndex: 0,
      tabName: ['province', 'city', 'country', 'town'],
      regionList: {
        province: this.province,
        city: this.city,
        country: this.country,
        town: this.town
      },
      //省、市、县、镇列表,地址id字符串,地址字符串
      selectedRegion: {
        province: {},
        city: {},
        country: {},
        town: {}
      },
      //已选择的 省、市、县、镇
      selectedExistAddress: {} // 当前选择的地址

    };
  },
  components: {
    'nut-popup': popup,
    'nut-icon': icon
  },
  watch: {
    value: function value(newVal, oldVal) {
      this.showPopup = newVal;
    },
    showPopup: function showPopup(newVal, oldVal) {
      if (newVal == false) this.$emit('input', false);

      if (newVal == true) {
        this.showModule = this.type;
      }
    },
    province: function province(newVal, oldVal) {
      this.regionList.province = newVal;
    },
    city: function city(newVal, oldVal) {
      this.regionList.city = newVal;
    },
    country: function country(newVal, oldVal) {
      this.regionList.country = newVal;
    },
    town: function town(newVal, oldVal) {
      this.regionList.town = newVal;
    },
    existAddress: function existAddress(newVal, oldVal) {
      var _this = this;

      this.existAddress = newVal;
      newVal.forEach(function (item, index) {
        if (item.selectedAddress) {
          _this.selectedExistAddress = item;
        }
      });
    }
  },
  mounted: function mounted() {},
  methods: {
    //获取已选地区列表名称
    getTabName: function getTabName(item, index) {
      if (item.name) return item.name;

      if (this.tabIndex < index) {
        return item.name;
      } else {
        return '请选择';
      }
    },
    // 切换下一级列表
    nextAreaList: function nextAreaList(item) {
      // onchange 接收的参数
      var calBack = {
        custom: this.tabName[this.tabIndex]
      };
      this.selectedRegion[this.tabName[this.tabIndex]] = item;

      for (var i = this.tabIndex; i < this.tabName.length - 1; i++) {
        this.selectedRegion[this.tabName[i + 1]] = {};
      }

      if (this.tabIndex < 3) {
        this.tabIndex = this.tabIndex + 1;
        this.lineAnimation(); // 切换下一个

        calBack.next = this.tabName[this.tabIndex];
        calBack.value = item;
        this.$emit('onChange', calBack);
        this.$emit('on-change', calBack);
      } else {
        this.handClose();
      }
    },
    //切换地区Tab
    changeRegionTab: function changeRegionTab(item, key, index) {
      this.tabIndex = index;
      this.lineAnimation();
    },
    // 移动下面的红线
    lineAnimation: function lineAnimation() {
      var _this2 = this;

      var name = 'tab-item-' + this.tabName[this.tabIndex];
      this.$nextTick(function () {
        if (_this2.$refs[name] && _this2.$refs[name][0]) {
          var distance = _this2.$refs[name][0].offsetLeft;
          TweenMaxWithCSS.to(_this2.$refs.regionLine, 0.5, {
            left: distance
          });
        }
      });
    },
    // 选择现有地址
    selectedExist: function selectedExist(item) {
      var copyExistAdd = this.existAddress;
      var prevExistAdd = {};
      copyExistAdd.forEach(function (list, index) {
        if (list.selectedAddress) {
          prevExistAdd = list;
        }

        list.selectedAddress = false;
      });
      item.selectedAddress = true;
      this.selectedExistAddress = item;
      this.$emit('selected', prevExistAdd, item, copyExistAdd);
      this.handClose();
    },
    // 关闭
    close: function close() {
      var that = this;

      var resCopy = extends_default()({}, this.selectedRegion);

      var res = {
        type: this.showModule,
        data: {}
      };

      if (this.showModule == 'custom') {
        var province = resCopy.province,
            city = resCopy.city,
            country = resCopy.country,
            town = resCopy.town;
        resCopy.addressIdStr = [province.id || 0, city.id || 0, country.id || 0, town.id || 0].join('_');
        resCopy.addressStr = [province.name, city.name, country.name, town.name].join('');
        res.data = resCopy;
      } else {
        res.data = this.selectedExistAddress;
      }

      this.initAddress();

      if (this.closeWay == 'self') {
        this.$emit('close', res);
      } else {
        this.$emit('closeMask', {
          closeWay: this.closeWay
        });
        this.$emit('close-mask', {
          closeWay: this.closeWay
        });
      }

      setTimeout(function () {
        that.showModule = 'type';
      }, 500);
    },
    // 手动关闭 点击叉号(cross)，或者蒙层(mask)
    handClose: function handClose() {
      var type = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 'self';
      if (!this.closeBtnIcon) return;
      this.closeWay = type == 'cross' ? 'cross' : 'self';
      this.showPopup = false;
    },
    // 点击遮罩层关闭
    clickOverlay: function clickOverlay() {
      this.closeWay = 'mask';
    },
    // 初始化
    initAddress: function initAddress() {
      for (var i = 0; i < this.tabName.length; i++) {
        this.selectedRegion[this.tabName[i]] = {};
      }

      this.tabIndex = 0;
      this.lineAnimation();
    },
    // 选择其他地址
    switchModule: function switchModule() {
      if (this.showModule == 'exist') {
        this.showModule = 'custom';
      } else {
        this.showModule = 'exist';
      }

      this.initAddress();
      this.$emit('switchModule', {
        type: this.showModule
      });
      this.$emit('switch-module', {
        type: this.showModule
      });
    }
  }
});
// CONCATENATED MODULE: ./src/packages/address/address.vue?vue&type=script&lang=js&
 /* harmony default export */ var address_addressvue_type_script_lang_js_ = (addressvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/address/address.vue





/* normalize component */

var address_component = normalizeComponent(
  address_addressvue_type_script_lang_js_,
  addressvue_type_template_id_e821993a_render,
  addressvue_type_template_id_e821993a_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var address = (address_component.exports);
// EXTERNAL MODULE: ./src/packages/address/address.scss
var address_address = __webpack_require__(76);

// CONCATENATED MODULE: ./src/packages/address/index.js



address.install = function (Vue) {
  Vue.component(address.name, address);
};

/* harmony default export */ var packages_address = (address);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/notify/notify.vue?vue&type=template&id=365511a8&
var notifyvue_type_template_id_365511a8_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('nut-popup',{class:['nut-notify', ("nut-notify--" + _vm.type), { className: _vm.className }],style:({ color: _vm.color, background: _vm.background }),attrs:{"position":"top","overlay":false,"lockScroll":false},on:{"click":_vm.handleClick,"opened":_vm.handleOpened,"closed":_vm.handleClosed},model:{value:(_vm.curVisible),callback:function ($$v) {_vm.curVisible=$$v},expression:"curVisible"}},[(_vm.$slots.default)?[_vm._t("default")]:[_vm._v(_vm._s(_vm.msg))]],2)}
var notifyvue_type_template_id_365511a8_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/notify/notify.vue?vue&type=template&id=365511a8&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/notify/notify.vue?vue&type=script&lang=js&


function notifyvue_type_script_lang_js_ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function notifyvue_type_script_lang_js_objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { notifyvue_type_script_lang_js_ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { notifyvue_type_script_lang_js_ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


/* harmony default export */ var notifyvue_type_script_lang_js_ = ({
  name: 'nut-notify',
  props: notifyvue_type_script_lang_js_objectSpread(notifyvue_type_script_lang_js_objectSpread({}, overlayProps), {}, {
    color: {
      type: String,
      default: ''
    },
    msg: {
      type: [Number, String],
      default: ''
    },
    duration: {
      type: [Number, String],
      default: 3000
    },
    className: {
      type: String,
      default: ''
    },
    background: {
      type: String,
      default: ''
    },
    type: {
      type: String,
      default: 'danger'
    },
    showPopup: {
      type: Boolean,
      default: false
    }
  }),
  watch: {
    showPopup: {
      handler: function handler(val) {
        if (val) {
          this.curVisible = val;
          this.show();
        }
      } // immediate: true

    }
  },
  data: function data() {
    return {
      timer: null,
      curVisible: false
    };
  },
  components: {
    'nut-popup': popup
  },
  methods: {
    handleClick: function handleClick() {
      typeof this.onClick === 'function' && this.onClick();
    },
    handleOpened: function handleOpened() {
      typeof this.onOpened === 'function' && this.onOpened();
    },
    handleClosed: function handleClosed() {
      typeof this.onClosed === 'function' && this.onClosed();
    },
    show: function show(force) {
      var _this = this;

      this.clearTimer();
      clearTimeout(this.textTimer);

      if (this.duration) {
        this.timer = setTimeout(function () {
          _this.hide(force);
        }, this.duration);
      }
    },
    hide: function hide(force) {
      var _this2 = this;

      this.clearTimer();
      this.curVisible = false;

      if (force) {
        clearTimeout(this.textTimer);
      } else {
        this.textTimer = setTimeout(function () {
          clearTimeout(_this2.textTimer);
        }, 300);
      }
    },
    clearTimer: function clearTimer() {
      if (this.timer) {
        clearTimeout(this.timer);
        this.timer = null;
      }
    }
  },
  destroyed: function destroyed() {
    this.textTimer = null;
    this.timer = null;
  }
});
// CONCATENATED MODULE: ./src/packages/notify/notify.vue?vue&type=script&lang=js&
 /* harmony default export */ var notify_notifyvue_type_script_lang_js_ = (notifyvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/notify/notify.vue





/* normalize component */

var notify_component = normalizeComponent(
  notify_notifyvue_type_script_lang_js_,
  notifyvue_type_template_id_365511a8_render,
  notifyvue_type_template_id_365511a8_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var notify = (notify_component.exports);
// CONCATENATED MODULE: ./src/packages/notify/_notify.js



function _notify_ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function _notify_objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { _notify_ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { _notify_ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }


 // 扩展为类

var NotifyConstructor = external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.extend(notify);
var timer,
    _notify_instance,
    _notify_instanceArr = [];
var _notify_defaultOptionsMap = {};
var id = '0'; // 默认传入值

var _notify_defaultOptions = {
  type: 'danger',
  showPopup: false,
  msg: '',
  color: undefined,
  background: undefined,
  duration: 3000,
  className: '',
  onClosed: null,
  onClick: null,
  onOpened: null,
  textTimer: null
}; // 当前传入值

var _notify_currentOptions = _notify_objectSpread({}, _notify_defaultOptions); // 展示，挂载


function _showNotify() {
  _notify_instance.vm = _notify_instance.$mount();
  document.body.appendChild(_notify_instance.$el);
  external_root_Vue_commonjs_vue_commonjs2_vue_amd_vue_default.a.nextTick(function () {
    _notify_instance.showPopup = true;
  });
}

function _notify_getInstance(obj) {
  // 默认传递的值
  var opt = {
    id: id
  };

  extends_default()(opt, _notify_currentOptions, _notify_defaultOptionsMap[obj.type], obj); // console.log(opt, obj, 'obj');
  //有相同id者共用一个实例，否则新增实例


  if (opt['id'] && _notify_instanceArr[opt['id']]) {
    _notify_instance = _notify_instanceArr[opt['id']];
    _notify_instance.hide(true);
    _notify_instance = extends_default()(_notify_instance, opt);
  } else {
    _notify_instance = new NotifyConstructor({
      propsData: opt
    });
    _notify_instance = extends_default()(_notify_instance, obj);
    opt['id'] && (_notify_instanceArr[opt['id']] = _notify_instance);
  }

  _showNotify();

  return _notify_instance;
}

function _notify_errorMsg(msg) {
  if (!msg) {
    console.warn('[NutUI Toast]: msg不能为空');
    return;
  }
}

var Notify = {
  text: function text(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    _notify_errorMsg(msg);
    return _notify_getInstance(_notify_objectSpread(_notify_objectSpread({}, obj), {}, {
      msg: msg
    }));
  },
  primary: function primary(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    _notify_errorMsg(msg);
    return _notify_getInstance(_notify_objectSpread(_notify_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'primary'
    }));
  },
  success: function success(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    _notify_errorMsg(msg);
    return _notify_getInstance(_notify_objectSpread(_notify_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'success'
    }));
  },
  danger: function danger(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    _notify_errorMsg(msg);
    return _notify_getInstance(_notify_objectSpread(_notify_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'danger'
    }));
  },
  warn: function warn(msg) {
    var obj = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
    _notify_errorMsg(msg);
    return _notify_getInstance(_notify_objectSpread(_notify_objectSpread({}, obj), {}, {
      msg: msg,
      type: 'warning'
    }));
  },
  // 全局设置默认内容
  setDefaultOptions: function setDefaultOptions(type, options) {
    if (typeof type === 'string') {
      _notify_defaultOptionsMap[type] = options;
    } else {
      extends_default()(_notify_currentOptions, type);
    }
  },
  // 重置默认内容
  resetDefaultOptions: function resetDefaultOptions(type) {
    if (typeof type === 'string') {
      _notify_defaultOptionsMap[type] = null;
    } else {
      _notify_currentOptions = _notify_objectSpread({}, _notify_defaultOptions);
      _notify_defaultOptionsMap = {};
    }
  }
};
/* harmony default export */ var _notify = (Notify);
// EXTERNAL MODULE: ./src/packages/notify/notify.scss
var notify_notify = __webpack_require__(77);

// CONCATENATED MODULE: ./src/packages/notify/index.js



var NotifyArr = [_notify, notify];

NotifyArr.install = function (Vue) {
  Vue.prototype['$notify'] = _notify;
  Vue.component(notify.name, notify);
};

/* harmony default export */ var packages_notify = (NotifyArr);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/countup/countup.vue?vue&type=template&id=17b952b6&
var countupvue_type_template_id_17b952b6_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-countup"},[(_vm.customBgImg != '')?[(_vm.type == 'machine')?[_c('ul',{staticClass:"run-number-machine-img",style:({ height: _vm.numHeight + 'px' })},_vm._l((_vm.machineNum),function(val,index){return _c('li',{key:'mImg' + index,ref:"run-number-machine-img-li",refInFor:true,staticClass:"run-number-machine-img-li",style:({
            width: _vm.numWidth + 'px',
            height: _vm.numHeight + 'px',
            backgroundImage: 'url(' + _vm.customBgImg + ')',
            backgroundPositionY: _vm.prizeY[index] + 'px'
          })})}),0)]:[_c('ul',{staticClass:"run-number-img",style:({ height: _vm.numHeight + 'px' })},[_vm._l((_vm.num_total_len),function(val,index){return _c('li',{key:'cImg' + index,staticClass:"run-number-img-li",style:({
            width: _vm.numWidth + 'px',
            height: _vm.numHeight + 'px',
            left:
              _vm.numWidth * (index > _vm.num_total_len - _vm.pointNum - 1 ? (index == _vm.num_total_len - _vm.pointNum ? index * 1.5 : index * 1.3) : index) + 'px',
            backgroundImage: 'url(' + _vm.customBgImg + ')',
            backgroundPosition: '0 ' + -(String(_vm.relNum)[index] * _vm.numHeight + _vm.customSpacNum * String(_vm.relNum)[index]) + 'px',
            transition: 'all linear ' + _vm.during / 10 + 'ms'
          })})}),_vm._v(" "),(_vm.pointNum > 0)?_c('div',{staticClass:"pointstyl",style:({
            width: _vm.numWidth / 2 + 'px',
            bottom: 0,
            left: _vm.numWidth * (_vm.num_total_len - _vm.pointNum) * 1.1 + 'px',
            fontSize: '30px'
          })},[_vm._v(".")]):_vm._e()],2)]]:[(_vm.scrolling)?_c('ul',{staticClass:"run-number",style:({ height: _vm.numHeight + 'px', lineHeight: _vm.numHeight + 'px' })},[_vm._l((_vm.num_total_len),function(val,index){return _c('li',{key:val,ref:"numberItem",refInFor:true,style:({
          top: _vm.topNumber(index),
          left: _vm.numWidth * (index > _vm.num_total_len - _vm.pointNum - 1 ? index * 1.1 : index) + 'px'
        }),attrs:{"turn-number":_vm.turnNumber(index)}},_vm._l((_vm.to0_10),function(item,idx){return _c('span',{key:'dote' + idx,style:({ width: _vm.numWidth + 'px', height: _vm.numHeight + 'px', lineHeight: _vm.numHeight + 'px' })},[_vm._v("\n          "+_vm._s(item)+"\n        ")])}),0)}),_vm._v(" "),(_vm.pointNum > 0)?_c('div',{staticClass:"pointstyl",style:({
          width: _vm.numWidth / 3 + 'px',
          height: _vm.numHeight + 'px',
          lineHeight: _vm.numHeight + 'px',
          top: 0,
          left: _vm.numWidth * (_vm.num_total_len - _vm.pointNum) + 'px'
        })},[_vm._v(".")]):_vm._e()],2):[_vm._v("\n      "+_vm._s(_vm.current)+"\n    ")]]],2)}
var countupvue_type_template_id_17b952b6_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/countup/countup.vue?vue&type=template&id=17b952b6&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/countup/countup.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var countupvue_type_script_lang_js_ = ({
  name: 'nut-countup',
  props: {
    initNum: {
      type: Number,
      default: 0
    },
    endNum: {
      type: Number,
      default: 0
    },
    speed: {
      type: Number,
      default: 1
    },
    toFixed: {
      type: Number,
      default: 0
    },
    during: {
      type: Number,
      default: 1000
    },
    startFlag: {
      type: Boolean,
      default: true
    },
    // 数字滚动
    numWidth: {
      type: Number,
      default: 20
    },
    numHeight: {
      type: Number,
      default: 20
    },
    scrolling: {
      type: Boolean,
      default: false
    },
    // 自定义图片
    customBgImg: {
      type: String,
      default: ''
    },
    customSpacNum: {
      type: Number,
      default: 0
    },
    customChangeNum: {
      type: Number,
      default: 1
    },
    // 抽奖
    type: {
      type: String,
      default: ''
    },
    machineNum: {
      type: Number,
      default: 3
    },
    machinePrizeNum: {
      type: Number,
      default: 0
    },
    machinePrizeLevel: {
      type: Number,
      default: 0
    },
    machineTrunMore: {
      type: Number,
      default: 0
    }
  },
  data: function data() {
    return {
      current: this.initNum,
      sortFlag: 'add',
      initDigit1: 0,
      initDigit2: 0,
      to0_10: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0],
      to10_0: [0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1],
      timer: null,
      totalCount: 0,
      //正整数
      pointNum: 0,
      //小数位
      numberVal: 0,
      //数字
      num_total_len: 0,
      //数字长度
      relNum: 0,
      //去除小数点
      customNumber: 1,
      prizeLevelTrun: 0,
      prizeY: [],
      prizeYPrev: [],
      // machineTransition: 'none',
      finshMachine: 0,
      notPrize: [],
      typeMachine: ''
    };
  },
  computed: {},
  watch: {
    customChangeNum: function customChangeNum(n, o) {
      this.customNumber = n;
      this.countGo();
    },
    machinePrizeLevel: function machinePrizeLevel(n, o) {
      this.prizeLevelTrun = n;
    }
  },
  mounted: function mounted() {
    if (this.startFlag) {
      if (this.scrolling || this.customBgImg) {
        if (this.type != 'machine') {
          this.countGo();
        }
      } else {
        this.countChange();
      }
    }
  },
  beforeDestroy: function beforeDestroy() {
    clearInterval(this.timer);
    this.timer = null;
  },
  methods: {
    // 清空定时器
    clearInterval: function (_clearInterval) {
      function clearInterval() {
        return _clearInterval.apply(this, arguments);
      }

      clearInterval.toString = function () {
        return _clearInterval.toString();
      };

      return clearInterval;
    }(function () {
      clearInterval(this.timer);
      this.timer = null;
    }),
    // 精确计算
    calculation: function calculation(num1, num2, type) {
      var num1Digits = (num1.toString().split('.')[1] || '').length;
      var num2Digits = (num2.toString().split('.')[1] || '').length;
      var baseNum = Math.pow(10, Math.max(num1Digits, num2Digits));

      if (type == '-') {
        return (num1 * baseNum - num2 * baseNum).toFixed(0) / baseNum;
      } else {
        return (num1 * baseNum + num2 * baseNum).toFixed(0) / baseNum;
      }
    },
    // 基本用法
    countChange: function countChange() {
      var _this = this;

      var endNum = this.endNum,
          initNum = this.initNum,
          speed = this.speed,
          toFixed = this.toFixed;
      var countTimer = setInterval(function () {
        if (initNum > endNum) {
          //减少
          if (_this.current <= endNum || _this.current <= speed) {
            //数字减小，有可能导致current小于speed
            _this.current = endNum.toFixed(toFixed);
            clearInterval(countTimer);

            _this.$emit('scroll-end');
          } else {
            _this.current = (parseFloat(_this.current) - parseFloat(speed)).toFixed(toFixed);
          }
        } else {
          //增加
          if (_this.current >= endNum) {
            _this.current = endNum.toFixed(toFixed);
            clearInterval(countTimer);

            _this.$emit('scroll-end');
          } else {
            _this.current = (parseFloat(_this.current) + parseFloat(speed)).toFixed(toFixed);
          }
        }
      }, this.during);
    },
    // 数字滚动-top值
    topNumber: function topNumber(index) {
      var num_total_len = this.num_total_len,
          pointNum = this.pointNum,
          initDigit1 = this.initDigit1,
          initDigit2 = this.initDigit2,
          sortFlag = this.sortFlag;
      var idx1 = sortFlag == 'add' ? initDigit2[index - (num_total_len - pointNum)] : 10 - initDigit2[index - (num_total_len - pointNum)];
      var idx2 = sortFlag == 'add' ? initDigit1[index] : 10 - initDigit1[index];
      var num = index > num_total_len - pointNum - 1 ? -idx1 * 100 + '%' : index <= initDigit1.length - 1 ? -idx2 * 100 + '%' : 0;

      if (num == '-1000%') {
        num = 0;
      }

      return num;
    },
    // 数字滚动-到哪里了
    turnNumber: function turnNumber(index) {
      var num_total_len = this.num_total_len,
          pointNum = this.pointNum,
          initDigit1 = this.initDigit1,
          initDigit2 = this.initDigit2,
          sortFlag = this.sortFlag;
      var idx1 = initDigit2[index - (num_total_len - pointNum)];
      var num = index > num_total_len - pointNum - 1 ? idx1 ? idx1 : 0 : index <= initDigit1.length - 1 ? initDigit1[index] : 0;
      return num;
    },
    countGo: function countGo() {
      var _this2 = this;

      var val = null;

      if (this.toFixed != 0) {// val = this.endNum.toFixed(this.toFixed);
        // this.initNum = this.initNum.toFixed(this.toFixed);
        // this.endNum = this.endNum.toFixed(this.toFixed);
      }

      var initNum = this.initNum,
          endNum = this.endNum,
          toFixed = this.toFixed,
          customBgImg = this.customBgImg;

      if (customBgImg) {
        initNum = this.customNumber;
      } // --------------


      var startNumber1, startNumber2, endNumber1, endNumber2;

      if (initNum != 0) {
        if (toFixed != 0) {
          initNum = initNum.toFixed(toFixed);
        }

        if (String(initNum).indexOf('.') > -1) {
          startNumber1 = String(initNum).split('.')[0].length;
          startNumber2 = String(initNum).split('.')[1].length;
        } else {
          startNumber1 = String(initNum).length;
          startNumber2 = 0;
        }
      } else {
        startNumber1 = 1;
        startNumber2 = 0;
      }

      if (endNum != 0) {
        if (toFixed != 0) {
          endNum = endNum.toFixed(toFixed);
        }

        if (String(endNum).indexOf('.') > -1) {
          endNumber1 = String(endNum).split('.')[0].length;
          endNumber2 = String(endNum).split('.')[1].length;
        } else {
          endNumber1 = String(endNum).length;
          endNumber2 = 0;
        }
      } else {
        endNumber1 = 1;
        endNumber2 = 0;
      }

      var len1 = startNumber1 >= endNumber1 ? startNumber1 : endNumber1;
      var len2 = startNumber2 >= endNumber2 ? startNumber2 : endNumber2;
      this.num_total_len = len1 + len2;
      this.pointNum = len2; // --------------

      if (initNum > endNum) {
        //减少
        this.sortFlag = 'reduce';
        this.to0_10 = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0];
        this.totalCount = this.calculation(initNum, endNum, '-');
        this.numberVal = String(initNum);
      } else {
        //增加
        this.sortFlag = 'add';
        this.to0_10 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
        this.totalCount = this.calculation(endNum, initNum, '-');
        this.numberVal = String(endNum);
      } //将小数位数计算后，补0


      var unit = 1;

      for (var i = 0; i < this.pointNum; i++) {
        unit *= 10;
      }

      var rel_big = this.numberVal * unit; // 去除小数点后的数，unit几个零表示有几个小数

      this.relNum = rel_big; // this.totalCount = rel_big;

      if (toFixed != 0) {
        //计算小数点后的位数，小数位
        this.pointNum = this.numberVal.split('.')[1] ? this.numberVal.split('.')[1].length : 0; //数字长度

        this.num_total_len = String(rel_big).length;
      }

      if (String(initNum).indexOf('.') > -1) {
        var n = String(initNum).split('.');
        this.initDigit1 = n[0];
        this.initDigit2 = n[1];
      } else {
        this.initDigit1 = String(initNum);
        this.initDigit2 = '0';
      }

      if (this.scrolling && !customBgImg) {
        this.$nextTick(function () {
          // 数字都是从小加到大的，所以我们循环转动最后一个数字，传入最后一个数字的DOM
          var element = _this2.$refs.numberItem[_this2.num_total_len - 1];

          _this2.runTurn(element);
        });
      } else {
        this.imgNumberScroll();
      }
    },
    runTurn: function runTurn(el) {
      var _this3 = this;

      var that = this;
      that.clearInterval();
      var m = 1;

      if (this.pointNum != 0) {
        m = 1 / Math.pow(10, this.pointNum);
      } //设置定时器


      that.timer = setInterval(function () {
        that.runStep(el);
        that.totalCount = that.calculation(that.totalCount, m, '-'); // that.totalCount--;

        if (that.totalCount <= 0) {
          that.clearInterval();

          _this3.$emit('scroll-end');
        }
      }, that.during);
    },
    runStep: function runStep(el) {
      var that = this;
      var currentTurn = el.getAttribute('turn-number');
      var turningNum = null;

      if (that.sortFlag == 'add') {
        turningNum = parseInt(currentTurn) + 1;
      } else {
        turningNum = parseInt(currentTurn) - 1 >= 0 ? parseInt(currentTurn) - 1 : 9;
      } // if(el.getAttribute('flag')) {el.removeAttribute('flag');}
      // let flag = parseInt(currentTurn) - 1;
      // el.setAttribute('flag', flag);
      // if(turningNum == 0) {
      //     el.setAttribute('flag', -1);
      // }


      el.setAttribute('turn-number', turningNum);

      if (el.style.transition == 'none 0s ease 0s' || turningNum == 1 || !el.style.transition) {
        el.style.transition = "all linear ".concat(that.during, "ms");
      }

      if (turningNum == 10 || that.sortFlag == 'reduce' && turningNum == 0) {
        var timeOut = null; // el.style.top = `-${turningNum * 100}%`;

        el.style.top = "-".concat(that.sortFlag == 'add' ? turningNum * 100 : (10 - turningNum) * 100, "%");
        el.setAttribute('turn-number', 0);
        timeOut = setTimeout(function () {
          timeOut && clearTimeout(timeOut);
          el.style.transition = 'none';
          el.style.top = 0; // 前面数字的滚动，用于递增

          if (turningNum == 10) {
            if (el.previousSibling) {
              that.runStep(el.previousSibling);
            }
          }
        }, 0.975 * that.during);
      } else {
        // el.style.top = `-${(10-turningNum)*100}%`;
        el.style.top = "-".concat(that.sortFlag == 'add' ? turningNum * 100 : (10 - turningNum) * 100, "%");
      } // 用于递减的时候


      if (el.style.top == '-100%' && that.sortFlag == 'reduce') {
        that.runStep(el.previousSibling);
      }
    },
    // 自定义图片
    imgNumberScroll: function imgNumberScroll() {
      var _this4 = this;

      var that = this;
      var m = 1;

      if (that.pointNum != 0) {
        m = Math.pow(10, that.pointNum);
      }

      this.$nextTick(function () {
        var f = that.$el.querySelector('.run-number-img');
        setTimeout(function () {
          that.relNum = that.calculation(that.relNum, m * that.speed, '+');
        }, that.during);
        f.addEventListener('webkitTransitionEnd', function () {
          _this4.$emit('scroll-end');

          setTimeout(function () {
            that.relNum = that.calculation(that.relNum, m * that.speed, '+');
          }, that.during);
        });
      });
    },
    // 不中奖设置随机数
    generateRandom: function generateRandom() {
      this.notPrize = [];

      while (this.notPrize.length < 3) {
        var rand = Math.floor(Math.random() * this.machinePrizeNum + 1);

        if (this.notPrize.indexOf(rand) == -1) {
          this.notPrize.push(rand);
        }
      }
    },
    // 抽奖
    machineLuck: function machineLuck() {
      var _this5 = this;

      this.machineTrunMore = this.machineTrunMore < 0 ? 0 : this.machineTrunMore;
      var distance = this.numHeight * this.machinePrizeNum; // 所有奖品的高度，雪碧图的高度

      if (this.prizeLevelTrun < 0) {
        this.generateRandom();
      }

      var _loop = function _loop(i) {
        setTimeout(function () {
          var turn = distance * (i + 1 + parseFloat(_this5.machineTrunMore));

          if (_this5.prizeYPrev.length != 0) {
            // this.machineTransition = 'none';
            // console.log(this.prizeYPrev[i]-(this.numHeight * this.machinePrizeNum));
            _this5.$set(_this5.prizeY, i, _this5.prizeYPrev[i]);
          }

          var local = _this5.prizeYPrev[i] ? _this5.prizeYPrev[i] : 0;
          var newLocation = turn + local + (_this5.machinePrizeNum - _this5.prizeLevelTrun + 1) * _this5.numHeight + (distance - local);

          if (_this5.prizeLevelTrun < 0) {
            newLocation += _this5.numHeight * _this5.notPrize[i];
          }

          _this5.scrollTime(i, // parseFloat((this.machinePrizeNum-(this.prizeLevelTrun-1))*this.numHeight + turn + local),
          newLocation, local);
        }, 500 * i);
      };

      for (var i = 0; i < this.machineNum; i++) {
        _loop(i);
      }
    },
    scrollTime: function scrollTime(index, total, num) {
      var _this6 = this;

      // this.machineTransition = `all linear ${this.during/this.machinePrizeNum}ms`;
      var t = setInterval(function () {
        if (num <= total) {
          num += 10;

          _this6.$set(_this6.prizeY, index, parseFloat(num));
        } else {
          clearInterval(t);
          t = null;
          _this6.finshMachine += 1;

          _this6.$set(_this6.prizeY, index, total); // 动画未完成的时候触发了判断，需要加个延时或者监听最后一个动画执行结束，保证在动画执行结束
          // this.$nextTick(() => {
          //     var f = document.getElementsByClassName('run-number-machine-img-li');
          //     f[f.length-1].addEventListener('webkitTransitionEnd', () => {
          //         setTimeout(() => {
          //             if(this.finshMachine == this.machineNum) {
          //                 this.finshMachine = 0;
          //             }
          //         },200)
          //     });
          // })


          if (_this6.finshMachine == _this6.machineNum) {
            var distance = _this6.numHeight * _this6.machinePrizeNum;
            _this6.prizeYPrev = [];
            var prevAry = JSON.parse(JSON.stringify(_this6.prizeY));
            prevAry.forEach(function (item) {
              var n = item;

              while (n > distance) {
                n -= distance;
              }

              _this6.prizeYPrev.push(n);
            });
            setTimeout(function () {
              _this6.finshMachine = 0;

              if (_this6.prizeLevelTrun < 0) {
                _this6.$emit('scroll-end', false);
              } else {
                _this6.$emit('scroll-end', true);
              }
            }, 130);
          }
        }
      }, 30);
    }
  }
});
// CONCATENATED MODULE: ./src/packages/countup/countup.vue?vue&type=script&lang=js&
 /* harmony default export */ var countup_countupvue_type_script_lang_js_ = (countupvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/countup/countup.vue





/* normalize component */

var countup_component = normalizeComponent(
  countup_countupvue_type_script_lang_js_,
  countupvue_type_template_id_17b952b6_render,
  countupvue_type_template_id_17b952b6_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var countup = (countup_component.exports);
// EXTERNAL MODULE: ./src/packages/countup/countup.scss
var countup_countup = __webpack_require__(78);

// CONCATENATED MODULE: ./src/packages/countup/index.js



countup.install = function (Vue) {
  Vue.component(countup.name, countup);
};

/* harmony default export */ var packages_countup = (countup);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/fixednav/fixednav.vue?vue&type=template&id=7446853c&
var fixednavvue_type_template_id_7446853c_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-fixednav",class:_vm.styled},[_c('div',{staticStyle:{"position":"relative","z-index":"1"}},[_c('nut-popup',{model:{value:(_vm.defaultActive),callback:function ($$v) {_vm.defaultActive=$$v},expression:"defaultActive"}})],1),_vm._v(" "),_vm._t("list",[_c('ul',{staticClass:"fixed-list"},_vm._l((_vm.navList),function(item,index){return _c('li',{key:item.id || index,on:{"click":function($event){return _vm.selected(item, $event)}}},[_c('img',{attrs:{"src":item.icon}}),_vm._v(" "),_c('span',[_vm._v(_vm._s(item.text))]),_vm._v(" "),(item.num)?_c('b',[_vm._v(_vm._s(item.num))]):_vm._e()])}),0)]),_vm._v(" "),_c('div',{staticClass:"fixed-btn",on:{"click":function($event){_vm.defaultActive = !_vm.defaultActive}}},[_vm._t("btn",[_c('img',{attrs:{"src":"https://img14.360buyimg.com/imagetools/jfs/t1/149975/30/1615/368/5ef86176Eb75bae46/5f70ae80a2d567b4.png"}}),_vm._v(" "),_c('span',[_vm._v(_vm._s(_vm.defaultActive ? _vm.activeText : _vm.unActiveText))])])],2)],2)}
var fixednavvue_type_template_id_7446853c_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/fixednav/fixednav.vue?vue&type=template&id=7446853c&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/fixednav/fixednav.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var fixednavvue_type_script_lang_js_ = ({
  name: 'nut-fixednav',
  props: {
    active: {
      type: Boolean,
      default: false
    },
    navList: {
      default: function _default() {
        return [];
      },
      type: Array
    },
    activeText: {
      default: '收起导航',
      type: String
    },
    unActiveText: {
      default: '快速导航',
      type: String
    },
    type: {
      default: 'right',
      type: String
    }
  },
  computed: {
    styled: function styled() {
      return defineProperty_default()({
        active: this.defaultActive
      }, this.defaultType, true);
    }
  },
  watch: {
    defaultActive: function defaultActive(newV, oldV) {
      this.$emit('update:active', newV);
    }
  },
  data: function data() {
    return {
      defaultActive: false,
      defaultType: ''
    };
  },
  mounted: function mounted() {
    this.defaultActive = this.active;
    this.defaultType = this.type;
  },
  methods: {
    selected: function selected(item, $event) {
      this.$emit('selected', {
        item: item,
        $event: $event
      });
    }
  }
});
// CONCATENATED MODULE: ./src/packages/fixednav/fixednav.vue?vue&type=script&lang=js&
 /* harmony default export */ var fixednav_fixednavvue_type_script_lang_js_ = (fixednavvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/fixednav/fixednav.vue





/* normalize component */

var fixednav_component = normalizeComponent(
  fixednav_fixednavvue_type_script_lang_js_,
  fixednavvue_type_template_id_7446853c_render,
  fixednavvue_type_template_id_7446853c_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var fixednav = (fixednav_component.exports);
// EXTERNAL MODULE: ./src/packages/fixednav/fixednav.scss
var fixednav_fixednav = __webpack_require__(79);

// CONCATENATED MODULE: ./src/packages/fixednav/index.js



fixednav.install = function (Vue) {
  Vue.component(fixednav.name, fixednav);
};

/* harmony default export */ var packages_fixednav = (fixednav);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/collapse/collapse.vue?vue&type=template&id=70a9a9a2&
var collapsevue_type_template_id_70a9a9a2_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-collapse",on:{"changeEvt":_vm.changeEvt}},[_vm._t("default")],2)}
var collapsevue_type_template_id_70a9a9a2_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/collapse/collapse.vue?vue&type=template&id=70a9a9a2&

// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/collapse/collapse-item.vue?vue&type=template&id=084bf89c&
var collapse_itemvue_type_template_id_084bf89c_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{class:['nut-collapse-item', { 'nut-collapse-item-left': _vm.classDirection == 'left' }, { 'nut-collapse-item-icon': this.$parent.icon }]},[_c('div',{class:['collapse-item', { 'item-expanded': _vm.openExpanded }, { 'nut-collapse-item-disabled': _vm.disabled }],on:{"click":_vm.toggleOpen}},[_c('div',{staticClass:"collapse-title"},[_c('span',{domProps:{"innerHTML":_vm._s(_vm.title)}})]),_vm._v(" "),(_vm.subTitle)?_c('span',{staticClass:"subTitle",domProps:{"innerHTML":_vm._s(_vm.subTitle)}}):_vm._e(),_vm._v(" "),(this.$parent.icon)?_c('i',{class:['collapse-icon', { 'col-expanded': _vm.openExpanded }, { 'collapse-icon-disabled': _vm.disabled }],style:(_vm.iconStyle)}):_c('i',{class:['collapse-icon', { 'col-expanded': _vm.openExpanded }, { 'collapse-icon-disabled': _vm.disabled }]})]),_vm._v(" "),_c('div',{ref:"wrapper",class:['collapse-wrapper']},[_c('div',{ref:"content",staticClass:"collapse-content"},[_vm._t("default")],2)])])}
var collapse_itemvue_type_template_id_084bf89c_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/collapse/collapse-item.vue?vue&type=template&id=084bf89c&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/collapse/collapse-item.vue?vue&type=script&lang=js&
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var collapse_itemvue_type_script_lang_js_ = ({
  name: 'nut-collapse-item',
  props: {
    title: {
      type: String,
      default: ''
    },
    subTitle: {
      type: String,
      default: ''
    },
    disabled: {
      type: Boolean,
      default: false
    },
    name: {
      type: Number | String,
      default: -1,
      required: true
    }
  },
  mounted: function mounted() {
    var _this = this;

    this.$nextTick(function () {
      var active = _this.$parent && _this.$parent.value;

      if (typeof active == 'number' || typeof active == 'string') {
        if (_this.name == active) {
          _this.defaultOpen();
        }
      }

      if (active instanceof Array) {
        var f = active.filter(function (item) {
          return item == _this.name;
        });

        if (f.length > 0) {
          _this.defaultOpen();
        }
      }
    });
    this.classDirection = this.$parent.expandIconPosition;

    if (this.$parent.icon) {
      this.$set(this.iconStyle, 'background-image', 'url(' + this.$parent.icon + ')');
    }
  },
  data: function data() {
    return {
      openExpanded: false,
      classDirection: 'right',
      iconStyle: {
        'background-image': 'url(https://img10.360buyimg.com/imagetools/jfs/t1/111306/10/17422/341/5f58aa0eEe9218dd6/28d76a42db334e31.png)',
        'background-repeat': 'no-repeat',
        'background-size': '100% 100%',
        transform: 'rotate(0deg)'
      }
    };
  },
  methods: {
    defaultOpen: function defaultOpen() {
      this.$parent.accordion ? this.$parent.accordionFun(this.name) : this.open();

      if (this.$parent.icon) {
        this.$set(this.iconStyle, 'transform', 'rotate(' + this.$parent.rotate + 'deg)');
      }
    },
    toggleOpen: function toggleOpen() {
      this.$parent.changeEvt(this.name);

      if (this.$parent.accordion) {
        this.$parent.changeVal(this.name);

        if (this.$parent.value == this.name) {
          this.$parent.accordionFun(this.name);
        }

        this.animation();
      } else {
        this.$parent.changeValAry(this.name);
        this.open();
      }
    },
    open: function open() {
      this.openExpanded = !this.openExpanded;
      this.animation();
    },
    // 手风琴模式
    animation: function animation() {
      var _this2 = this;

      this.$nextTick(function () {
        var _this2$$refs = _this2.$refs,
            content = _this2$$refs.content,
            wrapper = _this2$$refs.wrapper;

        if (!content || !wrapper) {
          return;
        }

        var offsetHeight = content.offsetHeight;

        if (offsetHeight) {
          var contentHeight = "".concat(offsetHeight, "px");
          wrapper.style.willChange = 'height';
          wrapper.style.height = !_this2.openExpanded ? 0 : contentHeight;

          if (_this2.$parent.icon && !_this2.openExpanded) {
            _this2.$set(_this2.iconStyle, 'transform', 'rotate(0deg)');
          } else {
            _this2.$set(_this2.iconStyle, 'transform', 'rotate(' + _this2.$parent.rotate + 'deg)');
          }
        }

        if (!_this2.openExpanded) {
          _this2.onTransitionEnd();
        }
      });
    },
    // 更改子组件展示
    changeOpen: function changeOpen(bol) {
      this.openExpanded = bol;
    },
    // 清除 willChange 减少性能浪费
    onTransitionEnd: function onTransitionEnd() {
      this.$refs.wrapper.style.willChange = 'auto';
    }
  }
});
// CONCATENATED MODULE: ./src/packages/collapse/collapse-item.vue?vue&type=script&lang=js&
 /* harmony default export */ var collapse_collapse_itemvue_type_script_lang_js_ = (collapse_itemvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/collapse/collapse-item.vue





/* normalize component */

var collapse_item_component = normalizeComponent(
  collapse_collapse_itemvue_type_script_lang_js_,
  collapse_itemvue_type_template_id_084bf89c_render,
  collapse_itemvue_type_template_id_084bf89c_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var collapse_item = (collapse_item_component.exports);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/collapse/collapse.vue?vue&type=script&lang=js&
//
//
//
//
//

/* harmony default export */ var collapsevue_type_script_lang_js_ = ({
  name: 'nut-collapse',
  components: {
    nutCollapseItem: collapse_item
  },
  model: {
    prop: 'value',
    event: 'change-active'
  },
  props: {
    value: {
      type: String | Number
    },
    accordion: {
      type: Boolean
    },
    expandIconPosition: {
      type: String,
      default: 'right'
    },
    icon: {
      type: String,
      default: ''
    },
    rotate: {
      type: Number | String,
      default: 180
    }
  },
  watch: {
    value: function value(newVal, oldVal) {
      this.accordionFun(newVal);
    }
  },
  data: function data() {
    return {};
  },
  methods: {
    changeEvt: function changeEvt(name) {
      this.$parent.change(name);
    },
    changeValAry: function changeValAry(name) {
      var index = -1;
      this.value.forEach(function (item, idx) {
        if (String(item) == String(name)) {
          index = idx;
        }
      });
      var v = JSON.parse(JSON.stringify(this.value));
      index > -1 ? v.splice(index, 1) : v.push(name);
      this.$emit('change-active', v);
    },
    changeVal: function changeVal(val) {
      this.$emit('change-active', val);
    },
    // 手风琴模式将所有的item收起，然后对应的展开（默认）
    // 对于展开的再次点击的将其设置成收起，动画效果在item组件中执行
    accordionFun: function accordionFun(val) {
      if (val instanceof Array) {} else {
        this.$children.forEach(function (item) {
          if (item.name == val && item.openExpanded) {
            item.changeOpen(false);
          } else {
            item.name == val ? item.changeOpen(true) : item.changeOpen(false);
            item.animation();
          }
        });
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/collapse/collapse.vue?vue&type=script&lang=js&
 /* harmony default export */ var collapse_collapsevue_type_script_lang_js_ = (collapsevue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/collapse/collapse.vue





/* normalize component */

var collapse_component = normalizeComponent(
  collapse_collapsevue_type_script_lang_js_,
  collapsevue_type_template_id_70a9a9a2_render,
  collapsevue_type_template_id_70a9a9a2_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var collapse = (collapse_component.exports);
// EXTERNAL MODULE: ./src/packages/collapse/collapse.scss
var collapse_collapse = __webpack_require__(80);

// CONCATENATED MODULE: ./src/packages/collapse/index.js



collapse.install = function (Vue) {
  Vue.component(collapse.name, collapse);
};

/* harmony default export */ var packages_collapse = (collapse);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/luckycard/luckycard.vue?vue&type=template&id=55a8e6cd&
var luckycardvue_type_template_id_55a8e6cd_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('div',{staticClass:"nut-luckycard",style:({height:_vm.height+'px',width:_vm.width+'px'})},[_c('div',{staticClass:"nut-content",style:({backgroundColor:_vm.backgroundColor,fontSize:_vm.fontSize+'px'}),domProps:{"innerHTML":_vm._s(_vm.content)}})])}
var luckycardvue_type_template_id_55a8e6cd_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/luckycard/luckycard.vue?vue&type=template&id=55a8e6cd&

// CONCATENATED MODULE: ./src/packages/luckycard/luckycard.js
/*
 * lucky-card.js - Scratch CARDS based on HTML5 Canvas
 *
 * Copyright (c) 2015 Frans Lee dmon@foxmail.com
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 * Version:  1.0.3
 */

/**
 * Instantiate parameters
 *
 * @constructor
 */



function LuckyCard(settings, callback) {
  this.cover = null;
  this.ctx = null;
  this.scratchDiv = settings.scratchDiv;
  this.cardDiv = null;
  this.cHeight = 0;
  this.cWidth = 0;
  this.supportTouch = false;
  this.events = [];
  this.startEventHandler = null;
  this.moveEventHandler = null;
  this.endEventHandler = null;
  this.opt = {
    coverColor: '#C5C5C5',
    coverImg: '',
    ratio: .8,
    callback: null
  };
  this.init(settings, callback);
}

;

function _calcArea(ctx, callback, ratio) {
  var pixels = ctx.getImageData(0, 0, this.cWidth, this.cHeight);
  var transPixels = [];

  _forEach(pixels.data, function (item, i) {
    var pixel = pixels.data[i + 3];

    if (pixel === 0) {
      transPixels.push(pixel);
    }
  });

  if (transPixels.length / pixels.data.length > ratio) {
    callback && typeof callback === 'function' && callback();
  }
}

function _forEach(items, callback) {
  return Array.prototype.forEach.call(items, function (item, idx) {
    callback(item, idx);
  });
}

function _isCanvasSupported() {
  var elem = document.createElement('canvas');
  return !!(elem.getContext && elem.getContext('2d'));
}
/**
 * touchstart/mousedown event handler
 */


function _startEventHandler(event) {
  event.preventDefault();
  this.moveEventHandler = _moveEventHandler.bind(this);
  this.cover.addEventListener(this.events[1], this.moveEventHandler, false);
  this.endEventHandler = _endEventHandler.bind(this);
  document.addEventListener(this.events[2], this.endEventHandler, false);
}

;
/**
 * touchmove/mousemove event handler
 */

function _moveEventHandler(event) {
  event.preventDefault();
  var evt = this.supportTouch ? event.touches[0] : event;
  var coverPos = this.cover.getBoundingClientRect();
  var pageScrollTop = document.documentElement.scrollTop || document.body.scrollTop;
  var pageScrollLeft = document.documentElement.scrollLeft || document.body.scrollLeft;
  var mouseX = evt.pageX - coverPos.left - pageScrollLeft;
  var mouseY = evt.pageY - coverPos.top - pageScrollTop;
  this.ctx.beginPath();
  this.ctx.fillStyle = '#FFFFFF';
  this.ctx.globalCompositeOperation = "destination-out";
  this.ctx.arc(mouseX, mouseY, 10, 0, 2 * Math.PI);
  this.ctx.fill();
}

;
/**
 * touchend/mouseup event handler
 */

function _endEventHandler(event) {
  event.preventDefault();
  if (this.opt.callback && typeof this.opt.callback === 'function') _calcArea.call(this, this.ctx, this.opt.callback, this.opt.ratio);
  this.cover.removeEventListener(this.events[1], this.moveEventHandler, false);
  document.removeEventListener(this.events[2], this.endEventHandler, false);
}

;
/**
 * Create Canvas element
 */

LuckyCard.prototype.createCanvas = function () {
  this.cover = document.createElement('canvas');
  this.cover.className = 'nut-cover';
  this.cover.height = this.cHeight;
  this.cover.width = this.cWidth;
  this.ctx = this.cover.getContext('2d');

  if (this.opt.coverImg) {
    var _this = this;

    var coverImg = new Image();
    coverImg.src = this.opt.coverImg;

    coverImg.onload = function () {
      _this.ctx.drawImage(coverImg, 0, 0, _this.cover.width, _this.cover.height);
    };
  } else {
    this.ctx.fillStyle = this.opt.coverColor;
    this.ctx.fillRect(0, 0, this.cover.width, this.cover.height);
  }

  this.scratchDiv.appendChild(this.cover);
  this.cardDiv.style.opacity = 1;
};
/**
 * To detect whether support touch events
 */


LuckyCard.prototype.eventDetect = function () {
  if ('ontouchstart' in window) this.supportTouch = true;
  this.events = this.supportTouch ? ['touchstart', 'touchmove', 'touchend'] : ['mousedown', 'mousemove', 'mouseup'];
  this.addEvent();
};
/**
 * Add touchstart/mousedown event listener
 */


LuckyCard.prototype.addEvent = function () {
  this.startEventHandler = _startEventHandler.bind(this);
  this.cover.addEventListener(this.events[0], this.startEventHandler, false);
};
/**
 * Clear pixels of canvas
 */


LuckyCard.prototype.clearCover = function () {
  this.ctx.clearRect(0, 0, this.cover.width, this.cover.height);
  this.cover.removeEventListener(this.events[0], this.startEventHandler);
  this.cover.removeEventListener(this.events[1], this.moveEventHandler);
  this.cover.removeEventListener(this.events[2], this.endEventHandler);
};
/**
 * LuckyCard initializer
 *
 * @param {Object} settings  Settings for LuckyCard
 * @param {function} callback  callback function
 */


LuckyCard.prototype.init = function (settings, callback) {
  if (!_isCanvasSupported()) {
    alert('对不起，当前浏览器不支持Canvas，无法使用本控件！');
    return;
  }

  var _this = this;

  _forEach(arguments, function (item) {
    if (typeof_default()(item) === "object") {
      for (var k in item) {
        if (k === 'callback' && typeof item[k] === 'function') {
          _this.opt.callback = item[k].bind(_this);
        } else {
          k in _this.opt && (_this.opt[k] = item[k]);
        }
      }
    } else if (typeof item === "function") {
      _this.opt.callback = item.bind(_this);
    }
  });
  /* this.scratchDiv = document.getElementById('scratch');*/


  if (!this.scratchDiv) return;
  this.cardDiv = this.scratchDiv.querySelector('.nut-content');
  if (!this.cardDiv) return;
  this.cHeight = this.cardDiv.clientHeight;
  this.cWidth = this.cardDiv.clientWidth;
  this.cardDiv.style.opacity = 0;
  this.createCanvas();
  this.eventDetect();
};
/**
 * To generate an instance of object
 *
 * @param {Object} settings  Settings for LuckyCard
 * @param {function} callback  callback function
 */


LuckyCard.case = function (settings, callback) {
  return new LuckyCard(settings, callback);
};

/* harmony default export */ var luckycard = (LuckyCard.case);
// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/luckycard/luckycard.vue?vue&type=script&lang=js&
//
//
//
//
//
//

/* harmony default export */ var luckycardvue_type_script_lang_js_ = ({
  name: 'nut-luckycard',
  props: {
    content: {
      type: String,
      default: ''
    },
    height: {
      type: [String, Number],
      default: 50
    },
    width: {
      type: [String, Number],
      default: 300
    },
    coverColor: {
      type: String,
      default: '#C5C5C5'
    },
    coverImg: {
      type: String,
      default: ''
    },
    fontSize: {
      type: [String, Number],
      default: 20
    },
    backgroundColor: {
      type: String,
      default: '#FFFFFF'
    },
    ratio: {
      type: [String, Number],
      default: 0.5
    }
  },
  data: function data() {
    return {};
  },
  methods: {},
  mounted: function mounted() {
    var _this = this;

    this.$nextTick(function () {
      var _vm = _this;
      luckycard({
        scratchDiv: _this.$el,
        coverColor: _this.coverColor,
        coverImg: _this.coverImg,
        ratio: Number(_this.ratio),
        callback: function callback() {
          //console.log(this);
          //this.clearCover();
          _vm.$emit('open', this);
        }
      });
    });
  }
});
// CONCATENATED MODULE: ./src/packages/luckycard/luckycard.vue?vue&type=script&lang=js&
 /* harmony default export */ var luckycard_luckycardvue_type_script_lang_js_ = (luckycardvue_type_script_lang_js_); 
// EXTERNAL MODULE: ./src/packages/luckycard/luckycard.vue?vue&type=style&index=0&lang=scss&
var luckycardvue_type_style_index_0_lang_scss_ = __webpack_require__(121);

// CONCATENATED MODULE: ./src/packages/luckycard/luckycard.vue






/* normalize component */

var luckycard_component = normalizeComponent(
  luckycard_luckycardvue_type_script_lang_js_,
  luckycardvue_type_template_id_55a8e6cd_render,
  luckycardvue_type_template_id_55a8e6cd_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var luckycard_luckycard = (luckycard_component.exports);
// EXTERNAL MODULE: ./src/packages/luckycard/luckycard.scss
var packages_luckycard_luckycard = __webpack_require__(81);

// CONCATENATED MODULE: ./src/packages/luckycard/index.js



luckycard_luckycard.install = function (Vue) {
  Vue.component(luckycard_luckycard.name, luckycard_luckycard);
};

/* harmony default export */ var packages_luckycard = (luckycard_luckycard);
// CONCATENATED MODULE: ./node_modules/vue-loader/lib/loaders/templateLoader.js??vue-loader-options!./node_modules/cache-loader/dist/cjs.js!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/numberkeyboard/numberkeyboard.vue?vue&type=template&id=396603ef&
var numberkeyboardvue_type_template_id_396603ef_render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;return _c('transition',{attrs:{"name":"nut-board-slide-up"},on:{"after-enter":_vm.afterEnter,"after-leave":_vm.afterLeave}},[_c('div',{directives:[{name:"show",rawName:"v-show",value:(_vm.visible),expression:"visible"}],staticClass:"nut-numberkeyboard"},[(_vm.title)?_c('div',{staticClass:"number-board-header"},[_c('h3',{staticClass:"tit"},[_vm._v(_vm._s(_vm.title))]),_vm._v(" "),_c('span',{staticClass:"keyboard-close",on:{"click":function () { return _vm.closeBoard(); }}},[_vm._v("完成")])]):_vm._e(),_vm._v(" "),_c('div',{staticClass:"number-board-body"},[_c('div',{staticClass:"number-board"},_vm._l((_vm.keysList),function(item){return _c('div',{key:'key' + item.id,class:[
            'key-board-wrapper',
            { 'key-board-wrapper-large': item.id == 0 && _vm.type == 'rightColumn' && Array.isArray(_vm.customKey) && _vm.customKey.length == 1 }
          ]},[_c('div',{class:['key', { active: item.id == _vm.clickKeyIndex }, { lock: item.type == 'lock' }, { delete: item.type == 'delete' }],on:{"touchstart":function (event) { return _vm.onTouchstart(item, event); },"touchmove":function (event) { return _vm.onTouchMove(item, event); },"touchend":_vm.onTouchEnd}},[(item.type == 'number' || item.type == 'custom')?[_vm._v(_vm._s(item.id))]:_vm._e(),_vm._v(" "),(item.type == 'lock')?_c('img',{attrs:{"src":"https://img11.360buyimg.com/imagetools/jfs/t1/146371/38/8485/738/5f606425Eca239740/14f4b4f5f20d8a68.png"}}):_vm._e(),_vm._v(" "),(item.type == 'delete')?_c('img',{attrs:{"src":"https://img11.360buyimg.com/imagetools/jfs/t1/129395/8/12735/2030/5f61ac37E70cab338/fb477dc11f46056c.png"}}):_vm._e()],2)])}),0),_vm._v(" "),(_vm.type == 'rightColumn')?_c('div',{staticClass:"number-board-sidebar"},[_c('div',{staticClass:"key-board-wrapper"},[_c('div',{class:['key', { active: _vm.clickKeyIndex == 'delete' }],on:{"touchstart":function (event) { return _vm.onTouchstart({ id: 'delete', type: 'delete' }, event); },"touchmove":function (event) { return _vm.onTouchMove({ id: 'delete', type: 'delete' }, event); },"touchend":_vm.onTouchEnd}},[_c('img',{attrs:{"src":"https://img11.360buyimg.com/imagetools/jfs/t1/129395/8/12735/2030/5f61ac37E70cab338/fb477dc11f46056c.png"}})])]),_vm._v(" "),_c('div',{staticClass:"key-board-wrapper",on:{"click":function () { return _vm.closeBoard(); }}},[_c('div',{class:['key', 'finish', { activeFinsh: _vm.clickKeyIndex == 'finish' }]},[_vm._v("\n            完成\n          ")])])]):_vm._e()])])])}
var numberkeyboardvue_type_template_id_396603ef_staticRenderFns = []


// CONCATENATED MODULE: ./src/packages/numberkeyboard/numberkeyboard.vue?vue&type=template&id=396603ef&

// CONCATENATED MODULE: ./node_modules/cache-loader/dist/cjs.js!./node_modules/babel-loader/lib!./node_modules/vue-loader/lib??vue-loader-options!./src/packages/numberkeyboard/numberkeyboard.vue?vue&type=script&lang=js&

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/* harmony default export */ var numberkeyboardvue_type_script_lang_js_ = ({
  name: 'nut-numberkeyboard',
  props: {
    title: {
      type: String,
      default: ''
    },
    visible: {
      type: Boolean,
      default: false
    },
    type: {
      type: String,
      default: 'default'
    },
    customKey: {
      type: Array,
      default: function _default() {
        return [];
      }
    },
    value: {
      type: String,
      default: ''
    },
    maxlength: {
      type: [Number, String],
      default: 6
    }
  },
  model: {
    prop: 'value',
    event: 'update:value'
  },
  computed: {
    keysList: function keysList() {
      if (this.type == 'rightColumn' || this.title != '') {
        return this.genCustomKeys();
      }

      return this.defaultKey();
    }
  },
  data: function data() {
    return {
      once: 0,
      keys: [],
      clickKeyIndex: undefined
    };
  },
  beforeDestroy: function beforeDestroy() {
    document.getElementsByTagName('body')[0].removeEventListener('click', function () {});
  },
  mounted: function mounted() {
    var that = this;
    this.$nextTick(function () {
      var targetArea = that.$el;
      document.getElementsByTagName('body')[0].addEventListener('click', function (event) {
        var e = event || window.event;
        var elem = e.target;

        if (targetArea.contains(elem)) {// console.log("在区域内");
        } else {
          // console.log("在区域外");
          if (that.once == 0 && that.visible) {
            that.once += 1;
            return false;
          }

          that.closeBoard();
        }
      });
    });
  },
  methods: {
    getBasicKeys: function getBasicKeys() {
      var keys = [];

      for (var i = 1; i <= 9; i++) {
        keys.push({
          id: i,
          type: 'number'
        });
      }

      return keys;
    },
    defaultKey: function defaultKey() {
      return [].concat(toConsumableArray_default()(this.getBasicKeys()), [{
        id: 'lock',
        type: 'lock'
      }, {
        id: 0,
        type: 'number'
      }, {
        id: 'delete',
        type: 'delete'
      }]);
    },
    genCustomKeys: function genCustomKeys() {
      var keys = this.getBasicKeys();
      var customKey = this.customKey;
      var customKeys = Array.isArray(customKey) ? customKey : [customKey];

      if (customKeys.length > 2) {
        customKeys = [customKeys[0], customKeys[1]];
      }

      if (customKeys.length === 1) {
        if (this.title) {
          keys.push({
            id: customKeys[0],
            type: 'custom'
          }, {
            id: 0,
            type: 'number'
          }, {
            id: 'delete',
            type: 'delete'
          });
        } else {
          keys.push({
            id: 0,
            type: 'number'
          }, {
            id: customKeys[0],
            type: 'custom'
          });
        }
      } else if (customKeys.length === 2) {
        keys.push({
          id: customKeys[0],
          type: 'custom'
        }, {
          id: 0,
          type: 'number'
        }, {
          id: customKeys[1],
          type: 'custom'
        });

        if (this.title) {
          keys.push({
            id: 'delete',
            type: 'delete'
          });
        }
      }

      return keys;
    },
    afterEnter: function afterEnter() {
      this.$emit('enter');
    },
    afterLeave: function afterLeave() {
      this.$emit('leave');
    },
    onTouchstart: function onTouchstart(item, event) {
      event.stopPropagation();
      this.clickKeyIndex = item.id;

      if (item.type == 'number' || item.type == 'custom') {
        this.$emit('input', item.id);

        if (this.value.length < this.maxlength) {
          this.$emit('update:value', this.value + item.id);
        }
      }

      if (item.type == 'lock') {
        this.closeBoard();
      }

      if (item.type == 'delete') {
        this.$emit('delete');
        this.$emit('update:value', this.value.slice(0, this.value.length - 1));
      }
    },
    onTouchMove: function onTouchMove(id, event) {
      event.stopPropagation(); // this.clickKeyIndex = id;
    },
    onTouchEnd: function onTouchEnd() {
      this.clickKeyIndex = undefined;
    },
    closeBoard: function closeBoard() {
      if (this.once > 0) {
        this.once = 0;
        this.$emit('close');
      }
    }
  }
});
// CONCATENATED MODULE: ./src/packages/numberkeyboard/numberkeyboard.vue?vue&type=script&lang=js&
 /* harmony default export */ var numberkeyboard_numberkeyboardvue_type_script_lang_js_ = (numberkeyboardvue_type_script_lang_js_); 
// CONCATENATED MODULE: ./src/packages/numberkeyboard/numberkeyboard.vue





/* normalize component */

var numberkeyboard_component = normalizeComponent(
  numberkeyboard_numberkeyboardvue_type_script_lang_js_,
  numberkeyboardvue_type_template_id_396603ef_render,
  numberkeyboardvue_type_template_id_396603ef_staticRenderFns,
  false,
  null,
  null,
  null
  
)

/* harmony default export */ var numberkeyboard = (numberkeyboard_component.exports);
// EXTERNAL MODULE: ./src/packages/numberkeyboard/numberkeyboard.scss
var numberkeyboard_numberkeyboard = __webpack_require__(82);

// CONCATENATED MODULE: ./src/packages/numberkeyboard/index.js



numberkeyboard.install = function (Vue) {
  Vue.component(numberkeyboard.name, numberkeyboard);
};

/* harmony default export */ var packages_numberkeyboard = (numberkeyboard);
// CONCATENATED MODULE: ./src/nutui.js


function nutui_ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function nutui_objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { nutui_ownKeys(Object(source), true).forEach(function (key) { defineProperty_default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { nutui_ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }


























































































































 // import VueQr from "./packages/qart/index.js";
// import "./packages/qart/qart.scss";








 // import Gesture from './packages/gesture/index.js';
// import './packages/gesture/gesture.scss';







var nutui_packages = {
  Cell: packages_cell,
  Dialog: packages_dialog,
  Icon: packages_icon,
  Toast: packages_toast,
  ActionSheet: packages_actionsheet,
  Tab: packages_tab,
  TabPanel: packages_tabpanel,
  TabBar: packages_tabbar,
  Calendar: packages_calendar,
  DatePicker: packages_datepicker,
  NavBar: packages_navbar,
  NoticeBar: packages_noticebar,
  Switch: packages_switch,
  Slider: packages_slider,
  Range: packages_range,
  Picker: packages_picker,
  Progress: packages_progress,
  Price: packages_price,
  Flex: packages_flex,
  Col: packages_col,
  Row: packages_row,
  Steps: packages_steps,
  Button: packages_button,
  Badge: packages_badge,
  Rate: packages_rate,
  Swiper: packages_swiper,
  Menu: packages_menu,
  Stepper: packages_stepper,
  ButtonGroup: packages_buttongroup,
  SearchBar: packages_searchbar,
  ImagePicker: packages_imagepicker,
  Radio: packages_radio,
  RadioGroup: packages_radiogroup,
  CheckBox: packages_checkbox,
  CheckBoxGroup: packages_checkboxgroup,
  ShortPassword: packages_shortpassword,
  Skeleton: packages_skeleton,
  Scroller: packages_scroller,
  BackTop: packages_backtop,
  CountDown: packages_countdown,
  InfiniteLoading: packages_infiniteloading,
  Uploader: packages_uploader,
  TextInput: packages_textinput,
  TextBox: packages_textbox,
  Avatar: packages_avatar,
  Elevator: packages_elevator,
  Popup: packages_popup,
  LeftSlip: packages_leftslip,
  TabSelect: packages_tabselect,
  LuckDraw: packages_luckdraw,
  Video: packages_video,
  Signature: packages_signature,
  CircleProgress: packages_circleprogress,
  TimeLine: packages_timeline,
  TimeLineItem: packages_timelineitem,
  SideNavBar: packages_sidenavbar,
  SubSideNavBar: packages_subsidenavbar,
  SideNavBarItem: packages_sidenavbaritem,
  Drag: packages_drag,
  Address: packages_address,
  Notify: packages_notify,
  CountUp: packages_countup,
  FixedNav: packages_fixednav,
  // Gesture: Gesture
  Collapse: packages_collapse,
  Luckycard: packages_luckycard,
  NumberKeyboard: packages_numberkeyboard
};
var components = {};
var methods = {};
var filters = {};
var directives = {};
src_config["a" /* packages */].map(function (item) {
  var pkg = nutui_packages[item.name];
  if (!pkg) return;

  if (item.type == 'component') {
    if (pkg.name) {
      components[pkg.name] = pkg;
    } else {
      for (var n in pkg) {
        components[n] = pkg[n];
      }
    }
  } else if (item.type == 'method') {
    methods[item.name] = pkg;
  } else if (item.type == 'filter') {
    filters[item.name] = pkg;
  } else if (item.type == 'directive') {
    directives[item.name] = pkg;
  }
});

var nutui_install = function install(Vue) {
  var opts = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : {};
  if (install.installed) return;

  if (opts.locale) {
    Vue.config.lang = opts.locale;
  }

  if (opts.lang) locale(Vue.config.lang, opts.lang);

  for (var cptName in methods) {
    if (Array.isArray(methods[cptName])) {
      Vue.prototype['$' + cptName.toLowerCase()] = methods[cptName][0];
      Vue.component(methods[cptName][1].name, methods[cptName][1]);
    } else {
      Vue.prototype['$' + cptName.toLowerCase()] = methods[cptName];
    }
  }

  for (var _cptName in components) {
    if (components[_cptName] && components[_cptName].name) {
      Vue.component(components[_cptName].name, components[_cptName]);
    }
  }

  for (var _cptName2 in filters) {
    if (filters[_cptName2] && filters[_cptName2].name) {
      Vue.filter(_cptName2, filters[_cptName2]);
    }
  }

  for (var _cptName3 in directives) {
    if (directives[_cptName3] && directives[_cptName3].name) {
      Vue.directive(directives[_cptName3].name, directives[_cptName3]);
    }
  }

  Vue.use(packages_lazyload, {
    lazyComponent: true,
    loading: '//img12.360buyimg.com/imagetools/jfs/t1/73967/28/14561/916/5dc142e4E0666555b/bf33454553c6035e.png'
  });
};

if (typeof window !== 'undefined' && window.Vue) {
  nutui_install(window.Vue);
}

/* harmony default export */ var nutui = __webpack_exports__["default"] = (nutui_objectSpread(nutui_objectSpread(nutui_objectSpread(nutui_objectSpread({
  version: package_0["a" /* version */],
  locale: locale,
  install: nutui_install,
  Lazyload: packages_lazyload
}, components), filters), directives), methods));

/***/ })
/******/ ]);
});
//# sourceMappingURL=nutui.js.map