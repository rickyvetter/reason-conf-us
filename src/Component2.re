/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

[@react.component]
let make = (~greeting) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Click => {...state, count: state.count + 1}
        | Toggle => {...state, show: !state.show}
        },
      {count: 0, show: true},
    );

  let message =
    "You've clicked this " ++ string_of_int(state.count) ++ " times(s)";
  <div>
    <button onClick={_event => dispatch(Click)}>
      {React.string(message)}
    </button>
    {React.array([|<div key="foo"> {React.string("one")} </div>|])}
    <button onClick={_event => dispatch(Toggle)}>
      {React.string("Toggle greeting")}
    </button>
    {state.show ? React.string(greeting) : React.null}
  </div>;
};