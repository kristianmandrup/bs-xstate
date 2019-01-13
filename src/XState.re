module Service = {
  type t('a) = {
    onTransition: 'a => unit,
    start: unit => unit,
    send: string => unit,
  };
};
module Machine = {
  [@bs.module "xstate/lib/interpreter"]
  external interpret: 'a => Service.t('a) = "";
  type t('a) = {transition: ('a, string) => t('a)};
};
/* link to exported of machine.js */
[@bs.module "xstate"] external machine: 'a => Machine.t('a) = "";