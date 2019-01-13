module Machine = {
  type t('a) = {transition: ('a, string) => t('a)};
};
module Service = {
  type t('a) = {
    onTransition: 'a => unit,
    start: unit => unit,
    send: string => unit,
  };
};
/* link to exported of machine.js */
[@bs.module "xstate"] external machine: 'a => Machine.t('a) = "";
[@bs.module "xstate/lib/interpreter"]
external interpret: Machine.t('a) => Service.t('a) = "";