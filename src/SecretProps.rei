type person;

let makeProps: (~firstName: string, ~lastName: string, unit) => person;

let make: (person) => React.element(React.unkeyed);