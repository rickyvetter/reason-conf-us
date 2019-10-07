let joinClasses = (a, b) => a ++ " " ++ b;

module Button = {
  type size =
    | Default
    | Large
    | Small;
  type color =
    | Normal
    | Primary
    | Negative;
  [@react.component]
  let make = (~size, ~color) => {
    <button
      className={joinClasses(
        switch (size) {
        | Large => "large"
        | Default => "default"
        | Small => "small"
        },
        switch (color) {
        | Normal => "normal"
        | Primary => "primary"
        | Negative => "negative"
        },
      )}
    />;
  };
};

module RedButton = {
  let make = Button.make;
  let makeProps = Button.makeProps(~color=Button.Primary);
};

let foo = <RedButton size=Button.Default />;

let bar = <Button size=Button.Default color=Button.Normal />;