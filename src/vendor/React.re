type keyed;
type unkeyed;
type static;

type element('a);

[@bs.val] external null: element(keyed) = "null";

external string: string => element(keyed) = "%identity";

external array: array(element(keyed)) => element(unkeyed) = "%identity";

external staticify: element('a) => element(static) = "%identity";

external arrayJSXONLY: array(element(static)) => element(unkeyed) = "%identity";

type componentLike('props, 'return) = 'props => 'return;

type component('props) = componentLike('props, element(unkeyed));

[@bs.module "react"]
external jsxKeyed: (component('props), 'props, string) => element(keyed) = "jsx";

[@bs.module "react"]
external jsxsKeyed: (component('props), 'props, string) => element(keyed) =
  "jsxs";

[@bs.module "react"]
external jsx: (component('props), 'props) => element(unkeyed) = "jsx";

[@bs.module "react"]
external jsxs: (component('props), 'props) => element(unkeyed) =
  "jsxs";

module Ref = {
  type t('value);

  [@bs.get] external current: t('value) => 'value = "current";
  [@bs.set] external setCurrent: (t('value), 'value) => unit = "current";
};

[@bs.module "react"]
external createRef: unit => Ref.t(Js.nullable('a)) = "createRef";

module Children = {
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external map: (element('a), element('b) => element('b)) => element('a) = "map";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external forEach: (element('any), element('any) => unit) => unit = "forEach";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external count: element('any) => int = "count";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external only: element('any) => element('any) = "only";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external toArray: element('any) => array(element('any)) = "toArray";
};

module Context = {
  type t('props);

  [@bs.get]
  external provider:
    t('props) =>
    component({
      .
      "value": 'props,
      "children": element('any),
    }) =
    "Provider";
};

[@bs.module "react"]
external createContext: 'a => Context.t('a) = "createContext";

[@bs.module "react"]
external forwardRef:
  ([@bs.uncurry] (('props, Js.Nullable.t(Ref.t('a))) => element('any))) =>
  component('props) =
  "forwardRef";

[@bs.module "react"]
external memo: component('props) => component('props) = "memo";

[@bs.module "react"]
external memoCustomCompareProps:
  (component('props), [@bs.uncurry] (('props, 'props) => bool)) =>
  component('props) =
  "memo";

module Fragment = {
  [@bs.obj]
  external makeProps:
    (~children: element('any), unit) => {. "children": element('any)} =
    "";
  [@bs.module "react"]
  external make: component({. "children": element('any)}) = "Fragment";
};

module Suspense = {
  [@bs.obj]
  external makeProps:
    (
      ~children: element('a)=?,
      ~fallback: element('b)=?,
      ~maxDuration: int=?,
      unit
    ) =>
    {
      .
      "children": option(element('a)),
      "fallback": option(element('b)),
      "maxDuration": option(int),
    } =
    "";
  [@bs.module "react"]
  external make:
    component({
      .
      "children": option(element('a)),
      "fallback": option(element('b)),
      "maxDuration": option(int),
    }) =
    "Suspense";
};

/* HOOKS */

/*
 * Yeah, we know this api isn't great. tl;dr: useReducer instead.
 * It's because useState can take functions or non-function values and treats
 * them differently. Lazy initializer + callback which returns state is the
 * only way to safely have any type of state and be able to update it correctly.
 */
[@bs.module "react"]
external useState:
  ([@bs.uncurry] (unit => 'state)) => ('state, ('state => 'state) => unit) =
  "useState";

[@bs.module "react"]
external useReducer:
  ([@bs.uncurry] (('state, 'action) => 'state), 'state) =>
  ('state, 'action => unit) =
  "useReducer";

[@bs.module "react"]
external useReducerWithMapState:
  (
    [@bs.uncurry] (('state, 'action) => 'state),
    'initialState,
    'initialState => 'state
  ) =>
  ('state, 'action => unit) =
  "useReducer";

[@bs.module "react"]
external useEffect: ([@bs.uncurry] (unit => option(unit => unit))) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect0:
  ([@bs.uncurry] (unit => option(unit => unit)), [@bs.as {json|[]|json}] _) =>
  unit =
  "useEffect";
[@bs.module "react"]
external useEffect1:
  ([@bs.uncurry] (unit => option(unit => unit)), array('a)) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect2:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b)) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect3:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c)) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect4:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd)) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect5:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd, 'e)) =>
  unit =
  "useEffect";
[@bs.module "react"]
external useEffect6:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd, 'e, 'f)) =>
  unit =
  "useEffect";
[@bs.module "react"]
external useEffect7:
  (
    [@bs.uncurry] (unit => option(unit => unit)),
    ('a, 'b, 'c, 'd, 'e, 'f, 'g)
  ) =>
  unit =
  "useEffect";

[@bs.module "react"]
external useLayoutEffect:
  ([@bs.uncurry] (unit => option(unit => unit))) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect0:
  ([@bs.uncurry] (unit => option(unit => unit)), [@bs.as {json|[]|json}] _) =>
  unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect1:
  ([@bs.uncurry] (unit => option(unit => unit)), array('a)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect2:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect3:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect4:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect5:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd, 'e)) =>
  unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect6:
  ([@bs.uncurry] (unit => option(unit => unit)), ('a, 'b, 'c, 'd, 'e, 'f)) =>
  unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect7:
  (
    [@bs.uncurry] (unit => option(unit => unit)),
    ('a, 'b, 'c, 'd, 'e, 'f, 'g)
  ) =>
  unit =
  "useLayoutEffect";

[@bs.module "react"]
external useMemo: ([@bs.uncurry] (unit => 'any)) => 'any = "useMemo";
[@bs.module "react"]
external useMemo0:
  ([@bs.uncurry] (unit => 'any), [@bs.as {json|[]|json}] _) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo1: ([@bs.uncurry] (unit => 'any), array('a)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo2: ([@bs.uncurry] (unit => 'any), ('a, 'b)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo3: ([@bs.uncurry] (unit => 'any), ('a, 'b, 'c)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo4: ([@bs.uncurry] (unit => 'any), ('a, 'b, 'c, 'd)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo5:
  ([@bs.uncurry] (unit => 'any), ('a, 'b, 'c, 'd, 'e)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo6:
  ([@bs.uncurry] (unit => 'any), ('a, 'b, 'c, 'd, 'e, 'f)) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo7:
  ([@bs.uncurry] (unit => 'any), ('a, 'b, 'c, 'd, 'e, 'f, 'g)) => 'any =
  "useMemo";

/* This is used as return values  */
type callback('input, 'output) = 'input => 'output;

[@bs.module "react"]
external useCallback:
  ([@bs.uncurry] ('input => 'output)) => callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback0:
  ([@bs.uncurry] ('input => 'output), [@bs.as {json|[]|json}] _) =>
  callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback1:
  ([@bs.uncurry] ('input => 'output), array('a)) => callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback2:
  ([@bs.uncurry] ('input => 'output), ('a, 'b)) => callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback3:
  ([@bs.uncurry] ('input => 'output), ('a, 'b, 'c)) =>
  callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback4:
  ([@bs.uncurry] ('input => 'output), ('a, 'b, 'c, 'd)) =>
  callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback5:
  ([@bs.uncurry] ('input => 'output), ('a, 'b, 'c, 'd, 'e)) =>
  callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback6:
  ([@bs.uncurry] ('input => 'output), ('a, 'b, 'c, 'd, 'e, 'f)) =>
  callback('input, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback7:
  ([@bs.uncurry] ('input => 'output), ('a, 'b, 'c, 'd, 'e, 'f, 'g)) =>
  callback('input, 'output) =
  "useCallback";

[@bs.module "react"]
external useContext: Context.t('any) => 'any = "useContext";

[@bs.module "react"] external useRef: 'value => Ref.t('value) = "useRef";

[@bs.module "react"]
external useImperativeHandle0:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    [@bs.as {json|[]|json}] _
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle1:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    array('a)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle2:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle3:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b, 'c)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle4:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b, 'c, 'd)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle5:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b, 'c, 'd, 'e)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle6:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b, 'c, 'd, 'e, 'f)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.module "react"]
external useImperativeHandle7:
  (
    Js.Nullable.t(Ref.t('value)),
    [@bs.uncurry] (unit => 'value),
    ('a, 'b, 'c, 'd, 'e, 'f, 'g)
  ) =>
  unit =
  "useImperativeHandle";

[@bs.set]
external setDisplayName: (component('props), string) => unit = "displayName";