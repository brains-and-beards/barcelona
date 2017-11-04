open ReactNative;

type category =
  | Eat
  | See
  | Stay;

type filter =
  | Category category
  | All;

module Style = {
  open ReactNative.Style;
  let container =
    style [
      justifyContent `center,
      paddingHorizontal 10.,
      paddingBottom 7.,
      paddingTop 10.,
      borderBottomColor Colors.white,
      borderBottomWidth 4.
    ];
  let content = style [fontSize 20., textAlign `center];
  let active = style [borderBottomColor Colors.brainsYellow];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make filter::(filter: filter) ::currentFilter ::onChange _children => {
  ...component,
  render: fun _self => {
    let active = filter == currentFilter;
    let name =
      switch filter {
      | All => "all"
      | Category See => "see"
      | Category Eat => "eat"
      | Category Stay => "stay"
      };
    let style =
      active ? ReactNative.Style.flatten [|Style.container, Style.active|] : Style.container;
    <TouchableOpacity style onPress=(fun _event => onChange filter)>
      <CustomText style=Style.content> (String.uppercase name) </CustomText>
    </TouchableOpacity>
  }
};
