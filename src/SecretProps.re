type person = {
  .
  "firstName": string,
  "lastName": string,
};
let makeProps = (~firstName, ~lastName, ()): person => {
  "firstName": firstName,
  "lastName": lastName,
};

let make = props => {
  <div> {React.string(props##firstName)} </div>;
};

