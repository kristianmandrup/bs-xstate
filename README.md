# bs-xstate

Bucklescript bindings for [xstate](https://github.com/davidkpiano/xstate).

State machines and statecharts for the modern web.

## Use

### Install

`npm i bs-xstate`

Add `bs-xstate` in `dependencies` of `bsconfig.json`

### Usage

```js
// Stateless machine definition
// machine.transition(...) is a pure function used by the interpreter.
let toggleMachine = XState.machine({
  initial: "inactive",
  states: {
    inactive: { on: { TOGGLE: "active" } },
    active: { on: { TOGGLE: "inactive" } }
  }
});

// Machine instance with internal state
let toggleService = XState.interpret(toggleMachine)
  .onTransition(state => console.log(state.value))
  .start();
// => 'inactive'

toggleService.send("TOGGLE");
// => 'active'

toggleService.send("TOGGLE");
// => 'inactive'
```

## Resources

- [xstate plantuml](https://github.com/lucmartens/xstate-plantuml) Visualize a xstate or react-automata statechart as a plantuml state diagram.

## Build

```
npm run build
```

## Watch

```
npm run watch
```

## Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
