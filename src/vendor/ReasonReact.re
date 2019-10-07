type reactClass;

type jsProps;

type reactElement('a) = React.element('a);

type reactRef;

external refToJsObj: reactRef => Js.t({..}) = "%identity";

