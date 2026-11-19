const form = document.getElementById("itemForm");
const itemList = document.getElementById("itemList");

form.addEventListener("submit", function (event) {
  event.preventDefault();

  const name = document.getElementById("itemName").value.trim();
  const type = document.getElementById("itemType").value;
  const location = document.getElementById("location").value.trim();

  if (!name || !location) {
    alert("Please fill in all fields.");
    return;
  }

  // Build the item using textContent so user input is displayed safely.
  const card = document.createElement("article");
  card.className = "item";

  const heading = document.createElement("h3");
  heading.textContent = name;

  const typeText = document.createElement("p");
  typeText.textContent = "Type: " + type;

  const locationText = document.createElement("p");
  locationText.textContent = "Location: " + location;

  card.append(heading, typeText, locationText);

  const emptyMessage = itemList.querySelector(".empty");
  if (emptyMessage) emptyMessage.remove();

  itemList.appendChild(card);
  form.reset();
});
