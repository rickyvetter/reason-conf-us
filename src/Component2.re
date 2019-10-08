/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

type person = {
  id: string,
  firstName: string
};

let friends: array(person) = Obj.magic();

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
  <React.DOM.div>
    <button onClick={_event => dispatch(Click)}>
      {React.string(message)}
    </button>
    <div>
      {
        React.array(
          Belt.Array.map(friends, friend =>
            <div key=friend.id> {React.string(friend.firstName)} </div>
          ),
        )
      }
    </div>
    <button onClick={_event => dispatch(Toggle)}>
      {React.string("Toggle greeting")}
    </button>
    {state.show ? React.string(greeting) : React.null}
  </React.DOM.div>;
};
