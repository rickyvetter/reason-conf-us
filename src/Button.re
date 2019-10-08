


type size =
  | Default
  | Large
  | Small;
[@react.component]
let make =
    (
      ~size,
      ~onClick: ReactEvent.Mouse.t => unit,
      ~children: React.element(React.keyed),
    ) => {
  <button
    style={ReactDOMRe.Style.make(
      ~height=
        switch (size) {
        | Large => "30px"
        | Default => "20px"
        | Small => "10px"
        },
      (),
    )}
    onClick>
    children
  </button>;
};

module Large = {
  let make = make;
  let makeProps = makeProps(~size=Large);
};
