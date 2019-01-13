const { Machine } = require("xstate");
const { interpret } = require("xstate/lib/interpreter");
module.export = {
  machine: Machine,
  interpret
};
